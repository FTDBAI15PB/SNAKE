#pragma once
#define MAPROW 40
#define MAPCOL 40
#define WALL_BOUND 0x99
#define WALL_BARRIER 0x98
#define WALL_GRASS	0x97
#define WALL_APPLE 0x96
#define WALL_SNAKE 0x01
class Map
{
public:
	static int Map_arr[MAPROW][MAPCOL];
public:
	void MapInit();
	void MapDraw();
	void MapBarrier();
	void MapRandBarrier();
public:
	Map();
	~Map();
};

