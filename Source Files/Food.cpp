#include "pch.h"
#include "Food.h"

#include <iostream>

Food::Food() 
	:_Cnt(0)
	,_FlashFlag(false)
	,_BigFlag(false)
	,_X(0)
	,_Y(0)
	,_BigX(0)
	,_BigY(0)
	,_ProgressBar(0)
{
	
}

Food::~Food()
{
}

void Food::DrawFood(Snake& snake)
{
	//利用rand函数获得坐标，并将其范围限制在2-29，即在地图内，如果获得的坐标与蛇身重叠，则重新获取。同时每5颗食物就出现一颗限时食物
	while (true)
	{
		int temp_x = rand() % 30;
		int temp_y = rand() % 30;
		if (temp_x < 2)
		{
			temp_x += 2;
		}
		if (temp_y < 2)
		{
			temp_y += 2;
		}

		bool flag = false;
		for (auto& point : snake._Snake)
		{
			if ((point.GetPointX() == temp_x && point.GetPointY() == temp_y) || (temp_x == _BigX && temp_y == _BigY)) 
			{
				flag = true;
				break;
			}
		}

		if (flag)
		{
			continue;
		}

		_X = temp_x;
		_Y = temp_y;
		Tools::Instance()->SetCurSorPositon(_X, _Y);
		Tools::Instance()->SetColor(13);
		std::cout << "★";
		++_Cnt;
		_Cnt %= 5;
		if (_Cnt == 0)
		{
			DrawLimitFood(snake);
		}
		break;
	}
}

void Food::DrawLimitFood(Snake& snake)
{
	Tools::Instance()->SetCurSorPositon(5, 0);
	Tools::Instance()->SetColor(11);
	std::cout << "------------------------------------------";//进度条
	_ProgressBar = 42;

	while (true)
	{
		int temp_x = rand() % 30;
		int temp_y = rand() % 30;
		if (temp_x < 2) temp_x += 2;
		if (temp_y < 2) temp_y += 2;
		bool flag = false;
		for (auto& point : snake._Snake)
		{
			if ((point.GetPointX() == temp_x && point.GetPointY() == temp_y) || (temp_x == _X && temp_y == _Y))
			{
				flag = true;
				break;
			}
		}
		if (flag)
		{
			continue;
		}

		_BigX = temp_x;
		_BigY = temp_y;
		Tools::Instance()->SetCurSorPositon(_BigX, _BigY);
		Tools::Instance()->SetColor(18);
		std::cout << "■";
		_BigFlag = true;
		_FlashFlag = true;
		break;
	}
}

bool Food::GetBigFlag()
{
	return _BigFlag;
}

void Food::FlashBigFood()
{
	Tools::Instance()->SetCurSorPositon(_BigX, _BigY);
	Tools::Instance()->SetColor(18);
	if (_FlashFlag)
	{
		std::cout << "  ";
		_FlashFlag = false;
	}
	else
	{
		std::cout << "■";
		_FlashFlag = true;
	}


	Tools::Instance()->SetCurSorPositon(26, 0);
	Tools::Instance()->SetColor(11);

	for (int i = 42; i >= _ProgressBar; --i)
	{
		std::cout << "\b \b";
	}

	--_ProgressBar;
	if (_ProgressBar == 0)
	{
		Tools::Instance()->SetCurSorPositon(_BigX, _BigY);
		std::cout << "  ";
		_BigFlag = false;
		_BigX = 0;
		_BigY = 0;
	}
}

int Food::GetCnt()
{
	return _Cnt;
}

int Food::GetProgressBar()
{
	return _ProgressBar;
}
