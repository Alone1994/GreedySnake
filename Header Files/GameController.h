#define _CRT_SECURE_NO_WARNINGS
#pragma once
#ifndef GameController_h__
#define GameController_h__

#include "StartInterface.h"
#include "Tools.h"

using namespace std;

//游戏管理类
class GameController
{
public:
	GameController();
	virtual ~GameController();

public:
	//整个游戏循环开始
	void GameLoop();
	
	//主界面显示(包括开场动画)
	void Start();
	
	//选择游戏难度
	void SelectDifficulty();

private:

	int _Speed;	//速度
	int _Key;	//当前选择难度
	int _Score;	//当前分数
};

#endif // GameController_h__


