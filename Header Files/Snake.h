#pragma once

#include "Point.h"
#include "Food.h"

#include <deque>

class Food;

//核心类：蛇
class Snake
{
public:

	Snake();
	virtual ~Snake();

	//蛇运动的方向
	enum Direction
	{
		UP,    //上
		DOWN,    //下
		LEFT,    //左
		RIGHT    //右
	};

	//蛇的初始化
	void InitSnake();

	//初始移动
	void InitMove();

	//蛇的移动
	void Move();

	//越界
	bool OverEdge();

	//撞到自己
	bool HitSelf();

private:

	std::deque<Point> _Snake;    //蛇形队列

	Direction _Direction;    //蛇的移动方向

	friend class Food;
};

