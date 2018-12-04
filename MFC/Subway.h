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
	void getPoint();//获取起点和终点
	void getstationNum();
	void getSubwayLineNumber();
	void creatMap();//获取相邻地铁站之间的距离
	void ToTxt();
	void InitializeDis();//创建用于计算的Dis数组
	void caculate();//开始核心计算
	string printPath();
	string getPrice();
	string getDistance();

	void getPassStationNumber();//得到经过的站点编号
	void getLineName();
	vector<CString> LineName;
	vector<int> pass;
	Dis * dis;
	int stationNum = 0;
	float **map;//相邻地铁站之间的距离
	Station sta[900];//存放地铁站的信息
	vector<string> resource;//从数据文件中读取的数据
	int resourceLength;
	string destine;
	int destineNumber;
	string origin;
	int originNumber;
};

