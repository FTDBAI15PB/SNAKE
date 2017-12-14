#include "stdafx.h"
#include "Map.h"
#include "Draw.h"
#include <windows.h>
Map::Map(){}
Map::~Map(){}

void Map::MapInit()
{
	for (int i = 0; i < MAPROW; i++)
	{
		for (int j = 0; j < MAPCOL; j++)
		{
			if (i == 0 || i == MAPROW - 1 ||
				j == 0 || j == MAPCOL - 1)
			{
				Map_arr[i][j] = WALL_BOUND;
			}
		}
	}
	MapDraw();
}

void Map::MapDraw()
{
	Draw obj_draw;
	for (int i = 0; i < MAPROW; i++)
	{
		for (int j = 0; j < MAPCOL; j++)
		{
			if (Map_arr[i][j] == WALL_BOUND)
			{
				obj_draw.DrawXY(j, i, "¡ö", 0x79);
			}
			else if (Map_arr[i][j] == WALL_BARRIER)
			{
				obj_draw.DrawXY(j, i, "¡õ", 0x79);
			}
			else if (Map_arr[i][j] == WALL_GRASS)
			{
				obj_draw.DrawXY(j, i, "¡ù", 0x0A);
			}
			else
			{
				obj_draw.DrawXY(j, i, "  ", 0x00);
			}
		}
	}
}

void Map::MapBarrier()
{

	int nX;
	int nY;
	int i = 0;
	while (i < 100)
	{
		nX = rand() % MAPCOL;
		nY = rand() % MAPROW;
		if (Map_arr[nX][nY] == 0)
		{
			Map_arr[nX][nY] = WALL_BARRIER;
			i++;
		}
	}
}

void Map::MapRandBarrier()
{

	for (int i = 0; i < MAPROW; i++)
	{
		for (int j = 0; j < MAPCOL; j++)
		{
			if (Map_arr[i][j] == WALL_BARRIER)
			{
				Map_arr[i][j] = 0;
			}
		}
	}
	MapBarrier();
}
