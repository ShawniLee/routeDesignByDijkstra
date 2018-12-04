#include "SubwayForQt.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SubwayForQt w;
	w.show();
	return a.exec();
}
