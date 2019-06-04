#pragma once
#ifndef Point_h__
#define Point_h__

#include "Tools.h"

//���Ƶ㼣��
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
	//����㼣
	void PointPrint();

	//����㼣
	void PointClear();

	//��ȡ���X����
	int GetPointX();

	//��ȡ���Y����
	int GetPointY();

	//����X��Y����
	void UpdatePos(int x, int y);

	//���Բ��(��)
	void PrintCircle();

	bool operator == (const Point& point)
	{
		return (point._X == this->_X) && (point._Y == this->_Y);
	}

private:
	int _X;	//�㼣��X��Y����
	int _Y;	
};


#endif // Point_h__

