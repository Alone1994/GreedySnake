#include "pch.h"
#include "Snake.h"


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
	Point* head = new Point(_Snake.back().GetPointX(), _Snake.back().GetPointY());    //Í·²¿×ø±ê

	return true;
}
