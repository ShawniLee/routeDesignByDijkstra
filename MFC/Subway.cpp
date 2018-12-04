#include "stdafx.h"
#include "SubWay.h"


SubWay::SubWay()
{

}

void SubWay::getPoint()
{
	//
	//
	originNumber = MAX;
	destineNumber = MAX;
	//cout << endl;
	//cout << "请输入起始点：";
	//cin >> origin;
	for (int i = 0; i < stationNum; i++)
	{
		if (sta[i].name == origin)
		{
			originNumber = i;
			break;
		}
	}
	//cout << "请输入终点：";
	//cin >> destine;
	for (int i = 0; i < stationNum; i++)
	{
		if (sta[i].name == destine)
		{
			destineNumber = i;
			break;
		}
	}

}


SubWay::~SubWay()
{
	// 释放内存
	for (int i = 0; i < stationNum; i++)
		delete[] map[i];
	delete[] map;

}

void SubWay::getstationNum()
{
	string line;
	ifstream file("./weight.txt");
	while (getline(file, line))
	{
		resource.push_back(line);
	}
	resourceLength = resource.size();
	//cout << name[0] << endl;
	sta[0].name = resource[0];
	stationNum = 1;
	for (int i = 0; i < resource.size() / 4; i++)
	{
		for (int j = 0;; j++)
		{
			if (resource[i * 4] == sta[j].name)
			{
				break;
			}
			if (sta[j + 1].name == "")
			{
				sta[j + 1].name = resource[i * 4];
				stationNum++;
			}
		}
	}
	//补充结尾车站
	int flag = 1;
	for (int i = 0; i < resource.size() / 4; i++)
	{
		for (int j = 0; j < stationNum; j++)
		{
			if (resource[i * 4 + 1] == sta[j].name)
			{
				flag = 0;
				break;
			}
			flag = 1;
		}
		if (flag == 1)
		{
			sta[stationNum].name = resource[i * 4 + 1];
			stationNum++;
			flag = 0;
		}
	}
	//判断是否有重复车站
	//for (int i = 0; i++; i < stationNum)
	//{
	//	for (int j = 0; i < stationNum; i++)
	//	{
	//		if (name[i] == name[j])
	//		{
	//			cout << "1";
	//		}
	//	}
	//}
	cout << "车站个数：" << stationNum << endl;
	//查看name数组
	//for (int i = 0; i < stationNum; i++)
	//{
	//	cout << name[i] << endl;
	//}
}

void SubWay::getSubwayLineNumber()
{
	string startPoint;
	string endPoint;
	string temp;
	int flag = 0;
	for (int i = 0; i < resourceLength / 4; i++)
	{
		startPoint = resource[i * 4];
		endPoint = resource[i * 4 + 1];
		temp = resource[i * 4 + 2];
		;
		for (int j = 0; j < stationNum; j++)
		{
			if (startPoint == sta[j].name)
			{
				flag = 0;
				for (int k = 0; k < sta[j].subwayLineNumber; k++)
				{
					if (temp == sta[j].subwayLine[k])
					{
						flag = 1;
						break;
					}
				}
				if (flag == 0)
				{
					sta[j].subwayLineNumber++;
					sta[j].subwayLine[sta[j].subwayLineNumber - 1] = temp;
				}
			}
			if (endPoint == sta[j].name)
			{
				flag = 0;
				for (int k = 0; k < sta[j].subwayLineNumber; k++)
				{
					if (temp == sta[j].subwayLine[k])
					{
						flag = 1;
						break;
					}
				}
				if (flag == 0)
				{
					sta[j].subwayLineNumber++;
					sta[j].subwayLine[sta[j].subwayLineNumber - 1] = temp;
					flag = 0;
				}
			}
		}
	}
	if (sta[22].subwayLine[0] == sta[22].subwayLine[1])
	{
		cout << 1;
	}
}

void SubWay::creatMap()
{
	map = new float*[this->stationNum];
	for (int i = 0; i < this->stationNum; i++) {
		map[i] = new float[this->stationNum];
		for (int k = 0; k < this->stationNum; k++) {
			//邻接矩阵初始化为无穷大
			map[i][k] = MAX;
		}
	}
	string startPoint;
	string endPoint;
	stringstream ss;//用于类型转换
	float ff;//用于类型转换
	for (int i = 0; i < this->stationNum; i++)
	{
		startPoint = sta[i].name;
		for (int j = 0; j < this->stationNum; j++)
		{
			endPoint = sta[j].name;
			for (int k = 0; k < resourceLength / 4; k++)
			{
				if (startPoint == resource[k * 4 + 0] && endPoint == resource[k * 4 + 1])
				{
					ss.clear();//清空
					ss << resource[k * 4 + 3];
					ss >> ff;
					map[i][j] = ff;
					//cout << map[i][k]<<"  "<< resource[k * 4 + 3] <<endl;
					ss.str("");//清空
					break;
				}
			}

		}
	}
	for (int i = 0; i < stationNum; i++)
	{
		for (int j = 0; j < stationNum; j++)
		{
			if (map[i][j] != MAX && map[j][i] == MAX)
			{
				map[j][i] = map[i][j];
			}

		}
	}
	//对角线归0
	for (int i = 0; i < stationNum; i++)
	{
		map[i][i] = 0;
	}
}

//用于显示邻接矩阵
void SubWay::ToTxt()
{
	int i, j;
	ofstream out("../out.txt");//打开文件
	ofstream outName("../outName.txt");
	ofstream outSpecific("../outSpecific.txt");
	for (i = 0; i < stationNum; i++)
	{
		for (j = 0; j < stationNum; j++)
		{
			out << map[i][j] << ',';//将每个元素写入文件，以逗号分隔。
		}
		out << endl;//每行输出结束，添加换行。
	}
	for (i = 0; i < stationNum; i++)
	{
		outName << sta[i].name;
		for (int j = 0; j < sta[i].subwayLineNumber; j++)
		{
			outName << "\t\t" << sta[i].subwayLine[j];//将每个元素写入文件，以逗号分隔
		}
		outName << endl;//每行输出结束，添加换行。
	}
	for (int i = 0; i < stationNum; i++)
	{
		outSpecific << map[235][i] << endl;
	}
	//计算非MAX点数			
	//int count = 0;
	//for (int i = 0; i < stationNum; i++)
	//{
	//	for (int j = 0; j < stationNum; j++)
	//	{
	//		if (map[i][j] != MAX ) 
	//		{
	//			count++;
	//		}
	//	}
	//}
	//cout << count;
}

void SubWay::InitializeDis()
{
	dis = new Dis[this->stationNum];
	int i;
	for (i = 0; i < stationNum; i++) {
		//设置当前的路径
		dis[i].path = "v" + to_string(originNumber) + "v" + to_string(i);
		dis[i].value = map[originNumber][i];
	}
	//设置起点的到起点的路径为0,并且设置为已访问过
	dis[originNumber].value = 0;
	dis[originNumber].visit = true;
}


void SubWay::caculate()
{
	int count = 1;
	//计算剩余的顶点的最短路径（剩余this->vexnum-1个顶点）
	while (count != this->stationNum) {
		//temp用于保存当前dis数组中最小的那个下标
		//min记录的当前的最小值
		int i = 0;
		int temp = 0;
		float min = MAX;
		for (i = 0; i < this->stationNum; i++) {
			if (!dis[i].visit && dis[i].value<min) {
				min = dis[i].value;
				temp = i;
			}
		}
		//cout << temp + 1 << "  "<<min << endl;
		//把temp对应的顶点加入到已经找到的最短路径的集合中
		dis[temp].visit = true;
		++count;
		for (i = 0; i < this->stationNum; i++) {
			//注意这里的条件arc[temp][i]!=MAX必须加，不然会出现溢出，从而造成程序异常
			if (!dis[i].visit && map[temp][i] != MAX && (dis[temp].value + map[temp][i]) < dis[i].value) {
				//如果新得到的边可以影响其他为访问的顶点，那就就更新它的最短路径和长度
				dis[i].value = dis[temp].value + map[temp][i];
				dis[i].path = dis[temp].path + "v" + to_string(i);
			}
		}
	}
	getPassStationNumber();
}

string SubWay::printPath()
{
	int i = 0;
	string str;
	string path;
	CString CSpath;
	str = "v" + to_string(originNumber);
	cout << "以" << str << "为起点的图的最短路径为：" << endl;
	if (dis[destineNumber].value != MAX)
	{
		//显示经过的所有车站 
		cout << dis[destineNumber].path << "=" << dis[destineNumber].value << endl;
		for (i = 0; pass[i] != destineNumber; i++)
		{
			cout << sta[pass[i]].name << " ";
			path = path + sta[pass[i]].name + "-->";
		}
		cout << sta[pass[i]].name;
		path += sta[pass[i]].name;

	}
	else {
		cout << dis[destineNumber].path << "是无最短路径的" << endl;
	}
	return path;
}

string SubWay::getPrice()
{
	float distance = dis[destineNumber].value;
	float price=0;
	if (distance <= 6.0)
	{
		price = 3.0;
	}
	else if (distance<=12.0)
	{
		price = 4.0;
	}
	else if (distance<=22.0)
	{
		price = 5.0;
	}
	else if (distance<=32.0)
	{
		price = 6.0;
	}
	else if(distance>32.0)
	{
		int chaochu;
		chaochu = (int)(distance - 32.0);
		price = 6.0 + chaochu /20 + 1;
	}
	string temp;

	std::strstream ss;
	ss << price;
	std::string res;
	ss >> res;
	temp = res;
	ss.clear();
	return temp;
}

string SubWay::getDistance()
{
	float distance = dis[destineNumber].value;
	string temp;

	std::strstream ss;
	ss << distance;
	std::string res;
	ss >> res;
	temp = res;
	ss.clear();
	return temp;
}

void SubWay::getPassStationNumber()
{
	pass.clear();
	int sum = 0;
	for (int i = 1; i < dis[destineNumber].path.length(); i++)
	{
		if ('0' <= dis[destineNumber].path.at(i) && dis[destineNumber].path.at(i) <= '9')
			//还原连续的数字
		{
			sum = sum * 10 + (dis[destineNumber].path.at(i) - '0');
		}
		if (!('0' <= dis[destineNumber].path.at(i) && dis[destineNumber].path.at(i) <= '9'))
		{
			pass.push_back(sum);
			sum = 0;
		}
	}
	//判断最后一个字符是否是数字
	//if (0 != sum)//添加这行代码会导致终点站选择编号为0时出错
		pass.push_back(sum);
	//for (unsigned int i = 0; i < pass.size(); i++)
	//	cout << pass.at(i) << " ";
}

void SubWay::getLineName()
{
}



