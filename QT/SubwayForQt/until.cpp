#include"Direction.h"
#include"Vertex.h"
#include"Link.h"
Direction::Direction()
{
}

Direction::Direction(int id, float distance, string destName) :destVId(id), distance(distance), destName(destName) {}
bool operator < (Direction a, Direction b)
{
	if (a.distance == b.distance)
		return a.destVId>b.destVId;//距离相等先出靠前的
	return a.distance>b.distance;              //最小堆
}

Vertex::Vertex(string pathName, int id)
{
	this->Vid = id;
	this->pathName.insert(pathName);
}

Link::Link(string pathName, float distance)
{
	this->distance = distance;
	this->pathName.insert(pathName);
}