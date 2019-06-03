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
	//����rand����������꣬�����䷶Χ������2-29�ڣ����ڵ�ͼ�ڣ������õ������������ص��������»�ȡ��ͬʱÿ5��ʳ��ͳ���һ����ʱʳ��
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
		Tools::Instance()->SetColor(3);
		std::cout << "��";
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
	std::cout << "------------------------------------------";//������
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
		std::cout << "��";
		_BigFlag = true;
		_FlashFlag = true;
		break;
	}
}