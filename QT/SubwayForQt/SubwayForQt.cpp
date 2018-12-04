#include "SubwayForQt.h"
#include"qcompleter.h"

vector<Graph> anotherPath;
Graph G;
void SubwayForQt::justClose()
{
	qApp->exit(0);
}
SubwayForQt::SubwayForQt(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.spendButton,&QPushButton::clicked,this,&SubwayForQt::spendMoney);
	connect(ui.close, &QPushButton::clicked,this,&SubwayForQt::justClose);
	readData();
	bg = new QButtonGroup(this);
	bg->addButton(ui.PathRadio, false);//一个值为0
	bg->addButton(ui.TranRadio, true);//一个值为1
	this->setWindowIcon(QIcon("subway.png"));
	//this->setAttribute(Qt::WA_TranslucentBackground, true);
	this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏
	QPixmap pixmap = QPixmap("subway_map.jpg").scaled(this->size());
	QPalette  palette(this->palette());
	palette.setBrush(QPalette::Background, QBrush(pixmap));
	this->setPalette(palette);
	QFont font("Microsoft YaHei", 8, 50, false);
	qApp->setFont(font);

	
}
float SubwayForQt::Dijkstra(Graph & G, string startName, string endName)
{
	int i;
	G.disName.resize(G.vertexNum);
	G.disId.resize(G.vertexNum);
	vector<bool> beenV(G.vertexNum, false);
	Vertex startV = G.vertex.find(startName)->second;
	Vertex endV = G.vertex.find(endName)->second;
	vector<float> dis(G.vertexNum);
	for (int i = 0; i < G.vertexNum; i++)
	{
		dis[i] = numeric_limits<float>::max();
	}
	dis[startV.Vid] = 0;
	//优先队列
	priority_queue<Direction> q;
	for (vector<Direction>::iterator i = G.adjacentMatrix[startV.Vid].begin(); i != G.adjacentMatrix[startV.Vid].end(); i++)
		q.push(Direction(i->destVId, i->distance, i->destName));//将第一步的所有可能性放入堆中
	while (!q.empty())
	{
		Direction oneStepMin = q.top(); //下一步可达的最近路线
		q.pop();
		dis[oneStepMin.destVId] = oneStepMin.distance;
		beenV[oneStepMin.destVId] = true;
		if (oneStepMin.destVId == endV.Vid)//到达最终目标，不遍历多余的点
		{
			return dis[endV.Vid];
		}
		for (i = 0; i<G.adjacentMatrix[oneStepMin.destVId].size(); i++)
		{
			Direction twoStepMin = G.adjacentMatrix[oneStepMin.destVId][i];//两步可达的最近路线
			if (dis[twoStepMin.destVId]>oneStepMin.distance + twoStepMin.distance)
				//两步达的终点一步达是否会更近（虽然不是最近的，但是比两步要近，所以起点也是到该点的最短距离
			{
				if (beenV[twoStepMin.destVId])//已经得到该点的最短路线，则不重复遍历
				{
					continue;
				}
				dis[twoStepMin.destVId] = oneStepMin.distance + twoStepMin.distance;//更新起点到该点的距离
				G.disName[twoStepMin.destVId] = oneStepMin.destName;
				G.disId[twoStepMin.destVId] = oneStepMin.destVId;
				beenV[twoStepMin.destVId] = true;
				if (twoStepMin.destVId == endV.Vid)//到达最终目标，不遍历多余的点
				{
					return dis[endV.Vid];
				}
				q.push(Direction(twoStepMin.destVId, dis[twoStepMin.destVId], twoStepMin.destName));//更新起点，开始新的旅程
			}
		}
	}
	return dis[endV.Vid];
}
void SubwayForQt::readData()
{
	ifstream in("node.txt");
	string name, pathName, source, target;
	float distance = 0;
	while (in >> name >> pathName)//载入node信息
		G.setVertex(name, pathName);
	in.close();
	in.open("links.txt");//载入link信息
	while (in >> source >> target >> pathName >> distance)
		G.setLink(source, target, pathName, distance);
	QStringList nodeName;
	for (map<string, Vertex>::iterator i = G.vertex.begin(); i != G.vertex.end(); i++)
	{
		nodeName <<  QString::fromLocal8Bit(i->first.c_str());
	}
	ui.startCombo->addItems(nodeName);
	ui.endCombo->addItems(nodeName);
	ui.startCombo->setCurrentIndex(-1);
	ui.endCombo->setCurrentIndex(-1);
	QCompleter *pCompleter1 = new QCompleter(ui.startCombo->model(), this);
	ui.startCombo->setCompleter(pCompleter1);
	QCompleter *pCompleter2 = new QCompleter(ui.startCombo->model(), this);
	ui.endCombo->setCompleter(pCompleter2);
}
string SubwayForQt::ReversePrint(Graph & G, string start, string end)
{
	string currentLine, PreLine;
	bool flag = false;
	if (end == "")
	{
		QString temp = SubwayForQt::ui.path->toPlainText();
		QString QStart = QString::fromLocal8Bit(start.c_str());
		SubwayForQt::ui.path->setText(temp + QStart +" ");
		//SubwayForQt::ui.path2->setText(temp + QStart+"->");
		//LineName.push(G.vertex.find(start)->second.pathName);//存入当前站点的线路信息
		return "start23";
	}
	else
	{
		Vertex endV = G.vertex.find(end)->second;

		//LineName.push(endV.pathName);//存入当前站点的线路信息
		PreLine = ReversePrint(G,start, G.disName[endV.Vid]);
		if (PreLine == "start23")//这是万里长征的第一步
		{
			set<string> startV = G.vertex.find(start)->second.pathName;
			for (set<string>::iterator i = startV.begin(); i != startV.end(); i++)
			{
				for (set<string>::iterator j = endV.pathName.begin(); j != endV.pathName.end(); j++)
				{
					if (*i == *j)//两点确定一条直线
					{
						currentLine = *i;
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
				QString Qtemp = SubwayForQt::ui.path->toPlainText();
				string sTemp= string((const char *)Qtemp.toLocal8Bit());
				string currentLine2 = "(换乘" + currentLine+")";
				QString QTran = QString::fromLocal8Bit(currentLine2.c_str());
				SubwayForQt::ui.path->setText(Qtemp + QTran);


				//QString Q2temp = SubwayForQt::ui.path2->toPlainText();
				//string currentLine3 = "(换乘" + currentLine + ")-> ";
				//QString QT2ran = QString::fromLocal8Bit(currentLine3.c_str());
				//SubwayForQt::ui.path2->setText(Q2temp + QT2ran);

			}
		}
		QString temp2 = SubwayForQt::ui.path->toPlainText();
		SubwayForQt::ui.path->setText(temp2 + QString::fromLocal8Bit((" ->"+end).c_str()));
		return currentLine;
	}
}
vector<string> SubwayForQt::split(const string &str, const string &pattern)
{
	vector<string> res;
	if (str == "")
		return res;
	//在字符串末尾也加入分隔符，方便截取最后一段
	string strs = str + pattern;
	size_t pos = strs.find(pattern);
	while (pos != strs.npos)
	{
		string temp = strs.substr(0, pos);
		res.push_back(temp);
		//去掉已分割的字符串,在剩下的字符串中进行分割
		strs = strs.substr(pos + 1, strs.size());
		pos = strs.find(pattern);
	}
	return res;
}
int SubwayForQt::CalCost(float distance) {
	//北京普通地铁6公里(含)内3元；6-12公里(含)4元；12-22公里(含)5元；22-32公里(含)6元；32公里以上每加1元可乘20公里。
	int result = 0;
	while (distance>1e-5)
	{
		switch ((int)floor(distance) / 6)
		{
		case 0:
			return 3;
		case 1:
			return 4;
		case 2:
		case 3:
			if (distance > 22)
				return result + 6;
			else
				return 5;
		default:
			if (distance > 32)
			{
				result += 1;
				distance -= 20;
				if (distance < 32)
					distance = 23;
			}
			else
				return result + 6;
			break;
		}
	}
	return result;
}
int SubwayForQt::spendMoney()
{
	bool Radiocheck = bg->checkedId();
	// 新建图,读入数据
	Graph M=G;
	string start, end;
	start = string((const char *)ui.startCombo->currentText().toLocal8Bit());
	end =  string((const char *)ui.endCombo->currentText().toLocal8Bit());
	if (G.vertex.find(start) == G.vertex.end())
	{
		QMessageBox::warning(NULL, "Error", u8"起点并没有地铁站哦");
		return 0;
	}
	else if (G.vertex.find(end) == G.vertex.end())
	{
		QMessageBox::warning(NULL, "Error", u8"终点并没有地铁站哦");
		return 0;
	}
	ui.path->clear();
	M.disId.clear();
	M.disName.clear();
	try
	{
		M.setAdjMatrix();//初始化稀疏邻接矩阵
		M.Overall = Dijkstra(M, start, end);
		QString a = u8"票价:" + QString("%1").arg(CalCost(M.Overall));
		QString b = u8"最短距离:" + QString("%1").arg(M.Overall);
		ui.costLabel->setText(a);
		ui.distanceLabel->setText(b);
		M.getTransfer(start, end);
		for (int i = 0; i < M.isTransfer.size(); i++)
		{
			if (*(M.isTransfer.begin() + i))
			{
				M.TranSum++;
			}
		}
		anotherPath.clear();
		if (Radiocheck)
		{
			M.getAnotherPath(start, end);
		}
		anotherPath.push_back(M);
		int min_inx = 0, min = 9999;
		for (int i = 0; i < anotherPath.size(); i++)
		{
			if (anotherPath[i].TranSum < min)
			{
				min_inx = i;
				min = anotherPath[i].TranSum;
			}
		}
		ui.path->clear();
		ReversePrint(anotherPath[min_inx],start, end);
		string allPath= string((const char *)ui.path->toPlainText().toLocal8Bit());
		string huanChengPath=start;
		vector<string> Path=split(allPath, " ");
		int continuPath = -1;
		for (int i = 1; i < Path.size()-1; i++)
		{
			if(Path[i].find("换乘")!= string::npos)
			{
				huanChengPath += "->" + to_string(continuPath)+ "站";
				huanChengPath += Path[i];
				continuPath = 0;
			}
			else
				continuPath++;

		}
		huanChengPath += "->" + to_string(continuPath) + "站";
		huanChengPath +="->"+end;
		ui.path2->setText(QString::fromLocal8Bit(huanChengPath.c_str()));
	}
	catch (...)
	{
		//cout << "票价:" << CalCost(M.Overall) << endl;
		QString a = u8"票价:" + QString("%1").arg(CalCost(M.Overall));
		QString b = u8"最短距离:" + QString("%1").arg(M.Overall);
		ui.costLabel->setText(a);
		ui.distanceLabel->setText(b);
		ui.path->clear();
		ReversePrint(M,start, end);
	}

	return 0;
}
