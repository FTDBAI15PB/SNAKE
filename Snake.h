#pragma once
#include <vector>
#include "Apple.h"
#include "Map.h"
using std::vector;
typedef struct _SNAKENODE
{
	int nX;
	int nY;
}SNAKENODE, *PSNAKENODE;

enum SNAKEDIR
{
	UP, DOWN, LEFT, RIGHT, MYERROR
};

class Snake
{
public:
	static int snake_time;
	static int snake_level;
	static int snake_buffer;
	SNAKEDIR snake_Direction;
	vector<SNAKENODE> snake_arr;
public:
	void SnakeMove();
	void SnakeDraw();
	bool SnakeLife();
	void SnakeDelete();
	void SnakeDirection();
	void SnakeInit(int x, int y, SNAKEDIR nDir);
	void SnakeOpinion(Apple &obj_apple, Map &onj_map);

public:
	Snake();
	~Snake();
};

