#include "pch.h"
#include "Map.h"

Map::~Map()
{
}

void Map::PrintInitMap()
{
	for (auto& point : _InitMap)
	{
		point.PointPrint();
		Sleep(50);    //营造渐进绘制的效果,而不是直接绘制所有点
	}
}
