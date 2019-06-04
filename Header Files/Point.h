#pragma once
#ifndef Point_h__
#define Point_h__

#include "Tools.h"

//绘制点迹类
class Point
{
public:
	Point() {}
	Point(const int x, const int y)
		:_X(x)
		,_Y(y) 
	{}
	virtual ~Point();

public:
	//输出点迹
	void PointPrint();

	//清除点迹
	void PointClear();

	//获取点的X坐标
	int GetPointX();

	//获取点的Y坐标
	int GetPointY();

	//更新X、Y坐标
	void UpdatePos(int x, int y);

	//输出圆点(蛇)
	void PrintCircle();

	bool operator == (const Point& point)
	{
		return (point._X == this->_X) && (point._Y == this->_Y);
	}

private:
	int _X;	//点迹的X、Y坐标
	int _Y;	
};


#endif // Point_h__

