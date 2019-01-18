#include "Map.h"
#include <string.h>

using namespace game;

void Map::init()
{
	//reset all fields to empty state (0)
	for(int i = 0; i < MAPSIZE;++i)
		memset(mapData[i],0,sizeof(mapData[0]));
}

Map::Map()
{
	init();
}


