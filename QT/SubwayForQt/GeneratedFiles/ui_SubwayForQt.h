/********************************************************************************
** Form generated from reading UI file 'SubwayForQt.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBWAYFORQT_H
#define UI_SUBWAYFORQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SubwayForQtClass
{
public:
    QWidget *centralWidget;
    QLabel *costLabel;
    QLabel *distanceLabel;
    QTextBrowser *path;
    QLabel *startLabel;
    QComboBox *startCombo;
    QComboBox *endCombo;
    QLabel *endLabel;
    QPushButton *spendButton;
    QLabel *label;
    QTextBrowser *path2;
    QLabel *label_2;
    QPushButton *close;
    QRadioButton *PathRadio;
    QRadioButton *TranRadio;

    void setupUi(QMainWindow *SubwayForQtClass)
    {
        if (SubwayForQtClass->objectName().isEmpty())
            SubwayForQtClass->setObjectName(QStringLiteral("SubwayForQtClass"));
        SubwayForQtClass->resize(831, 623);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(127, 127, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(63, 63, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(0, 0, 127, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(0, 0, 170, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        SubwayForQtClass->setPalette(palette);
        centralWidget = new QWidget(SubwayForQtClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        costLabel = new QLabel(centralWidget);
        costLabel->setObjectName(QStringLiteral("costLabel"));
        costLabel->setGeometry(QRect(360, 90, 161, 31));
        costLabel->setStyleSheet(QLatin1String("color:white;font-size:20px; \n"
"font-family:'Microsoft YaHei'"));
        distanceLabel = new QLabel(centralWidget);
        distanceLabel->setObjectName(QStringLiteral("distanceLabel"));
        distanceLabel->setGeometry(QRect(360, 150, 311, 31));
        distanceLabel->setStyleSheet(QLatin1String("color:white;font-size:20px; \n"
"font-family:'Microsoft YaHei'"));
        path = new QTextBrowser(centralWidget);
        path->setObjectName(QStringLiteral("path"));
        path->setGeometry(QRect(70, 405, 641, 81));
        path->setStyleSheet(QStringLiteral("QTextBrowser{border-width:0;border-style:outset;font-size=20px}"));
        startLabel = new QLabel(centralWidget);
        startLabel->setObjectName(QStringLiteral("startLabel"));
        startLabel->setGeometry(QRect(30, 120, 91, 21));
        startLabel->setStyleSheet(QLatin1String("color:white;font-size:20px; \n"
"font-family:'Microsoft YaHei'"));
        startCombo = new QComboBox(centralWidget);
        startCombo->setObjectName(QStringLiteral("startCombo"));
        startCombo->setGeometry(QRect(130, 120, 141, 22));
        startCombo->setStyleSheet(QLatin1String("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 3px;\n"
"    padding: 1px 2px 1px 2px; \n"
"    min-width: 9em;  \n"
"}"));
        startCombo->setEditable(true);
        endCombo = new QComboBox(centralWidget);
        endCombo->setObjectName(QStringLiteral("endCombo"));
        endCombo->setGeometry(QRect(130, 190, 141, 22));
        endCombo->setStyleSheet(QLatin1String("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 3px;\n"
"    padding: 1px 2px 1px 2px; \n"
"    min-width: 9em;  \n"
"}"));
        endCombo->setEditable(true);
        endLabel = new QLabel(centralWidget);
        endLabel->setObjectName(QStringLiteral("endLabel"));
        endLabel->setGeometry(QRect(31, 190, 71, 21));
        endLabel->setStyleSheet(QLatin1String("color:white;font-size:20px; \n"
"font-family:'Microsoft YaHei'"));
        spendButton = new QPushButton(centralWidget);
        spendButton->setObjectName(QStringLiteral("spendButton"));
        spendButton->setGeometry(QRect(90, 260, 93, 28));
        QPalette palette1;
        QBrush brush8(QColor(102, 102, 102, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush8);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush8);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush8);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        spendButton->setPalette(palette1);
        spendButton->setStyleSheet(QStringLiteral("QPushButton{ font-family:'Microsoft YaHei';font-size:14px;color:#666666;}"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 370, 121, 21));
        label->setStyleSheet(QLatin1String("color:white;font-size:20px; \n"
"font-family:'Microsoft YaHei'"));
        path2 = new QTextBrowser(centralWidget);
        path2->setObjectName(QStringLiteral("path2"));
        path2->setGeometry(QRect(360, 256, 351, 81));
        path2->setStyleSheet(QStringLiteral("QTextBrowser{border-width:0;border-style:outset;font-size=20px}"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(360, 220, 111, 31));
        label_2->setStyleSheet(QStringLiteral("color:white;font-size:20px;"));
        close = new QPushButton(centralWidget);
        close->setObjectName(QStringLiteral("close"));
        close->setGeometry(QRect(220, 260, 93, 28));
        close->setStyleSheet(QStringLiteral("QPushButton{ font-family:'Microsoft YaHei';font-size:14px;color:#666666;}"));
        PathRadio = new QRadioButton(centralWidget);
        PathRadio->setObjectName(QStringLiteral("PathRadio"));
        PathRadio->setGeometry(QRect(390, 360, 115, 19));
        PathRadio->setStyleSheet(QStringLiteral("color:white;font-size:20px;"));
        TranRadio = new QRadioButton(centralWidget);
        TranRadio->setObjectName(QStringLiteral("TranRadio"));
        TranRadio->setGeometry(QRect(560, 360, 115, 19));
        TranRadio->setStyleSheet(QStringLiteral("color:white;font-size:20px;"));
        SubwayForQtClass->setCentralWidget(centralWidget);

        retranslateUi(SubwayForQtClass);

        QMetaObject::connectSlotsByName(SubwayForQtClass);
    } // setupUi

    void retranslateUi(QMainWindow *SubwayForQtClass)
    {
        SubwayForQtClass->setWindowTitle(QApplication::translate("SubwayForQtClass", "SubwayForQt", nullptr));
        costLabel->setText(QApplication::translate("SubwayForQtClass", "\350\264\271\347\224\250\357\274\232", nullptr));
        distanceLabel->setText(QApplication::translate("SubwayForQtClass", "\350\267\235\347\246\273\357\274\232", nullptr));
        startLabel->setText(QApplication::translate("SubwayForQtClass", "\350\265\267\345\247\213\347\253\231:", nullptr));
        endLabel->setText(QApplication::translate("SubwayForQtClass", "\347\273\210\347\202\271\347\253\231:", nullptr));
        spendButton->setText(QApplication::translate("SubwayForQtClass", "\350\256\241\347\256\227", nullptr));
        label->setText(QApplication::translate("SubwayForQtClass", "\350\257\246\347\273\206\350\267\257\347\272\277\357\274\232", nullptr));
        label_2->setText(QApplication::translate("SubwayForQtClass", "\346\234\200\345\260\217\346\215\242\344\271\230\357\274\232", nullptr));
        close->setText(QApplication::translate("SubwayForQtClass", "\345\205\263\351\227\255", nullptr));
        PathRadio->setText(QApplication::translate("SubwayForQtClass", "\346\234\200\347\237\255\350\267\257\345\276\204", nullptr));
        TranRadio->setText(QApplication::translate("SubwayForQtClass", "\346\234\200\345\260\217\346\215\242\344\271\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SubwayForQtClass: public Ui_SubwayForQtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBWAYFORQT_H
