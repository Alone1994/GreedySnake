#include "pch.h"
#include "StartInterface.h"

#define STOPTIME 100

StartInterface::StartInterface():
	_Speed(25)
{
	//�����ƶ��㼣����
	_StartSnake.emplace_back(Point(0, 14));
	_StartSnake.emplace_back(Point(1, 14));
	_StartSnake.emplace_back(Point(2, 15));
	_StartSnake.emplace_back(Point(3, 16));
	_StartSnake.emplace_back(Point(4, 17));
	_StartSnake.emplace_back(Point(5, 18));
	_StartSnake.emplace_back(Point(6, 17));
	_StartSnake.emplace_back(Point(7, 16));
	_StartSnake.emplace_back(Point(8, 15));
	_StartSnake.emplace_back(Point(9, 14));

	//���� SNAKE
	_TextSnake.emplace_back(Point(-26, 14));//S
	_TextSnake.emplace_back(Point(-25, 14));
	_TextSnake.emplace_back(Point(-27, 15));
	_TextSnake.emplace_back(Point(-26, 16));
	_TextSnake.emplace_back(Point(-25, 17));
	_TextSnake.emplace_back(Point(-27, 18));
	_TextSnake.emplace_back(Point(-26, 18));

	_TextSnake.emplace_back(Point(-23, 14));//N
	_TextSnake.emplace_back(Point(-23, 15));
	_TextSnake.emplace_back(Point(-23, 16));
	_TextSnake.emplace_back(Point(-23, 17));
	_TextSnake.emplace_back(Point(-23, 18));
	_TextSnake.emplace_back(Point(-22, 15));
	_TextSnake.emplace_back(Point(-21, 16));
	_TextSnake.emplace_back(Point(-20, 17));
	_TextSnake.emplace_back(Point(-19, 14));
	_TextSnake.emplace_back(Point(-19, 15));
	_TextSnake.emplace_back(Point(-19, 16));
	_TextSnake.emplace_back(Point(-19, 17));
	_TextSnake.emplace_back(Point(-19, 18));

	_TextSnake.emplace_back(Point(-17, 18));//A
	_TextSnake.emplace_back(Point(-16, 17));
	_TextSnake.emplace_back(Point(-15, 16));
	_TextSnake.emplace_back(Point(-14, 15));
	_TextSnake.emplace_back(Point(-14, 16));
	_TextSnake.emplace_back(Point(-13, 14));
	_TextSnake.emplace_back(Point(-13, 16));
	_TextSnake.emplace_back(Point(-12, 15));
	_TextSnake.emplace_back(Point(-12, 16));
	_TextSnake.emplace_back(Point(-11, 16));
	_TextSnake.emplace_back(Point(-10, 17));
	_TextSnake.emplace_back(Point(-9, 18));

	_TextSnake.emplace_back(Point(-7, 14));//K
	_TextSnake.emplace_back(Point(-7, 15));
	_TextSnake.emplace_back(Point(-7, 16));
	_TextSnake.emplace_back(Point(-7, 17));
	_TextSnake.emplace_back(Point(-7, 18));
	_TextSnake.emplace_back(Point(-6, 16));
	_TextSnake.emplace_back(Point(-5, 15));
	_TextSnake.emplace_back(Point(-5, 17));
	_TextSnake.emplace_back(Point(-4, 14));
	_TextSnake.emplace_back(Point(-4, 18));

	_TextSnake.emplace_back(Point(-2, 14));//E
	_TextSnake.emplace_back(Point(-2, 15));
	_TextSnake.emplace_back(Point(-2, 16));
	_TextSnake.emplace_back(Point(-2, 17));
	_TextSnake.emplace_back(Point(-2, 18));
	_TextSnake.emplace_back(Point(-1, 14));
	_TextSnake.emplace_back(Point(-1, 16));
	_TextSnake.emplace_back(Point(-1, 18));
	_TextSnake.emplace_back(Point(0, 14));
	_TextSnake.emplace_back(Point(0, 16));
	_TextSnake.emplace_back(Point(0, 18));
}


StartInterface::~StartInterface()
{
}

void StartInterface::PrintSnakeDeque()
{
	for (auto & point : _StartSnake)
	{
		point.PointPrint();
		Sleep(STOPTIME);
	}
}

void StartInterface::PrintSnakeFromLeftToRight()
{
	//��ͷ��Ҫ��10�ƶ���40
	for (int i = 10; i < 40; i++)
	{
		//ÿһ�ε�������ǽ�ͷȥ����β����һ����
		int j = (((i - 2) % 8) < 4) ? (15 + (i - 2) % 8) : (21 - (i - 2) % 8);	
		_StartSnake.emplace_back(Point(i, j));
		_StartSnake.back().PointPrint();
		_StartSnake.front().PointClear();
		_StartSnake.pop_front();	//ȥ��������ǰ�˵ĵ�
		Sleep(STOPTIME);
	}
}

void StartInterface::PrintSnakeDispear()
{
	while (!_StartSnake.empty() || _TextSnake.back().GetPointX() < 33) //�����λ�û��ʧ������û�ƶ���ָ��λ��
	{
		if(!_StartSnake.empty())
		{
			_StartSnake.front().PointClear();
			_StartSnake.pop_front();
		}

		ClearTextSnake();

		UpdateTextSnake();

		Sleep(STOPTIME);
	}
		
}

void StartInterface::ClearTextSnake()
{
	for (auto& point : _TextSnake)
	{
		if (point.GetPointX() >= 0)
		{
			point.PointClear();
		}
		point.UpdatePos(point.GetPointX() + 1, point.GetPointY());	//����ƽ��һ��
	}
}

void StartInterface::UpdateTextSnake()
{
	for (auto& point : _TextSnake)
	{
		if (point.GetPointX() >= 0)
		{
			point.PointPrint();	//���
		}
	}
}

void StartInterface::AnimationAction()
{
	PrintSnakeDeque();
	PrintSnakeFromLeftToRight();
	PrintSnakeDispear();
}
