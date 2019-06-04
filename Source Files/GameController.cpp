#include "pch.h"
#include "GameController.h"
#include "Map.h"
#include "Snake.h"
#include "Food.h"

#include <time.h>
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

		DrawGame();

		int temp = PlayGame();//������Ϸѭ���������¿�ʼ���˳���Ϸʱ������ѭ��������ֵ��tmp

		if (temp == 1)    //����ֵΪ1ʱ���¿�ʼ��Ϸ
		{
			system("cls");
			continue;
		}
		else if (temp == 2)    //����ֵΪ2ʱ�˳���Ϸ
		{
			break;
		}
		else
		{
			break;
		}
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

	_Score = 0;
	int ch ;	//��¼����ֵ
	_Key = 1;	//��¼ѡ�����ʼѡ���һ��
	bool flag = false;//��¼�Ƿ����Enter����ǣ���ʼ��Ϊ��
	while (ch = _getch())
	{
		switch (ch)
		{
			case 72:
				if (_Key > 1)//����ʱѡ����Ϊ��һ��ʱ��UP�Ϸ������Ч
				{
					switch (_Key)
					{
					case 2:
						Tools::Instance()->SetCurSorPositon(27, 22);//����ѡ�������ñ���ɫ
						Tools::Instance()->SetCurBackgroundColor();
						std::cout << "��ģʽ";

						Tools::Instance()->SetCurSorPositon(27, 24);//����ѡ����ȡ������ɫ
						Tools::Instance()->SetColor(3);
						std::cout << "��ͨģʽ";

						--_Key;
						break;
					case 3:
						Tools::Instance()->SetCurSorPositon(27, 24);
						Tools::Instance()->SetCurBackgroundColor();
						std::cout << "��ͨģʽ";

						Tools::Instance()->SetCurSorPositon(27, 26);
						Tools::Instance()->SetColor(3);
						std::cout << "����ģʽ";

						--_Key;
						break;
					case 4:
						Tools::Instance()->SetCurSorPositon(27, 26);
						Tools::Instance()->SetCurBackgroundColor();
						std::cout << "����ģʽ";

						Tools::Instance()->SetCurSorPositon(27, 28);
						Tools::Instance()->SetColor(3);
						std::cout << "����ģʽ";

						--_Key;
						break;
					}
				}
				break;

			case 80:
				if(_Key < 4)
				{
					switch (_Key)
					{
						case 1:
							Tools::Instance()->SetCurSorPositon(27, 24);
							Tools::Instance()->SetCurBackgroundColor();
							std::cout << "��ͨģʽ";
							Tools::Instance()->SetCurSorPositon(27, 22);
							Tools::Instance()->SetColor(3);
							std::cout << "��ģʽ";

							++_Key;
							break;
						case 2:
							Tools::Instance()->SetCurSorPositon(27, 26);
							Tools::Instance()->SetCurBackgroundColor();
							std::cout << "����ģʽ";
							Tools::Instance()->SetCurSorPositon(27, 24);
							Tools::Instance()->SetColor(3);
							std::cout << "��ͨģʽ";

							++_Key;
							break;
						case 3:
							Tools::Instance()->SetCurSorPositon(27, 28);
							Tools::Instance()->SetCurBackgroundColor();
							std::cout << "����ģʽ";
							Tools::Instance()->SetCurSorPositon(27, 26);
							Tools::Instance()->SetColor(3);
							std::cout << "����ģʽ";

							++_Key;
							break;
					}
				}
				break;

			case 13:    //�س�
				flag = true;
				break;
			default:	//��Ч����
				break;
		}

		if (flag)
		{
			break;
		}

		Tools::Instance()->SetCurSorPositon(0, 31);    //���ù�굽���½�
	}

	switch (_Key)//������ѡѡ�������ߵ��ƶ��ٶȣ�speedֵԽ���ٶ�Խ��
	{
	case 1:
		_Speed = 135;
		break;
	case 2:
		_Speed = 100;
		break;
	case 3:
		_Speed = 60;
		break;
	case 4:
		_Speed = 30;
		break;
	default:
		break;
	}
}

void GameController::DrawGame()
{
	system("cls");    //����

	Tools::Instance()->SetColor(3);

	//���Ƴ�ʼ��ͼ
	Map* initMap = new Map();
	initMap->PrintInitMap();   
	delete initMap;

	//���Ʋ����
	Tools::Instance()->SetCurSorPositon(33, 1);
	std::cout << "Greedy Snake...";

	Tools::Instance()->SetCurSorPositon(34, 2);
	std::cout << "̰����";

	Tools::Instance()->SetCurSorPositon(31, 4);
	std::cout << "�Ѷ�";

	Tools::Instance()->SetCurSorPositon(36, 5);
	switch (_Key)
	{
	case 1:
		std::cout << "��ģʽ";
		break;
	case 2:
		std::cout << "��ͨģʽ";
		break;
	case 3:
		std::cout << "����ģʽ";
		break;
	case 4:
		std::cout << "����ģʽ";
	default:
		break;
	}

	Tools::Instance()->SetCurSorPositon(31, 7);
	std::cout << "�÷֣�";

	Tools::Instance()->SetCurSorPositon(37, 8);
	std::cout << "     0";

	Tools::Instance()->SetCurSorPositon(33, 13);
	std::cout << " ������ƶ�";

	Tools::Instance()->SetCurSorPositon(33, 15);
	std::cout << " ESC����ͣ";
}

int GameController::PlayGame()
{
	//��ʼ���ߺ�ʳ��
	Snake* snake = new Snake();
	Food* food = new Food();

	Tools::Instance()->SetColor(6);
	snake->InitSnake();
	srand((unsigned)time(NULL));    //���������,����ʳ�������λ��
	food->DrawFood(*snake);

	//todo:��Ϸѭ�� 2019.06.03 by zjz

	while (snake->OverEdge() && snake->HitSelf())
	{
		if (!snake->ChangeDirection())
		{
			int temp = CreateMenu();
			switch (temp)
			{
			case 1://������Ϸ
				break;

			case 2://���¿�ʼ
				delete snake;
				delete food;
				return 1;//��1��ΪPlayGame�����ķ���ֵ���ص�Game�����У���ʾ���¿�ʼ

			case 3://�˳���Ϸ
				delete snake;
				delete food;
				return 2;//��2��ΪPlayGame�����ķ���ֵ���ص�Game�����У���ʾ�˳���Ϸ

			default:
				break;
			}
		}

		//����Ե�ʳ��
		if (snake->GetFood(*food))
		{
			snake->Move();
			UpdateScore(1);
			RedrawUIScore();
			food->DrawFood(*snake);
		}
		else
		{
			snake->InitMove();
		}

		Sleep(_Speed);//�����ߵ��ƶ�Ч��

		//������ʱʳ��
	}

	return 0;
}

int GameController::CreateMenu()
{
	/*���Ʋ˵�*/
	Tools::Instance()->SetColor(11);
	Tools::Instance()->SetCurSorPositon(32, 19);
	std::cout << "�˵���";
	Sleep(100);
	Tools::Instance()->SetCurSorPositon(34, 21);
	Tools::Instance()->SetCurBackgroundColor();
	std::cout << "������Ϸ";
	Sleep(100);
	Tools::Instance()->SetCurSorPositon(34, 23);
	Tools::Instance()->SetColor(11);
	std::cout << "���¿�ʼ";
	Sleep(100);
	Tools::Instance()->SetCurSorPositon(34, 25);
	std::cout << "�˳���Ϸ";
	Tools::Instance()->SetCurSorPositon(0, 31);

	/*ѡ�񲿷�*/
	int ch;
	int tmp_key = 1;
	bool flag = false;
	while (ch = _getch())
	{
		switch (ch)
		{
		case 72://UP
			if (tmp_key > 1)
			{
				switch (tmp_key)
				{
				case 2:
					Tools::Instance()->SetCurSorPositon(34, 21);
					Tools::Instance()->SetCurBackgroundColor();
					std::cout << "������Ϸ";
					Tools::Instance()->SetCurSorPositon(34, 23);
					Tools::Instance()->SetColor(11);
					std::cout << "���¿�ʼ";

					--tmp_key;
					break;
				case 3:
					Tools::Instance()->SetCurSorPositon(34, 23);
					Tools::Instance()->SetCurBackgroundColor();
					std::cout << "���¿�ʼ";
					Tools::Instance()->SetCurSorPositon(34, 25);
					Tools::Instance()->SetColor(11);
					std::cout << "�˳���Ϸ";

					--tmp_key;
					break;
				}
			}
			break;

		case 80://DOWN
			if (tmp_key < 3)
			{
				switch (tmp_key)
				{
				case 1:
					Tools::Instance()->SetCurSorPositon(34, 23);
					Tools::Instance()->SetCurBackgroundColor();
					std::cout << "���¿�ʼ";
					Tools::Instance()->SetCurSorPositon(34, 21);
					Tools::Instance()->SetColor(11);
					std::cout << "������Ϸ";

					++tmp_key;
					break;
				case 2:
					Tools::Instance()->SetCurSorPositon(34, 25);
					Tools::Instance()->SetCurBackgroundColor();
					std::cout << "�˳���Ϸ";
					Tools::Instance()->SetCurSorPositon(34, 23);
					Tools::Instance()->SetColor(11);
					std::cout << "���¿�ʼ";

					++tmp_key;
					break;
				}
			}
			break;

		case 13://Enter
			flag = true;
			break;

		default:
			break;
		}

		if (flag)
		{
			break;
		}
		Tools::Instance()->SetCurSorPositon(0, 31);
	}

	if (tmp_key == 1) //ѡ�������Ϸ���򽫲˵�����
	{
		Tools::Instance()->SetCurSorPositon(32, 19);
		std::cout << "      ";
		Tools::Instance()->SetCurSorPositon(34, 21);
		std::cout << "        ";
		Tools::Instance()->SetCurSorPositon(34, 23);
		std::cout << "        ";
		Tools::Instance()->SetCurSorPositon(34, 25);
		std::cout << "        ";
	}
	return tmp_key;
}

void GameController::UpdateScore(const int& score)
{
	_Score += _Key * 10 * score;
}

void GameController::RedrawUIScore()
{
	Tools::Instance()->SetCurSorPositon(37, 8);
	Tools::Instance()->SetColor(11);
	int bit = 0;
	int temp = _Score;
	while (temp != 0)
	{
		bit++;
		temp /= 10;
	}

	for (int i = 0; i < (6 - bit); i++)
	{
		std::cout << " ";
	}
	std::cout << _Score;
}
