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

};

#endif // GameController_h__


