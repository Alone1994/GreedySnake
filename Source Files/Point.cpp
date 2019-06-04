#include "pch.h"
#include "Point.h"

#include <iostream>

Point::~Point()
{
}

void Point::PointPrint()
{
	Tools::Instance()->SetCurSorPositon(_X, _Y);
	std::cout << "��";
}

void Point::PointClear()
{
	Tools::Instance()->SetCurSorPositon(_X, _Y);
	std::cout << " ";	//����հ�
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

void Point::PrintCircle()
{
	Tools::Instance()->SetCurSorPositon(_X, _Y);
	std::cout << "��";
}
