#define _CRT_SECURE_NO_WARNINGS
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

	//������Ϸ����
	void DrawGame();

	//��ʼ��Ϸ,��ʵҲ��һ��ѭ��,����Ϸ����ʱ����ֵ���ظ�temp
	int PlayGame();

	//�����˵�
	int CreateMenu();

	//���·�������ͨʳ�����ʱʳ��ķ�����ͬ
	void UpdateScore(const int& score);

	//�ػ�������
	void RedrawUIScore();

	//�ػ�������(�Ե���ʱʳ��)
	void RewriteScore();

	int GameOver();

private:

	int _Speed;	//�ٶ�
	int _CurDifference;	//��ǰѡ���Ѷ�
	int _Score;	//��ǰ����
};

#endif // GameController_h__


