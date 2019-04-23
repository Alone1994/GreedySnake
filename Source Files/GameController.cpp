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
	start->AnimationAction();	//���Ŷ���
	delete start;	//�ͷ��ڴ�

	//���ù��λ��,�����ʾ��,�ȴ�������������
	Tools::Instance()->SetCurSorPositon(13, 26);
	std::cout << "====================";
	Tools::Instance()->SetCurSorPositon(13, 27);
	system("pause");
}

void GameController::SelectDifficulty()
{
	//�Ѷ���Ϣ
	Tools::Instance()->SetColor(3);
	Tools::Instance()->SetCurSorPositon(13, 26);
	std::cout << "                          ";
	Tools::Instance()->SetCurSorPositon(13, 27);
	std::cout << "                          ";
	Tools::Instance()->SetCurSorPositon(6, 21);
	std::cout << "��ѡ����Ϸ�Ѷȣ�";
	Tools::Instance()->SetCurSorPositon(6, 22);
	std::cout << "(���¼�ѡ��,�س�ȷ��)";
	Tools::Instance()->SetCurSorPositon(27, 22);
	Tools::Instance()->SetCurBackgroundColor();//��һ��ѡ�����ñ���ɫ�Ա�ʾ��ǰѡ��
	std::cout << "��ģʽ";
	Tools::Instance()->SetCurSorPositon(27, 24);
	Tools::Instance()->SetColor(3);
	std::cout << "��ͨģʽ";
	Tools::Instance()->SetCurSorPositon(27, 26);
	std::cout << "����ģʽ";
	Tools::Instance()->SetCurSorPositon(27, 28);
	std::cout << "����ģʽ";
	Tools::Instance()->SetCurSorPositon(0, 31);
}
