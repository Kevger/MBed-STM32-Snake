#include "OutputNucleo.h"
#include "config.h"


using namespace game;

void OutputNucleo::send(uint16_t data)
{
    outputEnable = 0;
    for(int i = 0; i < 16; ++i) {
        clockLine = 0;
        dataLine = data & 1;
        clockLine = 1;
        data>>=1;
    }
    outputEnable = 1;
}

//output field to LED Matrix
void OutputNucleo::refresh()
{
    for(int y = 0; y < MAPSIZE; ++y) {
        uint8_t rowData = 0;
        for(int x = 0; x < MAPSIZE; ++x) {
            rowData<<=1;
            if(map.mapData[y][x] == ENTITY_NONE)
                rowData +=1;
        }
        //Low-byte represents row number and high-byte the row data
        send((rowData << 8)|(1<<y));
        wait_us(DELAY_ROW_REFRESH_US); //tuning of brightness/flickering
    }
}


OutputNucleo::OutputNucleo(const Map& map)
    :Output(map), dataLine(DATA_LINE_PIN)
    , clockLine(CLOCK_LINE_PIN)
    , outputEnable(OUTPUT_ENABLE_PIN)
{
    send(0);
}

