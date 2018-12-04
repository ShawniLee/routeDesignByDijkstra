#pragma once
#define MAX 10000

struct Dis
{
	string path;
	float value;
	bool visit;
	Dis() {
		visit = false;
		value = 0;
		path = "";
	}
};
struct Station
{
	string name;
	string subwayLine[10];
	int subwayLineNumber = 0;
};

class SubWay
{
public:
	SubWay();
	~SubWay();
	void getPoint();//��ȡ�����յ�
	void getstationNum();
	void getSubwayLineNumber();
	void creatMap();//��ȡ���ڵ���վ֮��ľ���
	void ToTxt();
	void InitializeDis();//�������ڼ����Dis����
	void caculate();//��ʼ���ļ���
	string printPath();
	string getPrice();
	string getDistance();

	void getPassStationNumber();//�õ�������վ����
	void getLineName();
	vector<CString> LineName;
	vector<int> pass;
	Dis * dis;
	int stationNum = 0;
	float **map;//���ڵ���վ֮��ľ���
	Station sta[900];//��ŵ���վ����Ϣ
	vector<string> resource;//�������ļ��ж�ȡ������
	int resourceLength;
	string destine;
	int destineNumber;
	string origin;
	int originNumber;
};

