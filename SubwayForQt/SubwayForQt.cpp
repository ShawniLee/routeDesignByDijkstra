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
	bg->addButton(ui.PathRadio, false);//һ��ֵΪ0
	bg->addButton(ui.TranRadio, true);//һ��ֵΪ1
	this->setWindowIcon(QIcon("subway.png"));
	//this->setAttribute(Qt::WA_TranslucentBackground, true);
	this->setWindowFlags(Qt::FramelessWindowHint);//ȥ��������
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
	//���ȶ���
	priority_queue<Direction> q;
	for (vector<Direction>::iterator i = G.adjacentMatrix[startV.Vid].begin(); i != G.adjacentMatrix[startV.Vid].end(); i++)
		q.push(Direction(i->destVId, i->distance, i->destName));//����һ�������п����Է������
	while (!q.empty())
	{
		Direction oneStepMin = q.top(); //��һ���ɴ�����·��
		q.pop();
		dis[oneStepMin.destVId] = oneStepMin.distance;
		beenV[oneStepMin.destVId] = true;
		if (oneStepMin.destVId == endV.Vid)//��������Ŀ�꣬����������ĵ�
		{
			return dis[endV.Vid];
		}
		for (i = 0; i<G.adjacentMatrix[oneStepMin.destVId].size(); i++)
		{
			Direction twoStepMin = G.adjacentMatrix[oneStepMin.destVId][i];//�����ɴ�����·��
			if (dis[twoStepMin.destVId]>oneStepMin.distance + twoStepMin.distance)
				//��������յ�һ�����Ƿ���������Ȼ��������ģ����Ǳ�����Ҫ�����������Ҳ�ǵ��õ����̾���
			{
				if (beenV[twoStepMin.destVId])//�Ѿ��õ��õ�����·�ߣ����ظ�����
				{
					continue;
				}
				dis[twoStepMin.destVId] = oneStepMin.distance + twoStepMin.distance;//������㵽�õ�ľ���
				G.disName[twoStepMin.destVId] = oneStepMin.destName;
				G.disId[twoStepMin.destVId] = oneStepMin.destVId;
				beenV[twoStepMin.destVId] = true;
				if (twoStepMin.destVId == endV.Vid)//��������Ŀ�꣬����������ĵ�
				{
					return dis[endV.Vid];
				}
				q.push(Direction(twoStepMin.destVId, dis[twoStepMin.destVId], twoStepMin.destName));//������㣬��ʼ�µ��ó�
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
	while (in >> name >> pathName)//����node��Ϣ
		G.setVertex(name, pathName);
	in.close();
	in.open("links.txt");//����link��Ϣ
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
		//LineName.push(G.vertex.find(start)->second.pathName);//���뵱ǰվ�����·��Ϣ
		return "start23";
	}
	else
	{
		Vertex endV = G.vertex.find(end)->second;

		//LineName.push(endV.pathName);//���뵱ǰվ�����·��Ϣ
		PreLine = ReversePrint(G,start, G.disName[endV.Vid]);
		if (PreLine == "start23")//�������ﳤ���ĵ�һ��
		{
			set<string> startV = G.vertex.find(start)->second.pathName;
			for (set<string>::iterator i = startV.begin(); i != startV.end(); i++)
			{
				for (set<string>::iterator j = endV.pathName.begin(); j != endV.pathName.end(); j++)
				{
					if (*i == *j)//����ȷ��һ��ֱ��
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
				if (PreLine == *j)//���һ�����������
				{
					currentLine = *j;
					flag = true;
				}
			}
			if (flag == false)//�����ǲ���Ӧ�û����ˣ���һվ��
			{

				currentLine = *endV.pathName.begin();
				QString Qtemp = SubwayForQt::ui.path->toPlainText();
				string sTemp= string((const char *)Qtemp.toLocal8Bit());
				string currentLine2 = "(����" + currentLine+")";
				QString QTran = QString::fromLocal8Bit(currentLine2.c_str());
				SubwayForQt::ui.path->setText(Qtemp + QTran);


				//QString Q2temp = SubwayForQt::ui.path2->toPlainText();
				//string currentLine3 = "(����" + currentLine + ")-> ";
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
	//���ַ���ĩβҲ����ָ����������ȡ���һ��
	string strs = str + pattern;
	size_t pos = strs.find(pattern);
	while (pos != strs.npos)
	{
		string temp = strs.substr(0, pos);
		res.push_back(temp);
		//ȥ���ѷָ���ַ���,��ʣ�µ��ַ����н��зָ�
		strs = strs.substr(pos + 1, strs.size());
		pos = strs.find(pattern);
	}
	return res;
}
int SubwayForQt::CalCost(float distance) {
	//������ͨ����6����(��)��3Ԫ��6-12����(��)4Ԫ��12-22����(��)5Ԫ��22-32����(��)6Ԫ��32��������ÿ��1Ԫ�ɳ�20���
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
	// �½�ͼ,��������
	Graph M=G;
	string start, end;
	start = string((const char *)ui.startCombo->currentText().toLocal8Bit());
	end =  string((const char *)ui.endCombo->currentText().toLocal8Bit());
	if (G.vertex.find(start) == G.vertex.end())
	{
		QMessageBox::warning(NULL, "Error", u8"��㲢û�е���վŶ");
		return 0;
	}
	else if (G.vertex.find(end) == G.vertex.end())
	{
		QMessageBox::warning(NULL, "Error", u8"�յ㲢û�е���վŶ");
		return 0;
	}
	ui.path->clear();
	M.disId.clear();
	M.disName.clear();
	try
	{
		M.setAdjMatrix();//��ʼ��ϡ���ڽӾ���
		M.Overall = Dijkstra(M, start, end);
		QString a = u8"Ʊ��:" + QString("%1").arg(CalCost(M.Overall));
		QString b = u8"��̾���:" + QString("%1").arg(M.Overall);
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
			if(Path[i].find("����")!= string::npos)
			{
				huanChengPath += "->" + to_string(continuPath)+ "վ";
				huanChengPath += Path[i];
				continuPath = 0;
			}
			else
				continuPath++;

		}
		huanChengPath += "->" + to_string(continuPath) + "վ";
		huanChengPath +="->"+end;
		ui.path2->setText(QString::fromLocal8Bit(huanChengPath.c_str()));
	}
	catch (...)
	{
		//cout << "Ʊ��:" << CalCost(M.Overall) << endl;
		QString a = u8"Ʊ��:" + QString("%1").arg(CalCost(M.Overall));
		QString b = u8"��̾���:" + QString("%1").arg(M.Overall);
		ui.costLabel->setText(a);
		ui.distanceLabel->setText(b);
		ui.path->clear();
		ReversePrint(M,start, end);
	}

	return 0;
}
