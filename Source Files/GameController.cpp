#include "pch.h"
#include "GameController.h"

#include <iostream>
#include <windows.h>

GameController::GameController()
{
}


GameController::~GameController()
{
}

void GameController::GameLoop()
{
	Start();
	while (true)
	{
		SelectDifficulty();
	}
}

void GameController::Start()
{
	Tools::Instance()->SetWindowSize(41, 32);
	Tools::Instance()->SetColor(2);

	StartInterface* start = new StartInterface();
	start->AnimationAction();	//播放动画
	delete start;	//释放内存

	//设置光标位置,输出提示语,等待任意键输入结束
	Tools::Instance()->SetCurSorPositon(13, 26);
	std::cout << "====================";
	Tools::Instance()->SetCurSorPositon(13, 27);
	system("pause");
}

void GameController::SelectDifficulty()
{
	//难度信息
	Tools::Instance()->SetColor(3);
	Tools::Instance()->SetCurSorPositon(13, 26);
	std::cout << "                          ";
	Tools::Instance()->SetCurSorPositon(13, 27);
	std::cout << "                          ";
	Tools::Instance()->SetCurSorPositon(6, 21);
	std::cout << "请选择游戏难度：";
	Tools::Instance()->SetCurSorPositon(6, 22);
	std::cout << "(上下键选择,回车确认)";
	Tools::Instance()->SetCurSorPositon(27, 22);
	Tools::Instance()->SetCurBackgroundColor();//第一个选项设置背景色以表示当前选中
	std::cout << "简单模式";
	Tools::Instance()->SetCurSorPositon(27, 24);
	Tools::Instance()->SetColor(3);
	std::cout << "普通模式";
	Tools::Instance()->SetCurSorPositon(27, 26);
	std::cout << "困难模式";
	Tools::Instance()->SetCurSorPositon(27, 28);
	std::cout << "炼狱模式";
	Tools::Instance()->SetCurSorPositon(0, 31);
}
