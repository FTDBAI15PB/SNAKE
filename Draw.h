#pragma once
#include "Snake.h"
#include <windows.h>
#define MAPROW 40
#define MAPCOL 40
#define WALL_BOUND 0x99
#define WALL_SNAKE 0x01
#define WALL_FOOD  0x02
class Draw
{


public:
	void DrawHit();
	void DrawBlank();
	void DrawStartWin();
	void DrawBord(Snake &obj_snake);
	void DrawXY(int x, int y, char *type, char color);
	void DrawWindows(char* pTitle, int nWid, int nHeight);
	bool DrawRandMap(MOUSE_EVENT_RECORD &mer, Map &obj_map);
public:
	Draw();
	~Draw();
};


