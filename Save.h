#pragma once
#include "Snake.h"
#include "Map.h"
class Save
{
public:
	void ReadData(Snake &obj_snake,Map &obj_map);
	void SaveData(Snake &obj_snake, Map &obj_map);
public:
	Save();
	~Save();
};

