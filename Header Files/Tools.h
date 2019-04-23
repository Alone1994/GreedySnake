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

	//设置窗口大小
	void SetWindowSize(int cols, int lines);

	//设置文字颜色
	void SetColor(int colorID);

	//设置当前选中难度背景颜色
	void SetCurBackgroundColor();
};

#endif // Tools_h__


