#include "pch.h"
#include "Point.h"


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
}
