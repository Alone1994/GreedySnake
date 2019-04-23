#pragma once
#ifndef GameController_h__
#define GameController_h__

#include "StartInterface.h"
#include "Tools.h"

using namespace std;

//��Ϸ������
class GameController
{
public:
	GameController();
	virtual ~GameController();

public:
	//������Ϸѭ����ʼ
	void GameLoop();
	
	//��������ʾ(������������)
	void Start();
	
	//ѡ����Ϸ�Ѷ�
	void SelectDifficulty();

};

#endif // GameController_h__


