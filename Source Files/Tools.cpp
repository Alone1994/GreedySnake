#include "pch.h"
#include "Tools.h"

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
