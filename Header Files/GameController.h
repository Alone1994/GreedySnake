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

	//绘制游戏界面
	void DrawGame();

	//开始游戏,其实也是一个循环,当游戏结束时，将值返回给temp
	int PlayGame();

	//创建菜单
	int CreateMenu();

	//更新分数：普通食物和限时食物的分数不同
	void UpdateScore(const int& score);

	//重绘界面分数
	void RedrawUIScore();

	//重绘界面分数(吃到限时食物)
	void RewriteScore();

	int GameOver();

private:

	int _Speed;	//速度
	int _CurDifference;	//当前选择难度
	int _Score;	//当前分数
};

#endif // GameController_h__


