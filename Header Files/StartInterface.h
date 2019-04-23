#pragma once
#ifndef StartInterface_h__
#define StartInterface_h__

#include "Point.h"

#include <deque>
#include <vector>
#include <windows.h>

//����������

class StartInterface
{
public:
	StartInterface();
	virtual ~StartInterface();

public:

	//��ʼ����
	void AnimationAction();

private:
	//��ӡ�����������ֵ�����
    void PrintSnakeDeque();

	//��ӡ���δ����ҵ��ƶ�
	void PrintSnakeFromLeftToRight();

	//��ӡ���δ����ƶ�����ʧ
	void PrintSnakeDispear();

	//���SNAKE����
	void ClearTextSnake();

	//����SNAKE���ֵ�λ��
	void UpdateTextSnake();

private:
	std::deque<Point> _StartSnake;	//��ʼ�����е����ε㼣
	std::vector<Point> _TextSnake;	//��ʼ�����е�����
	int _Speed; //�㼣�����ƶ��ٶ�
};


#endif // StartInterface_h__



