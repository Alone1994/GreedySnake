#ifndef Food_h__
#define Food_h__

#include "Snake.h"

class Snake;
 
//ʳ��
class Food
{
public:
	Food();
	virtual ~Food();

public:
	//����ʳ��
	void DrawFood(Snake& snake);

	//������ʱʳ��
	void DrawLimitFood(Snake& snake);

	int GetCnt();

	//��ȡ��ʱʳ����
	bool GetBigFlag();

	//��ʱʳ�����˸����
	void FlashBigFood();

	//��ȡ������
	int GetProgressBar();

private:
	int _Cnt;
	bool _FlashFlag;    //��˸���
	bool _BigFlag;    //�Ƿ�����ʱʳ����
	int _X, _Y;
	int _BigX, _BigY;    //��ʱʳ�������
	int _ProgressBar;    //��ʱʳ�������

	friend class Snake;
};

#endif // Food_h__


