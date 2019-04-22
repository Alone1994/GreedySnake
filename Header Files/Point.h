#pragma once
#ifndef Point_h__
#define Point_h__

#include "Tools.h"

//绘制点迹类
class Point
{
public:
	Point();
	Point(const int x, const int y);
	virtual ~Point();

public:
	//输出点迹
	void PointPrint();

private:
	int _X;	//点迹的X、Y坐标
	int _Y;	
};


#endif // Point_h__

