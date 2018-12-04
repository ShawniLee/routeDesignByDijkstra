#include "Graph.h"
#include"SubwayForQt.h"


void Graph::setVertex(string name, string pathName)
{
	if (vertex.count(name))//有这个结点，说明这是中转站，增加线路名
	{
		vertex.find(name)->second.pathName.insert(pathName);
	}
	else//无
	{
		int id = vertexNum;
		vertexNum++;
		Vertex temp(pathName, id);
		vertex.insert(pair<string, Vertex>(name, temp));
	}
}

void Graph::setLink(string source, string target, string pathName, float distance)
{
	string key = source + " " + target;
	if (path.count(key))//有这条线路，增加线名
	{
		path.find(key)->second.pathName.insert(pathName);
	}
	else
	{
		Link b(pathName, distance);
		b.Lid = pathNum;
		pathNum++;
		path.insert(pair<string, Link>(key, b));
	}
}

void Graph::setAdjMatrix()
{
	map<string, Link>::iterator aPath = path.begin();
	adjacentMatrix.resize(vertexNum);
	while (aPath != path.end())
	{
		pair<string, Vertex> start = *vertex.find(SubwayForQt::split(aPath->first, " ").at(0));//起点
		pair<string, Vertex> end = *vertex.find(SubwayForQt::split(aPath->first, " ").at(1));//终点
		Direction temp1(start.second.Vid, aPath->second.distance, start.first);
		Direction temp2(end.second.Vid, aPath->second.distance, end.first);
		adjacentMatrix[start.second.Vid].push_back(temp2);//所得线路向量插入邻接矩阵
		adjacentMatrix[end.second.Vid].push_back(temp1);
		aPath++;
	}
}



string Graph::getTransfer(string start, string end)
{
	string currentLine, PreLine;
	bool flag = false;
	if (end == "")
	{

		isTransfer.clear();
		TransName.clear();
		isTransfer.push_back(false);
		TransName.push_back(start);
		return "start23";
	}
	else
	{
		Vertex endV = vertex.find(end)->second;
		PreLine = getTransfer(start, disName[endV.Vid]);
		if (PreLine == "start23")
		{
			set<string> startV = vertex.find(start)->second.pathName;
			for (set<string>::iterator i = startV.begin(); i != startV.end(); i++)
			{
				for (set<string>::iterator j = endV.pathName.begin(); j != endV.pathName.end(); j++)
				{
					if (*i == *j)//两点确定一条直线
					{
						currentLine = *i;
						i = startV.end();
						isTransfer.push_back(false);
						i--;
						break;
					}
				}
			}
		}
		else
		{
			for (set<string>::iterator j = endV.pathName.begin(); j != endV.pathName.end(); j++)
			{
				if (PreLine == *j)//嗯我还在这条线上
				{
					currentLine = *j;
					flag = true;
				}
			}
			if (flag == false)//诶我是不是应该换乘了（上一站）
			{
				currentLine = *endV.pathName.begin();
				vector<bool>::iterator temp = isTransfer.end();
				temp--;
				*temp = true;
				isTransfer.push_back(false);
			}
			else
			{
				isTransfer.push_back(false);
			}
		}
		TransName.push_back(end);
		return currentLine;
	}
}

void Graph::getAnotherPath(string start, string end, int minTranSum)
{
	Graph temp;
	for (vector<bool>::iterator i = isTransfer.begin(); i != isTransfer.end(); i++)
	{
		if (*i)
		{
			int TranNum = i - isTransfer.begin();
			temp = *this;
			string key = *(TransName.begin() + TranNum - 1) + " " + *(TransName.begin() + TranNum);

			temp.TranSum = 0;
			temp.disId.clear();
			temp.disName.clear();
			temp.delLink(key);
			temp.Overall = SubwayForQt::Dijkstra(temp, start, end);
			if (fabs(temp.Overall - numeric_limits<float>::max())<1e-4)//不可达，放弃
			{
				continue;
			}
			temp.getTransfer(start, end);
			for (int i = 0; i < temp.isTransfer.size(); i++)
			{
				if (*(temp.isTransfer.begin() + i))
				{
					temp.TranSum++;
				}
			}

			if (temp.Overall<Overall * 2 && temp.TranSum <= minTranSum)
			{
				minTranSum = temp.TranSum;
				temp.getAnotherPath(start, end, minTranSum);
				anotherPath.push_back(temp);
			}
		}
	}
	return;
}

void Graph::delLink(string key)
{
	vector<string> temp = SubwayForQt::split(key, " ");
	string key2 = temp[1] + " " + temp[0];
	Vertex start = vertex.find(temp[0])->second;
	Vertex end = vertex.find(temp[1])->second;
	for (vector<Direction>::iterator i = adjacentMatrix[start.Vid].begin(); i != adjacentMatrix[start.Vid].end(); i++)
	{
		if (i->destVId == end.Vid) {
			adjacentMatrix[start.Vid].erase(i);
			break;
		}
	}
	for (vector<Direction>::iterator i = adjacentMatrix[end.Vid].begin(); i != adjacentMatrix[end.Vid].end(); i++)//交换起始点删除
	{
		if (i->destVId == start.Vid) {
			adjacentMatrix[end.Vid].erase(i);
			break;
		}
	}
}
