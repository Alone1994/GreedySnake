#pragma once
#ifndef StartInterface_h__
#define StartInterface_h__

#include "Point.h"

#include <deque>
#include <vector>
#include <windows.h>

//开场动画类

class StartInterface
{
public:
	StartInterface();
	virtual ~StartInterface();

private:
	//打印开场动画的蛇形
    void PrintSnakeDeque();

private:
	std::deque<Point> _StartSnake;	//开始动画中的蛇形点迹
	std::vector<Point> _TextSnake;	//开始动画中的文字
	int _Speed; //点迹队列移动速度
};


#endif // StartInterface_h__



