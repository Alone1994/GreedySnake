#include "pch.h"
#include "Tools.h"

#include <windows.h>
#include <stdio.h>

Tools* Tools::Instance()
{
	static Tools instance;
	return &instance;
}

Tools::Tools()
{
}

Tools::~Tools()
{
}

void Tools::SetCurSorPositon(const int x, const int y)
{
	COORD pos;
	pos.X = x * 2;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);	//设置光标位置
}

void Tools::SetWindowSize(int cols, int lines)
{
	system("title 贪吃蛇");	//todo
	char cmd[30];
	sprintf_s(cmd, "mode con cols=%d lines=%d", cols * 2, lines);//一个图形■占两个字符，故宽度乘以2
	system(cmd);//system(mode con cols=88 lines=88)设置窗口宽度和高度
}

void Tools::SetColor(int colorID)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}

void Tools::SetCurBackgroundColor()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
}
