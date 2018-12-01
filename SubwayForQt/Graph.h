#pragma once
#include"Vertex.h"
#include"Link.h"
#include"Direction.h"


class Graph
{
public:
	map<string, Vertex> vertex;// 存放图中顶点的数组
	map<string, Link> path;// 存放图中边的数组
	vector<vector<Direction>> adjacentMatrix;
	vector<string>	disName;
	vector<int> disId;
	int TranSum = 0;
	vector<bool> isTransfer;
	vector<string> TransName;
	float Overall;
	int vertexNum = 0, pathNum = 0;// 图中顶点数和边数
	void setVertex(string name, string pathName);
	void setLink(string source, string target, string pathName, float distance);
	void setAdjMatrix();
	string getTransfer(string start, string end);
	//TODO:从isTransfer中获取换乘的起点和终点，循环复制图，寻路，输出
	void getAnotherPath(string start, string end, int minTranSum = 999);
	void delLink(string key);
};
extern vector<Graph> anotherPath;
