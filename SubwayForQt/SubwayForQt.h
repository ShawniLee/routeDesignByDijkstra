#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SubwayForQt.h"
#include"Graph.h"
#include<QMessageBox>
class SubwayForQt : public QMainWindow
{
	Q_OBJECT

public:
	SubwayForQt(QWidget *parent = Q_NULLPTR);
	int spendMoney();
	int CalCost(float distance);
	vector<string> static split(const string &str, const string &pattern);
	float static Dijkstra(Graph & G, string startName, string endName);
	void readData();
	string ReversePrint(Graph & G, string start, string end);
	Ui::SubwayForQtClass ui;
	void justClose();
private:
	

};
