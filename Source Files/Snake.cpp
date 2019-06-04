#include "pch.h"
#include "Snake.h"

#include <conio.h>
#include <iostream>

Snake::Snake()
{
	_Snake.emplace_back(14, 8);
	_Snake.emplace_back(15, 8);
	_Snake.emplace_back(16, 8);
	_Direction = Direction::DOWN;
}


Snake::~Snake()
{
}

void Snake::InitSnake()
{
	for (auto& point : _Snake)
	{
		point.PrintCircle();
	}
}

void Snake::InitMove()
{
	Move();
	_Snake.front().PointClear();
	_Snake.pop_front();
}

void Snake::Move()
{
	switch (_Direction)
	{
	case Snake::UP:
		_Snake.emplace_back(_Snake.back().GetPointX(), _Snake.back().GetPointY() - 1);
		break;
	case Snake::DOWN:
		_Snake.emplace_back(_Snake.back().GetPointX(), _Snake.back().GetPointY() + 1);
		break;
	case Snake::LEFT:
		_Snake.emplace_back(_Snake.back().GetPointX() - 1, _Snake.back().GetPointY());
		break;
	case Snake::RIGHT:
		_Snake.emplace_back(_Snake.back().GetPointX() + 1, _Snake.back().GetPointY());
		break;
	default:
		break;
	}

	Tools::Instance()->SetColor(14);
	_Snake.back().PrintCircle();
}

bool Snake::OverEdge()
{
	bool res = _Snake.back().GetPointX() < 30 && _Snake.back().GetPointY() < 30 && _Snake.back().GetPointX() > 1 && _Snake.back().GetPointY() > 1;
	return res;
}

bool Snake::HitSelf()
{
	std::deque<Point>::size_type cnt = 1;
	Point *head = new Point(_Snake.back().GetPointX(), _Snake.back().GetPointY());    //ͷ������

	//���������������ͷ����ͬ�����겻�����߳������ʾ��ͷײ���Լ�
	for (auto& point : _Snake)
	{
		if (point == *head)
		{
			cnt++;
		}
		else
		{
			break;
		}
	}
	delete head;

	if(cnt == _Snake.size())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Snake::ChangeDirection()
{
	char ch;
	if (_kbhit())    //����������Ӧ�����¼�,��鵱ǰ�Ƿ��м�������,�����򷵻�һ����0ֵ,���򷵻�0
	{
		ch = _getch();
		switch (ch)
		{
		case -32:
			ch = _getch();
			switch (ch)
			{
			case 72:
				if (_Direction != Direction::DOWN)//��������뵱ǰ�˶������෴����Ч
					_Direction = Direction::UP;
				break;
			case 80:
				if (_Direction != Direction::UP)
					_Direction = Direction::DOWN;
				break;
			case 75:
				if (_Direction != Direction::RIGHT)
					_Direction = Direction::LEFT;
				break;
			case 77:
				if (_Direction != Direction::LEFT)
					_Direction = Direction::RIGHT;
				break;
			default:
				break;
			}
			return true;

		case 27://ESC
			return false;

		default:
			return true;
		}
	}

	return true;
}

bool Snake::GetFood(const Food& food)
{
	if (_Snake.back().GetPointX() == food._X && _Snake.back().GetPointY() == food._Y) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}