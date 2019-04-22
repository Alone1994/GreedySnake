#pragma once
#ifndef Tools_h__
#define Tools_h__

#include <windows.h>
#include <stdio.h>

//公共工具单例类
class Tools
{
public:
	static Tools* Instance();

public:
	Tools();
	virtual ~Tools();

public:
	//设置光标位置
	void SetCurSorPositon(const int x, const int y);
};

#endif // Tools_h__


