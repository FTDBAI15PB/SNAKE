#include "stdafx.h"
#include "Draw.h"
#include <windows.h>
#include <conio.h>
#include <iostream>
#include "Snake.h"
Draw::Draw(){}
Draw::~Draw(){}
using namespace std;
void Draw::DrawXY(int x, int y, char *type, char color)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	// 隐藏光标位置
	CONSOLE_CURSOR_INFO ci = {};
	ci.bVisible = FALSE;
	ci.dwSize = 1;
	SetConsoleCursorInfo(hOut, &ci);
	// 设置光标位置
	COORD cd = { x * 2, y };
	SetConsoleCursorPosition(hOut, cd);
	// 设置打印字符颜色属性
	SetConsoleTextAttribute(hOut, color);
	SetConsoleCursorInfo(hOut, &ci);
	printf("%s", type);
}
void Draw::DrawWindows(char* pTitle, int nWid, int nHeight)
{

	SetConsoleTitleA(pTitle);
	// 获取窗口最大尺寸
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	// 宽高
	COORD cd = GetLargestConsoleWindowSize(hOut);
	// 首先把缓冲区设置尽可能大
	SetConsoleScreenBufferSize(hOut, cd);
	// 把窗口调整到和参数一样大
	SMALL_RECT sr = { 0, 0, nWid - 1, nHeight - 1 };
	if (!SetConsoleWindowInfo(hOut, 1, &sr))
	{
		MessageBox(NULL, L"窗口尺寸不合适！", NULL, MB_OK);
		return;
	}
	// 如果成功，要把滚动条去掉
	COORD cdNow = { nWid, nHeight };
	SetConsoleScreenBufferSize(hOut, cdNow);
}

void Draw::DrawStartWin()
{


	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	char welcome[24][100] = {
		{ "		                                                                                    " },
		{ "		                                                                                    " },
		{ "		                                                                                    " },
		{ "		                                                                                    " },
		{ "		                                                                                    " },
		{ "		                                                                                    " },
		{ "		                                                                                    " },
		{ "		                                                                                    " },
		{ "		     77777 777                            7 7 77                                    " },
		{ "		    77777777777                           777 77                                    " },
		{ "		   777770  77777 77777 77     77777       77777         777                         " },
		{ "		    77777    777 7777777777  7777777777   77777 7777 7777777777                     " },
		{ "		    7777777      77772 7777 77777  77777 7777777777  77777 77777                    " },
		{ "		     77777777    7777 77774   77  77772  77777777   77777  77777                    " },
		{ "		        772174   7277 77771 77272777727  74777777   772777777787                    " },
		{ "		  7727   75707   7477 75727 7477  7879   787777977   7877  7777                     " },
		{ "		   7887777744    7877 7875  7887  2877   7877 7872   7047  778                      " },
		{ "		    78888807     7891 7177   78872740    7888  777    7088551                       " },
		{ "		      777         77          777         777           777                         " },
		{ "		                                                                                    " },
		{ "		                                                                                    " },
		{ "		                                                                                    " },
		{ "		                                                                                    " },
		{ "		                                                                                    " }
	};
	char(*p)[100] = welcome;
	for (int i = 0; i < 24; i++)
	{
		DrawXY(0, i, *p, 0x0f);
		*p++;
	}
	DrawXY(18, 26, ">>", 0xf);
	DrawXY(18, 28, "  ", 0xf);
	DrawXY(18, 30, "  ", 0xf);
	DrawXY(20, 26, "开始游戏", 0xf);
	DrawXY(20, 28, "继续游戏", 0xf);
	DrawXY(20, 30, "结束游戏", 0xf);
}

void Draw::DrawHit()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO ci = {};
	ci.bVisible = FALSE;
	ci.dwSize = 1;
	SetConsoleCursorInfo(hOut, &ci);
	COORD pos = { 80, 16 };
	SetConsoleCursorPosition(hOut, pos);
	SetConsoleTextAttribute(hOut, 0x0A);
	SetConsoleCursorInfo(hOut, &ci);
	cout << "S你撞墙了！" << endl;
}

void Draw::DrawBlank()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO ci = {};
	ci.bVisible = FALSE;
	ci.dwSize = 1;
	SetConsoleCursorInfo(hOut, &ci);
	COORD pos = { 80, 16 };
	SetConsoleCursorPosition(hOut, pos);
	SetConsoleTextAttribute(hOut, 0x0A);
	SetConsoleCursorInfo(hOut, &ci);
	cout << "           " << endl;
}
void Draw::DrawBord(Snake &obj_snake)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO ci = {};
	ci.bVisible = FALSE;
	ci.dwSize = 1;
	SetConsoleCursorInfo(hOut, &ci);

	COORD pos, pos1, pos2, pos3;

	pos.X = 2 * 40;
	pos.Y = 2;

	SetConsoleCursorPosition(hOut, pos);
	SetConsoleTextAttribute(hOut, 0x0A);
	SetConsoleCursorInfo(hOut, &ci);
	cout << "SNAKE Fuller :" << obj_snake.snake_buffer << endl;
	pos1.X = 2 * 40;
	pos1.Y = 4;

	SetConsoleCursorPosition(hOut, pos1);
	SetConsoleTextAttribute(hOut, 0x0A);
	SetConsoleCursorInfo(hOut, &ci);
	cout << "SNAKE Level :" << obj_snake.snake_level << endl;
	pos2.X = 2 * 40;
	pos2.Y = 6;

	SetConsoleCursorPosition(hOut, pos2);
	SetConsoleTextAttribute(hOut, 0x0A);
	SetConsoleCursorInfo(hOut, &ci);
	cout << "SNAKE BODY :" << obj_snake.snake_arr.size() << endl;

	pos3.X = 2 * 40;
	pos3.Y = 8;

	SetConsoleCursorPosition(hOut, pos3);
	SetConsoleTextAttribute(hOut, 0x0A);
	SetConsoleCursorInfo(hOut, &ci);
	cout << "TIME :" << obj_snake.snake_time / 1000 << endl;
}

bool Draw::DrawRandMap(MOUSE_EVENT_RECORD &mer, Map &obj_map)
{
	if ((mer.dwMousePosition.X / 2 < 39 && mer.dwMousePosition.Y < 39) && (mer.dwMousePosition.X / 2>0 && mer.dwMousePosition.Y > 0))
	{
		switch (mer.dwEventFlags)
		{
		case 0://单击
			if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				obj_map.Map_arr[mer.dwMousePosition.Y][mer.dwMousePosition.X / 2] = WALL_GRASS;
				DrawXY(mer.dwMousePosition.X / 2, mer.dwMousePosition.Y, "※", 0x0a);
				return false;
			}
			if (mer.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
			{
				return true;
			}

		case MOUSE_MOVED:
			if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				obj_map.Map_arr[mer.dwMousePosition.Y][mer.dwMousePosition.X / 2] = WALL_GRASS;
				DrawXY(mer.dwMousePosition.X / 2, mer.dwMousePosition.Y, "※", 0x0a);
			}
			return false;
		default:
			return false;
		}
	}
}


