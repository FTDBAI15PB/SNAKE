// snake.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <fstream>

#include "Save.h"
#include "Map.h"
#include "Draw.h"
#include "Apple.h"
#include "Snake.h"
#define MAPROW 40
#define MAPCOL 40


#pragma comment(lib,"winmm.lib")
int Map::Map_arr[MAPROW][MAPCOL] = {};
int Snake::snake_buffer = 5;
int Snake::snake_level = 0;
int Snake::snake_time = 0;
int _tmain(int argc, _TCHAR* argv[])
{
	
	PlaySoundA("sound\\��ʿ֮��.wav", NULL, SND_ASYNC | SND_NODEFAULT | SND_LOOP);
	srand((unsigned)time(NULL));
	Draw obj_draw;
	Map obj_map;
	Snake obj_snake;
	Apple obj_apple;
	obj_draw.DrawWindows("SnakeInfo", 100, 41);
	//��ʼ���棬�˵�ѡ��
	obj_draw.DrawStartWin();
	
	int MenuX = 18;
	int MenuY = 26;
	keybd_event(VK_SHIFT, 0, 0, 0);
	Sleep(100);
	keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
	while (true)
	{
		char choice = _getch();
		obj_draw.DrawXY(MenuX, MenuY, "  ", 0xff);
		switch (choice)
		{
		case 'w':
			if (MenuY == 26)
			{
				break;
			}
			MenuY = MenuY - 2;
			break;
		case 's':
			if (MenuY == 30)
			{
				break;
			}
			MenuY = MenuY + 2;
			break;
		case '\r':
			if (MenuY == 26)
			{
				goto Start;
				printf("��ʼ��Ϸ");
				//��ͼ���ɣ��߳�ʼ��
			}
			if (MenuY == 28)
			{

				//���ļ����鿴�Ƿ�浵
				FILE *fp;
				errno_t err = fopen_s(&fp, "data.dat", "r");
				if (err != 0)
				{
					obj_draw.DrawXY(26, 28, "û�д浵", rand() % 0xff);
				}
				else
				{
					obj_draw.DrawXY(26, 28, "�д浵", rand() % 0xff);
					Save().ReadData(obj_snake, obj_map);
					system("CLS");
					obj_map.MapInit();
					obj_apple.AppleXYRand();
					goto again;
				}

			}
			if (MenuY == 30)
			{
				exit(1);
			}
		default:
			break;
		}
		obj_draw.DrawXY(MenuX, MenuY, ">>", 0x0A);
	}
Start:
	system("CLS");
	printf("��ʼ��Ϸ");
	if (MessageBox(NULL, L"�Ƿ��Զ����ͼ", L"O_O", MB_OKCANCEL) == IDOK)
	{
		//�Ƿ��Զ����ͼ
		//�ǣ��Զ����ͼ��֮���ڿ�ʼ��Ϸ
		Map obj_map;
		obj_map.MapInit();
		_getch();
		HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
		INPUT_RECORD stcRecord = {};
		DWORD dwRead = 0;
		SetConsoleMode(hInput, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
		while (true)
		{
			ReadConsoleInput(hInput, &stcRecord, 1, &dwRead);
			//����¼�
			if (stcRecord.EventType == MOUSE_EVENT)
			{
				if (obj_draw.DrawRandMap(stcRecord.Event.MouseEvent, obj_map))
				{
					break;
				}
			}
		}
	}
	//��,ֱ�ӿ�ʼ��Ϸ
	//��ʼ����ͼ���ߡ�ʳ���ʼʱ�䡢���ְ�
	//��Ϸ���棬
	//��ʼ��Map
	
	obj_map.MapBarrier();
	obj_map.MapInit();
	//��ʼ��Apple
	obj_apple.AppleXYRand();
	//��ʼ��snake
	
	obj_snake.SnakeInit(20, 20, UP);
again:
	clock_t tBegin = clock(), tEnd;
	while (1)
	{
		obj_draw.DrawBord(obj_snake);
		//�ж����Ƿ�����ƶ�
		if (obj_snake.snake_buffer == 0)
		{
			MessageBox(NULL, L"GAME OVER", L"AHA", MB_OK);
			exit(1);
		}

		if (_kbhit())
		{
			switch (_getch())
			{
			case 'w':
				obj_snake.snake_Direction = UP;
				break;
			case 'a':
				obj_snake.snake_Direction = LEFT;
				break;
			case 's':
				obj_snake.snake_Direction = DOWN;
				break;
			case 'd':
				obj_snake.snake_Direction = RIGHT;
				break;
			case ' '://��ͣ
				_getch();
				break;
			case 'q':
				Save().SaveData(obj_snake, obj_map);
				break;//��������
			case '\r':
				Save().SaveData(obj_snake, obj_map);
				exit(1);//��;�˳����Զ�����
			default:
				break;
			}
			obj_snake.SnakeOpinion(obj_apple, obj_map);
			obj_snake.SnakeDraw();

		}
		tEnd = clock();
		obj_snake.snake_time = tEnd;
		if (tEnd - tBegin > abs(300 - obj_snake.snake_buffer * 10))
		{
			tBegin = tEnd;
			obj_snake.SnakeOpinion(obj_apple, obj_map);
			obj_snake.SnakeDraw();
		}
	}

	return 0;
}

