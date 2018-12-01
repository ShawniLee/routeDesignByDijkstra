#pragma once
#include"define.h"
class Direction
{
public:
	string destName;
	int destVId;
	float distance;
	Direction();
	Direction(int id, float distance, string destName);

private:


};
bool operator < (Direction a, Direction b);
