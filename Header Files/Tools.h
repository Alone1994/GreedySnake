#pragma once
#ifndef Tools_h__
#define Tools_h__

#include <windows.h>
#include <stdio.h>

//�������ߵ�����
class Tools
{
public:
	static Tools* Instance();

public:
	Tools();
	virtual ~Tools();

public:
	//���ù��λ��
	void SetCurSorPositon(const int x, const int y);

	//���ô��ڴ�С
	void SetWindowSize(int cols, int lines);

	//����������ɫ
	void SetColor(int colorID);

	//���õ�ǰѡ���Ѷȱ�����ɫ
	void SetCurBackgroundColor();
};

#endif // Tools_h__


