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
		Sleep(50);    //Ӫ�콥�����Ƶ�Ч��,������ֱ�ӻ������е�
	}
}
