#pragma once

#include <QPushButton>
#include<QMenu>
#include<QWidgetAction>
#include<QLabel>
class QTDropDownButton : public QPushButton
{
	Q_OBJECT
public:
	QTDropDownButton(QString text, QWidget *parent = nullptr);

	void addItem(QString text);

	protected slots:
	void menuAboutToShow();
	void menuTriggered(QAction *action);

private:
	QMenu * menu_;
};