#include "stdafx.h"
#include "Save.h"
#include <fstream>
#include <iostream>
#include <windows.h>
#include "Map.h"
#include "Snake.h"
Save::Save(){}
Save::~Save(){}
using namespace  std;

void Save::SaveData(Snake &obj_snake, Map &obj_map)
{
	int len = obj_snake.snake_arr.size();
	fstream fOut("data.dat", ios::out|ios::binary);
	fOut.write((char*)&obj_snake.snake_Direction, sizeof(obj_snake.snake_Direction));
	fOut.write((char *)&obj_snake.snake_buffer, sizeof(obj_snake.snake_buffer));
	fOut.write((char *)&obj_snake.snake_level, sizeof(obj_snake.snake_level));
	fOut.write((char *)&len, sizeof(len));
	fOut.write((char*)&obj_map.Map_arr, sizeof(obj_map.Map_arr));
	for (SNAKENODE &each : obj_snake.snake_arr)
	{
		fOut.write((char*)&each, sizeof(each));
	}

	

	fOut.close();
	MessageBox(NULL, L"±£´æ³É¹¦", L"haha", MB_OK);
}

void Save::ReadData(Snake &obj_snake,Map &obj_map)
{
	int lens;
	fstream fIn(("data.dat"), ios::in|ios::binary);
	fIn.read((char *)&obj_snake.snake_Direction, sizeof(obj_snake.snake_Direction));
	fIn.read((char *)&obj_snake.snake_buffer, sizeof(obj_snake.snake_buffer));
	fIn.read((char *)&obj_snake.snake_level, sizeof(obj_snake.snake_level));
	fIn.read((char *)&lens, sizeof(lens));
	fIn.read((char*)&obj_map.Map_arr, sizeof(obj_map.Map_arr));
	obj_snake.snake_arr.resize(lens);

	for (SNAKENODE &each : obj_snake.snake_arr)
	{
		fIn.read((char *)&each, sizeof(each));
	}
	fclose;
}

