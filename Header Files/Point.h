#pragma once
#ifndef Point_h__
#define Point_h__

#include "Tools.h"

//���Ƶ㼣��
class Point
{
public:
	Point();
	Point(const int x, const int y);
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

private:
	int _X;	//�㼣��X��Y����
	int _Y;	
};


#endif // Point_h__

