#ifndef Food_h__
#define Food_h__

#include "Snake.h"

class Snake;
 
//食物
class Food
{
public:
	Food();
	virtual ~Food();

public:
	//绘制食物
	void DrawFood(Snake& snake);

	//绘制限时食物
	void DrawLimitFood(Snake& snake);

	int GetCnt();

	//获取限时食物标记
	bool GetBigFlag();

	//限时食物的闪烁功能
	void FlashBigFood();

	//获取进度条
	int GetProgressBar();

private:
	int _Cnt;
	bool _FlashFlag;    //闪烁标记
	bool _BigFlag;    //是否有限时食物标记
	int _X, _Y;
	int _BigX, _BigY;    //限时食物的坐标
	int _ProgressBar;    //限时食物进度条

	friend class Snake;
};

#endif // Food_h__


