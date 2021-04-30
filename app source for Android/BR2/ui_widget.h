/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_3;
    QListWidget *list;
    QTextBrowser *textBrowser_info;
    QPushButton *pushButton_disconnect;
    QPushButton *pushButton_openBluetooth;
    QPushButton *pushButton_scan;
    QPushButton *pushButton_closeDevice;
    QPushButton *pushButton_send;
    QPushButton *pushButton_clear;
    QCheckBox *checkBox_discoverable;
    QWidget *tab_2;
    QGridLayout *gridLayout;
    QPushButton *pushButton_fr;
    QPushButton *pushButtonTurnMode;
    QPushButton *pushButtonRight;
    QPushButton *pushButtonForward;
    QLineEdit *lineEdit_16;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_13;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *lineEdit_9;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonMode;
    QPushButton *pushButtonLeft;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_br;
    QLineEdit *lineEdit_5;
    QSpacerItem *verticalSpacer;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_12;
    QSpacerItem *verticalSpacer_4;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_11;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_17;
    QLineEdit *lineEdit_18;
    QSpacerItem *verticalSpacer_3;
    QPushButton *pushButton_fl;
    QPushButton *pushButtonBackward;
    QLineEdit *lineEdit_14;
    QLineEdit *lineEdit_15;
    QLineEdit *lineEdit_1;
    QPushButton *pushButton_bl;
    QSlider *horizontalSliderSpeed;
    QLabel *label;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(622, 802);
        gridLayout_2 = new QGridLayout(Widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_3 = new QGridLayout(tab);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        list = new QListWidget(tab);
        list->setObjectName(QStringLiteral("list"));

        gridLayout_3->addWidget(list, 0, 0, 1, 2);

        textBrowser_info = new QTextBrowser(tab);
        textBrowser_info->setObjectName(QStringLiteral("textBrowser_info"));

        gridLayout_3->addWidget(textBrowser_info, 1, 0, 1, 2);

        pushButton_disconnect = new QPushButton(tab);
        pushButton_disconnect->setObjectName(QStringLiteral("pushButton_disconnect"));

        gridLayout_3->addWidget(pushButton_disconnect, 2, 0, 1, 1);

        pushButton_openBluetooth = new QPushButton(tab);
        pushButton_openBluetooth->setObjectName(QStringLiteral("pushButton_openBluetooth"));

        gridLayout_3->addWidget(pushButton_openBluetooth, 2, 1, 1, 1);

        pushButton_scan = new QPushButton(tab);
        pushButton_scan->setObjectName(QStringLiteral("pushButton_scan"));

        gridLayout_3->addWidget(pushButton_scan, 3, 0, 1, 1);

        pushButton_closeDevice = new QPushButton(tab);
        pushButton_closeDevice->setObjectName(QStringLiteral("pushButton_closeDevice"));

        gridLayout_3->addWidget(pushButton_closeDevice, 3, 1, 1, 1);

        pushButton_send = new QPushButton(tab);
        pushButton_send->setObjectName(QStringLiteral("pushButton_send"));

        gridLayout_3->addWidget(pushButton_send, 4, 0, 1, 1);

        pushButton_clear = new QPushButton(tab);
        pushButton_clear->setObjectName(QStringLiteral("pushButton_clear"));

        gridLayout_3->addWidget(pushButton_clear, 4, 1, 1, 1);

        checkBox_discoverable = new QCheckBox(tab);
        checkBox_discoverable->setObjectName(QStringLiteral("checkBox_discoverable"));

        gridLayout_3->addWidget(checkBox_discoverable, 5, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout = new QGridLayout(tab_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_fr = new QPushButton(tab_2);
        pushButton_fr->setObjectName(QStringLiteral("pushButton_fr"));

        gridLayout->addWidget(pushButton_fr, 6, 4, 1, 1);

        pushButtonTurnMode = new QPushButton(tab_2);
        pushButtonTurnMode->setObjectName(QStringLiteral("pushButtonTurnMode"));

        gridLayout->addWidget(pushButtonTurnMode, 12, 3, 1, 1);

        pushButtonRight = new QPushButton(tab_2);
        pushButtonRight->setObjectName(QStringLiteral("pushButtonRight"));

        gridLayout->addWidget(pushButtonRight, 8, 4, 1, 1);

        pushButtonForward = new QPushButton(tab_2);
        pushButtonForward->setObjectName(QStringLiteral("pushButtonForward"));

        gridLayout->addWidget(pushButtonForward, 6, 3, 1, 1);

        lineEdit_16 = new QLineEdit(tab_2);
        lineEdit_16->setObjectName(QStringLiteral("lineEdit_16"));

        gridLayout->addWidget(lineEdit_16, 19, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 8, 5, 1, 1);

        lineEdit_10 = new QLineEdit(tab_2);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));

        gridLayout->addWidget(lineEdit_10, 16, 2, 1, 1);

        lineEdit_13 = new QLineEdit(tab_2);
        lineEdit_13->setObjectName(QStringLiteral("lineEdit_13"));

        gridLayout->addWidget(lineEdit_13, 18, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 5, 3, 1, 1);

        lineEdit_9 = new QLineEdit(tab_2);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));

        gridLayout->addWidget(lineEdit_9, 3, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 8, 0, 1, 1);

        pushButtonMode = new QPushButton(tab_2);
        pushButtonMode->setObjectName(QStringLiteral("pushButtonMode"));

        gridLayout->addWidget(pushButtonMode, 12, 4, 1, 1);

        pushButtonLeft = new QPushButton(tab_2);
        pushButtonLeft->setObjectName(QStringLiteral("pushButtonLeft"));

        gridLayout->addWidget(pushButtonLeft, 8, 2, 1, 1);

        lineEdit_7 = new QLineEdit(tab_2);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));

        gridLayout->addWidget(lineEdit_7, 3, 2, 1, 1);

        lineEdit_8 = new QLineEdit(tab_2);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));

        gridLayout->addWidget(lineEdit_8, 3, 3, 1, 1);

        lineEdit_2 = new QLineEdit(tab_2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 1, 2, 1, 1);

        pushButton_br = new QPushButton(tab_2);
        pushButton_br->setObjectName(QStringLiteral("pushButton_br"));

        gridLayout->addWidget(pushButton_br, 9, 4, 1, 1);

        lineEdit_5 = new QLineEdit(tab_2);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        gridLayout->addWidget(lineEdit_5, 2, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 8, 3, 1, 1);

        lineEdit_3 = new QLineEdit(tab_2);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 1, 4, 1, 1);

        lineEdit_12 = new QLineEdit(tab_2);
        lineEdit_12->setObjectName(QStringLiteral("lineEdit_12"));

        gridLayout->addWidget(lineEdit_12, 16, 4, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 10, 3, 1, 1);

        lineEdit_6 = new QLineEdit(tab_2);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        gridLayout->addWidget(lineEdit_6, 2, 4, 1, 1);

        lineEdit_11 = new QLineEdit(tab_2);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));

        gridLayout->addWidget(lineEdit_11, 16, 3, 1, 1);

        lineEdit_4 = new QLineEdit(tab_2);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 2, 2, 1, 1);

        lineEdit_17 = new QLineEdit(tab_2);
        lineEdit_17->setObjectName(QStringLiteral("lineEdit_17"));

        gridLayout->addWidget(lineEdit_17, 19, 3, 1, 1);

        lineEdit_18 = new QLineEdit(tab_2);
        lineEdit_18->setObjectName(QStringLiteral("lineEdit_18"));

        gridLayout->addWidget(lineEdit_18, 19, 4, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_3, 14, 3, 1, 1);

        pushButton_fl = new QPushButton(tab_2);
        pushButton_fl->setObjectName(QStringLiteral("pushButton_fl"));

        gridLayout->addWidget(pushButton_fl, 6, 2, 1, 1);

        pushButtonBackward = new QPushButton(tab_2);
        pushButtonBackward->setObjectName(QStringLiteral("pushButtonBackward"));

        gridLayout->addWidget(pushButtonBackward, 9, 3, 1, 1);

        lineEdit_14 = new QLineEdit(tab_2);
        lineEdit_14->setObjectName(QStringLiteral("lineEdit_14"));

        gridLayout->addWidget(lineEdit_14, 18, 3, 1, 1);

        lineEdit_15 = new QLineEdit(tab_2);
        lineEdit_15->setObjectName(QStringLiteral("lineEdit_15"));

        gridLayout->addWidget(lineEdit_15, 18, 4, 1, 1);

        lineEdit_1 = new QLineEdit(tab_2);
        lineEdit_1->setObjectName(QStringLiteral("lineEdit_1"));

        gridLayout->addWidget(lineEdit_1, 1, 3, 1, 1);

        pushButton_bl = new QPushButton(tab_2);
        pushButton_bl->setObjectName(QStringLiteral("pushButton_bl"));

        gridLayout->addWidget(pushButton_bl, 9, 2, 1, 1);

        horizontalSliderSpeed = new QSlider(tab_2);
        horizontalSliderSpeed->setObjectName(QStringLiteral("horizontalSliderSpeed"));
        horizontalSliderSpeed->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSliderSpeed, 12, 2, 1, 1);

        label = new QLabel(tab_2);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 11, 2, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout_2->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(Widget);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        textBrowser_info->setHtml(QApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Bluetooth</p></body></html>", nullptr));
        pushButton_disconnect->setText(QApplication::translate("Widget", "\346\226\255\345\274\200", nullptr));
        pushButton_openBluetooth->setText(QApplication::translate("Widget", "\346\211\223\345\274\200", nullptr));
        pushButton_scan->setText(QApplication::translate("Widget", "\346\211\253\346\217\217", nullptr));
        pushButton_closeDevice->setText(QApplication::translate("Widget", "\345\205\263\351\227\255", nullptr));
        pushButton_send->setText(QApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
        pushButton_clear->setText(QApplication::translate("Widget", "\346\270\205\351\231\244", nullptr));
        checkBox_discoverable->setText(QApplication::translate("Widget", "\345\217\257\350\247\201\346\200\247", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Widget", "BlueTooth", nullptr));
        pushButton_fr->setText(QApplication::translate("Widget", "\345\257\271\350\247\222", nullptr));
        pushButtonTurnMode->setText(QApplication::translate("Widget", "\345\271\263\347\247\273", nullptr));
        pushButtonRight->setText(QApplication::translate("Widget", "\345\217\263\350\275\254", nullptr));
        pushButtonForward->setText(QApplication::translate("Widget", "\345\211\215\350\277\233", nullptr));
        pushButtonMode->setText(QApplication::translate("Widget", "\351\201\245\346\216\247\346\250\241\345\274\217", nullptr));
        pushButtonLeft->setText(QApplication::translate("Widget", "\345\267\246\350\275\254", nullptr));
        pushButton_br->setText(QApplication::translate("Widget", "\345\257\271\350\247\222", nullptr));
        pushButton_fl->setText(QApplication::translate("Widget", "\345\257\271\350\247\222", nullptr));
        pushButtonBackward->setText(QApplication::translate("Widget", "\345\220\216\351\200\200", nullptr));
        pushButton_bl->setText(QApplication::translate("Widget", "\345\257\271\350\247\222", nullptr));
        label->setText(QApplication::translate("Widget", "speed:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Widget", "Console", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
