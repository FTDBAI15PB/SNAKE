#include "stdafx.h"
#include "Snake.h"
#include "Draw.h"
#include "Map.h"
#include "Apple.h"
#include <conio.h>
Snake::Snake(){}
Snake::~Snake(){}

void Snake::SnakeInit(int x, int y, SNAKEDIR nDir)
{
	SNAKENODE sn = { x, y };
	snake_Direction = nDir;
	snake_arr.push_back(sn);
	Draw obj;
	obj.DrawXY(x, y, "¡ö", 0x06);
}

void Snake::SnakeDraw()
{
	SnakeDelete();
	int snake_len = snake_arr.size();
	for (int i = snake_len - 2; i >= 0; --i)
	{
		snake_arr[i + 1] = snake_arr[i];
	}
	switch (snake_Direction)
	{
	case UP:
		snake_arr[0].nY--;
		break;
	case DOWN:
		snake_arr[0].nY++;
		break;
	case LEFT:
		snake_arr[0].nX--;
		break;
	case RIGHT:
		snake_arr[0].nX++;
		break;
	}
	Draw obj;
	for (int i = 0; i < snake_len; ++i)
	{
		obj.DrawXY(snake_arr[i].nX, snake_arr[i].nY, "¡ö", 0x06);
	}
}

void Snake::SnakeDelete()
{
	Draw obj_draw;
	int nCount = snake_arr.size();
	for (int i = 0; i < nCount; i++)
	{
		obj_draw.DrawXY(snake_arr[i].nX, snake_arr[i].nY, " ", 0x00);
	}
}

void Snake::SnakeOpinion(Apple &obj_apple, Map &onj_map)
{
	Map obj_map;
	SNAKENODE snake_Head = snake_arr[0];
	switch (snake_Direction)
	{
	case UP:
		snake_Head.nY--;
		break;
	case DOWN:
		snake_Head.nY++;
		break;
	case LEFT:
		snake_Head.nX--;
		break;
	case RIGHT:
		snake_Head.nX++;
		break;
	}
	if (obj_map.Map_arr[snake_Head.nY][snake_Head.nX] == WALL_BOUND)
	{
		snake_buffer = 0;
	}
	if (obj_map.Map_arr[snake_Head.nY][snake_Head.nX] == WALL_GRASS)
	{
		Draw().DrawXY(snake_arr[0].nX, snake_arr[0].nY, "¡õ", 0x06);
		obj_map.Map_arr[snake_Head.nY][snake_Head.nX] = 0;
		_getch();
		if (snake_arr.size() > 1)
		{
			snake_arr.pop_back();
		}
		else
		{
			MessageBox(NULL, L"Game Over", L"haha", MB_OK);
			exit(1);

		}

	}
	if (obj_map.Map_arr[snake_Head.nY][snake_Head.nX] == WALL_BARRIER)
	{
		Draw().DrawHit();
		_getch();
		Draw().DrawBlank();
		snake_buffer--;
		obj_map.MapRandBarrier();
		obj_map.MapDraw();
		obj_apple.AppleXYRand();
	}
	if (obj_map.Map_arr[snake_Head.nY][snake_Head.nX] == WALL_APPLE)
	{
		snake_level++;
		SNAKENODE snake_eat = { snake_Head.nX, snake_Head.nY };
		snake_arr.insert(snake_arr.end(), snake_eat);
		obj_map.Map_arr[snake_Head.nY][snake_Head.nX] = 0;
		obj_apple.AppleXYRand();
	}
}



