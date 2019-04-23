#include "pch.h"
#include "Point.h"

#include <iostream>

Point::Point()
{
}

Point::Point(const int x, const int y)
	:_X(x)
	,_Y(y)
{

}	

Point::~Point()
{
}

void Point::PointPrint()
{
	Tools::Instance()->SetCurSorPositon(_X, _Y);
	std::cout << "¡ö";
}

void Point::PointClear()
{
	Tools::Instance()->SetCurSorPositon(_X, _Y);
	std::cout << " ";	//Êä³ö¿Õ°×
}

int Point::GetPointX()
{
	return _X;
}

int Point::GetPointY()
{
	return _Y;
}

void Point::UpdatePos(int x, int y)
{
	_X = x;
	_Y = y;
}
