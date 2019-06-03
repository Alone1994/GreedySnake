#ifndef Map_h__
#define Map_h__

#include "Point.h"

#include <vector>
#include <windows.h>

//初始地图点集管理类
class Map
{
public:
	Map() 
	{
		_InitMap.emplace_back(Point(1, 1));
		_InitMap.emplace_back(Point(2, 1));
		_InitMap.emplace_back(Point(3, 1));
		_InitMap.emplace_back(Point(4, 1));
		_InitMap.emplace_back(Point(5, 1));
		_InitMap.emplace_back(Point(6, 1));
		_InitMap.emplace_back(Point(7, 1));
		_InitMap.emplace_back(Point(8, 1));
		_InitMap.emplace_back(Point(9, 1));
		_InitMap.emplace_back(Point(10, 1));
		_InitMap.emplace_back(Point(11, 1));
		_InitMap.emplace_back(Point(12, 1));
		_InitMap.emplace_back(Point(13, 1));
		_InitMap.emplace_back(Point(14, 1));
		_InitMap.emplace_back(Point(15, 1));
		_InitMap.emplace_back(Point(16, 1));
		_InitMap.emplace_back(Point(17, 1));
		_InitMap.emplace_back(Point(18, 1));
		_InitMap.emplace_back(Point(19, 1));
		_InitMap.emplace_back(Point(20, 1));
		_InitMap.emplace_back(Point(21, 1));
		_InitMap.emplace_back(Point(22, 1));
		_InitMap.emplace_back(Point(23, 1));
		_InitMap.emplace_back(Point(24, 1));
		_InitMap.emplace_back(Point(25, 1));
		_InitMap.emplace_back(Point(26, 1));
		_InitMap.emplace_back(Point(27, 1));
		_InitMap.emplace_back(Point(28, 1));
		_InitMap.emplace_back(Point(29, 1));
		_InitMap.emplace_back(Point(30, 1));
		_InitMap.emplace_back(Point(1, 2));
		_InitMap.emplace_back(Point(30, 2));
		_InitMap.emplace_back(Point(1, 3));
		_InitMap.emplace_back(Point(30, 3));
		_InitMap.emplace_back(Point(1, 4));
		_InitMap.emplace_back(Point(30, 4));
		_InitMap.emplace_back(Point(1, 5));
		_InitMap.emplace_back(Point(30, 5));
		_InitMap.emplace_back(Point(1, 6));
		_InitMap.emplace_back(Point(30, 6));
		_InitMap.emplace_back(Point(1, 7));
		_InitMap.emplace_back(Point(30, 7));
		_InitMap.emplace_back(Point(1, 8));
		_InitMap.emplace_back(Point(30, 8));
		_InitMap.emplace_back(Point(1, 9));
		_InitMap.emplace_back(Point(30, 9));
		_InitMap.emplace_back(Point(1, 10));
		_InitMap.emplace_back(Point(30, 10));
		_InitMap.emplace_back(Point(1, 11));
		_InitMap.emplace_back(Point(30, 11));
		_InitMap.emplace_back(Point(1, 12));
		_InitMap.emplace_back(Point(30, 12));
		_InitMap.emplace_back(Point(1, 13));
		_InitMap.emplace_back(Point(30, 13));
		_InitMap.emplace_back(Point(1, 14));
		_InitMap.emplace_back(Point(30, 14));
		_InitMap.emplace_back(Point(1, 15));
		_InitMap.emplace_back(Point(30, 15));
		_InitMap.emplace_back(Point(1, 16));
		_InitMap.emplace_back(Point(30, 16));
		_InitMap.emplace_back(Point(1, 17));
		_InitMap.emplace_back(Point(30, 17));
		_InitMap.emplace_back(Point(1, 18));
		_InitMap.emplace_back(Point(30, 18));
		_InitMap.emplace_back(Point(1, 19));
		_InitMap.emplace_back(Point(30, 19));
		_InitMap.emplace_back(Point(1, 20));
		_InitMap.emplace_back(Point(30, 20));
		_InitMap.emplace_back(Point(1, 21));
		_InitMap.emplace_back(Point(30, 21));
		_InitMap.emplace_back(Point(1, 22));
		_InitMap.emplace_back(Point(30, 22));
		_InitMap.emplace_back(Point(1, 23));
		_InitMap.emplace_back(Point(30, 23));
		_InitMap.emplace_back(Point(1, 24));
		_InitMap.emplace_back(Point(30, 24));
		_InitMap.emplace_back(Point(1, 25));
		_InitMap.emplace_back(Point(30, 25));
		_InitMap.emplace_back(Point(1, 26));
		_InitMap.emplace_back(Point(30, 26));
		_InitMap.emplace_back(Point(1, 27));
		_InitMap.emplace_back(Point(30, 27));
		_InitMap.emplace_back(Point(1, 28));
		_InitMap.emplace_back(Point(30, 28));
		_InitMap.emplace_back(Point(1, 29));
		_InitMap.emplace_back(Point(30, 29));
		_InitMap.emplace_back(Point(1, 30));
		_InitMap.emplace_back(Point(2, 30));
		_InitMap.emplace_back(Point(3, 30));
		_InitMap.emplace_back(Point(4, 30));
		_InitMap.emplace_back(Point(5, 30));
		_InitMap.emplace_back(Point(6, 30));
		_InitMap.emplace_back(Point(7, 30));
		_InitMap.emplace_back(Point(8, 30));
		_InitMap.emplace_back(Point(9, 30));
		_InitMap.emplace_back(Point(10, 30));
		_InitMap.emplace_back(Point(11, 30));
		_InitMap.emplace_back(Point(12, 30));
		_InitMap.emplace_back(Point(13, 30));
		_InitMap.emplace_back(Point(14, 30));
		_InitMap.emplace_back(Point(15, 30));
		_InitMap.emplace_back(Point(16, 30));
		_InitMap.emplace_back(Point(17, 30));
		_InitMap.emplace_back(Point(18, 30));
		_InitMap.emplace_back(Point(19, 30));
		_InitMap.emplace_back(Point(20, 30));
		_InitMap.emplace_back(Point(21, 30));
		_InitMap.emplace_back(Point(22, 30));
		_InitMap.emplace_back(Point(23, 30));
		_InitMap.emplace_back(Point(24, 30));
		_InitMap.emplace_back(Point(25, 30));
		_InitMap.emplace_back(Point(26, 30));
		_InitMap.emplace_back(Point(27, 30));
		_InitMap.emplace_back(Point(28, 30));
		_InitMap.emplace_back(Point(29, 30));
		_InitMap.emplace_back(Point(30, 30));
	};
	virtual ~Map();

public:

	//绘制初始地图
	void PrintInitMap();

private:

	std::vector<Point> _InitMap;    //保存初始地图
};


#endif // Map_h__

