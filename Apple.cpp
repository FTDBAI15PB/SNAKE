#include "stdafx.h"
#include "Apple.h"
#include <stdlib.h>
#include "Map.h"
#include "Draw.h"
Apple::Apple(){}
Apple::~Apple(){}

void Apple::AppleXYRand()
{
	apple[0] = rand() % MAPROW;
	apple[1] = rand() % MAPCOL;
	if (Map::Map_arr[apple[0]][apple[1]] != 0)
	{
		AppleXYRand();
	}
	Map::Map_arr[apple[0]][apple[1]] = WALL_APPLE;
	Draw().DrawXY(apple[1], apple[0], "¡ñ", 0x04);
}
