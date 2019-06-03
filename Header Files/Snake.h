#pragma once

#include "Point.h"
#include "Food.h"

#include <deque>

class Food;

//�����ࣺ��
class Snake
{
public:

	Snake();
	virtual ~Snake();

	//���˶��ķ���
	enum Direction
	{
		UP,    //��
		DOWN,    //��
		LEFT,    //��
		RIGHT    //��
	};

	//�ߵĳ�ʼ��
	void InitSnake();

	//��ʼ�ƶ�
	void InitMove();

	//�ߵ��ƶ�
	void Move();

	//Խ��
	bool OverEdge();

	//ײ���Լ�
	bool HitSelf();

private:

	std::deque<Point> _Snake;    //���ζ���

	Direction _Direction;    //�ߵ��ƶ�����

	friend class Food;
};

