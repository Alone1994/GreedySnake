#include "pch.h"
#include "GameController.h"

#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <windows.h>

GameController::GameController():
	_Speed(100)
	,_Key(1)
	,_Score(0)
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

	_Score = 0;
	int ch ;	//记录键入值
	_Key = 1;	//记录选中项，初始选择第一个
	bool flag = false;//记录是否键入Enter键标记，初始置为否
	while (ch = _getch())
	{
		switch (ch)
		{
			case 72:
				if (_Key > 1)//当此时选中项为第一项时，UP上方向键无效
				{
					switch (_Key)
					{
					case 2:
						Tools::Instance()->SetCurSorPositon(27, 22);//给待选中项设置背景色
						Tools::Instance()->SetCurBackgroundColor();
						std::cout << "简单模式";

						Tools::Instance()->SetCurSorPositon(27, 24);//将已选中项取消背景色
						Tools::Instance()->SetColor(3);
						std::cout << "普通模式";

						--_Key;
						break;
					case 3:
						Tools::Instance()->SetCurSorPositon(27, 24);
						Tools::Instance()->SetCurBackgroundColor();
						std::cout << "普通模式";

						Tools::Instance()->SetCurSorPositon(27, 26);
						Tools::Instance()->SetColor(3);
						std::cout << "困难模式";

						--_Key;
						break;
					case 4:
						Tools::Instance()->SetCurSorPositon(27, 26);
						Tools::Instance()->SetCurBackgroundColor();
						std::cout << "困难模式";

						Tools::Instance()->SetCurSorPositon(27, 28);
						Tools::Instance()->SetColor(3);
						std::cout << "炼狱模式";

						--_Key;
						break;
					}
				}
				break;
		}
	}
}
