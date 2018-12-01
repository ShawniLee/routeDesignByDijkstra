#pragma once
#include"Vertex.h"
#include"Link.h"
#include"Direction.h"


class Graph
{
public:
	map<string, Vertex> vertex;// ���ͼ�ж��������
	map<string, Link> path;// ���ͼ�бߵ�����
	vector<vector<Direction>> adjacentMatrix;
	vector<string>	disName;
	vector<int> disId;
	int TranSum = 0;
	vector<bool> isTransfer;
	vector<string> TransName;
	float Overall;
	int vertexNum = 0, pathNum = 0;// ͼ�ж������ͱ���
	void setVertex(string name, string pathName);
	void setLink(string source, string target, string pathName, float distance);
	void setAdjMatrix();
	string getTransfer(string start, string end);
	//TODO:��isTransfer�л�ȡ���˵������յ㣬ѭ������ͼ��Ѱ·�����
	void getAnotherPath(string start, string end, int minTranSum = 999);
	void delLink(string key);
};
extern vector<Graph> anotherPath;
