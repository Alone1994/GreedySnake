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
};

#endif // Tools_h__


