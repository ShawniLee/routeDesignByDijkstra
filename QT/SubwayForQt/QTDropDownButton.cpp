#include "QTDropDownButton.h"


QTDropDownButton::QTDropDownButton(QString text, QWidget *parent) :
	QPushButton(text, parent)
{
	setFlat(true);
	menu_ = new QMenu();
	setMenu(menu_);

	connect(menu_, SIGNAL(aboutToShow()), this, SLOT(menuAboutToShow()));
	connect(menu_, SIGNAL(triggered(QAction*)), this, SLOT(menuTriggered(QAction*)));

	setStyleSheet("QPushButton {text-align: left; font-family: Arial; font-size: 13pt; color: #808080; border: 1px solid gray; padding: 5px;}"
		"QPushButton::menu-indicator {subcontrol-origin: padding; subcontrol-position: right center; right:5px;}");
	menu_->setStyleSheet("QLabel {font-family: Arial; font-size: 13pt; padding: 5px 0 5px 0; background-color: transparent;}"
		"QLabel:hover {background-color: rgb(51, 153, 255);}");
}

void QTDropDownButton::addItem(QString text)
{
	if (!menu_)
		return;

	QWidgetAction* wa1 = new QWidgetAction(menu_);
	QLabel* l1 = new QLabel(text);
	wa1->setDefaultWidget(l1);
	menu_->addAction(wa1);
}

void QTDropDownButton::menuAboutToShow()
{
	if (menu_)
	{
		menu_->setFixedWidth(this->width());
	}
}

void QTDropDownButton::menuTriggered(QAction *action)
{
	if (!action)
		return;

	QWidgetAction* qwa = dynamic_cast<QWidgetAction*>(action);
	if (!qwa)
		return;

	QLabel* ql = dynamic_cast<QLabel*>(qwa->defaultWidget());
	if (!ql)
		return;

	setText(ql->text());
}