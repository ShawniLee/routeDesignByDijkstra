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
	//cout << "��������ʼ�㣺";
	//cin >> origin;
	for (int i = 0; i < stationNum; i++)
	{
		if (sta[i].name == origin)
		{
			originNumber = i;
			break;
		}
	}
	//cout << "�������յ㣺";
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
	// �ͷ��ڴ�
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
	//�����β��վ
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
	//�ж��Ƿ����ظ���վ
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
	cout << "��վ������" << stationNum << endl;
	//�鿴name����
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
			//�ڽӾ����ʼ��Ϊ�����
			map[i][k] = MAX;
		}
	}
	string startPoint;
	string endPoint;
	stringstream ss;//��������ת��
	float ff;//��������ת��
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
					ss.clear();//���
					ss << resource[k * 4 + 3];
					ss >> ff;
					map[i][j] = ff;
					//cout << map[i][k]<<"  "<< resource[k * 4 + 3] <<endl;
					ss.str("");//���
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
	//�Խ��߹�0
	for (int i = 0; i < stationNum; i++)
	{
		map[i][i] = 0;
	}
}

//������ʾ�ڽӾ���
void SubWay::ToTxt()
{
	int i, j;
	ofstream out("../out.txt");//���ļ�
	ofstream outName("../outName.txt");
	ofstream outSpecific("../outSpecific.txt");
	for (i = 0; i < stationNum; i++)
	{
		for (j = 0; j < stationNum; j++)
		{
			out << map[i][j] << ',';//��ÿ��Ԫ��д���ļ����Զ��ŷָ���
		}
		out << endl;//ÿ�������������ӻ��С�
	}
	for (i = 0; i < stationNum; i++)
	{
		outName << sta[i].name;
		for (int j = 0; j < sta[i].subwayLineNumber; j++)
		{
			outName << "\t\t" << sta[i].subwayLine[j];//��ÿ��Ԫ��д���ļ����Զ��ŷָ�
		}
		outName << endl;//ÿ�������������ӻ��С�
	}
	for (int i = 0; i < stationNum; i++)
	{
		outSpecific << map[235][i] << endl;
	}
	//�����MAX����			
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
		//���õ�ǰ��·��
		dis[i].path = "v" + to_string(originNumber) + "v" + to_string(i);
		dis[i].value = map[originNumber][i];
	}
	//�������ĵ�����·��Ϊ0,��������Ϊ�ѷ��ʹ�
	dis[originNumber].value = 0;
	dis[originNumber].visit = true;
}


void SubWay::caculate()
{
	int count = 1;
	//����ʣ��Ķ�������·����ʣ��this->vexnum-1�����㣩
	while (count != this->stationNum) {
		//temp���ڱ��浱ǰdis��������С���Ǹ��±�
		//min��¼�ĵ�ǰ����Сֵ
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
		//��temp��Ӧ�Ķ�����뵽�Ѿ��ҵ������·���ļ�����
		dis[temp].visit = true;
		++count;
		for (i = 0; i < this->stationNum; i++) {
			//ע�����������arc[temp][i]!=MAX����ӣ���Ȼ�����������Ӷ���ɳ����쳣
			if (!dis[i].visit && map[temp][i] != MAX && (dis[temp].value + map[temp][i]) < dis[i].value) {
				//����µõ��ı߿���Ӱ������Ϊ���ʵĶ��㣬�Ǿ;͸����������·���ͳ���
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
	cout << "��" << str << "Ϊ����ͼ�����·��Ϊ��" << endl;
	if (dis[destineNumber].value != MAX)
	{
		//��ʾ���������г�վ 
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
		cout << dis[destineNumber].path << "�������·����" << endl;
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
			//��ԭ����������
		{
			sum = sum * 10 + (dis[destineNumber].path.at(i) - '0');
		}
		if (!('0' <= dis[destineNumber].path.at(i) && dis[destineNumber].path.at(i) <= '9'))
		{
			pass.push_back(sum);
			sum = 0;
		}
	}
	//�ж����һ���ַ��Ƿ�������
	//if (0 != sum)//������д���ᵼ���յ�վѡ����Ϊ0ʱ����
		pass.push_back(sum);
	//for (unsigned int i = 0; i < pass.size(); i++)
	//	cout << pass.at(i) << " ";
}

void SubWay::getLineName()
{
}



