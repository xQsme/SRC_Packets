/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_8;
    QComboBox *comboBoxInterface;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *buttonCapture;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *checkIP;
    QLabel *label_2;
    QLineEdit *editIp;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *checkMac;
    QLabel *label_3;
    QLineEdit *editMac;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkPort;
    QLabel *label_4;
    QLineEdit *editPort;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkTtl;
    QLabel *label_5;
    QLineEdit *editTTL;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *checkFlag;
    QLabel *label_6;
    QComboBox *comboFlag;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *buttonOutput;
    QSpacerItem *horizontalSpacer_6;
    QCheckBox *checkTCP;
    QSpacerItem *horizontalSpacer_7;
    QCheckBox *checkUDP;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonEdit;
    QSpacerItem *horizontalSpacer_3;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_8 = new QHBoxLayout(centralWidget);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_7->addWidget(pushButton);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_7->addWidget(pushButton_2);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_8);

        comboBoxInterface = new QComboBox(centralWidget);
        comboBoxInterface->setObjectName(QString::fromUtf8("comboBoxInterface"));

        horizontalLayout_7->addWidget(comboBoxInterface);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_7->addWidget(label);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_7->addWidget(lineEdit);

        buttonCapture = new QPushButton(centralWidget);
        buttonCapture->setObjectName(QString::fromUtf8("buttonCapture"));

        horizontalLayout_7->addWidget(buttonCapture);


        verticalLayout->addLayout(horizontalLayout_7);

        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        checkIP = new QCheckBox(centralWidget);
        checkIP->setObjectName(QString::fromUtf8("checkIP"));
        checkIP->setChecked(true);

        horizontalLayout_4->addWidget(checkIP);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        editIp = new QLineEdit(centralWidget);
        editIp->setObjectName(QString::fromUtf8("editIp"));

        horizontalLayout_4->addWidget(editIp);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        checkMac = new QCheckBox(centralWidget);
        checkMac->setObjectName(QString::fromUtf8("checkMac"));
        checkMac->setChecked(true);

        horizontalLayout_3->addWidget(checkMac);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        editMac = new QLineEdit(centralWidget);
        editMac->setObjectName(QString::fromUtf8("editMac"));

        horizontalLayout_3->addWidget(editMac);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        checkPort = new QCheckBox(centralWidget);
        checkPort->setObjectName(QString::fromUtf8("checkPort"));
        checkPort->setChecked(true);

        horizontalLayout_2->addWidget(checkPort);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        editPort = new QLineEdit(centralWidget);
        editPort->setObjectName(QString::fromUtf8("editPort"));

        horizontalLayout_2->addWidget(editPort);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        checkTtl = new QCheckBox(centralWidget);
        checkTtl->setObjectName(QString::fromUtf8("checkTtl"));
        checkTtl->setChecked(true);

        horizontalLayout->addWidget(checkTtl);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout->addWidget(label_5);

        editTTL = new QLineEdit(centralWidget);
        editTTL->setObjectName(QString::fromUtf8("editTTL"));

        horizontalLayout->addWidget(editTTL);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        checkFlag = new QCheckBox(centralWidget);
        checkFlag->setObjectName(QString::fromUtf8("checkFlag"));
        checkFlag->setMaximumSize(QSize(30, 16777215));
        checkFlag->setChecked(true);

        horizontalLayout_6->addWidget(checkFlag);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        comboFlag = new QComboBox(centralWidget);
        comboFlag->setObjectName(QString::fromUtf8("comboFlag"));
        comboFlag->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);

        horizontalLayout_6->addWidget(comboFlag);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        buttonOutput = new QPushButton(centralWidget);
        buttonOutput->setObjectName(QString::fromUtf8("buttonOutput"));

        horizontalLayout_5->addWidget(buttonOutput);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        checkTCP = new QCheckBox(centralWidget);
        checkTCP->setObjectName(QString::fromUtf8("checkTCP"));

        horizontalLayout_5->addWidget(checkTCP);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        checkUDP = new QCheckBox(centralWidget);
        checkUDP->setObjectName(QString::fromUtf8("checkUDP"));
        checkUDP->setChecked(true);

        horizontalLayout_5->addWidget(checkUDP);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        buttonEdit = new QPushButton(centralWidget);
        buttonEdit->setObjectName(QString::fromUtf8("buttonEdit"));

        horizontalLayout_5->addWidget(buttonEdit);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_5);


        horizontalLayout_8->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Create Raw UDP Packet", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Clear Packets", nullptr));
        label->setText(QApplication::translate("MainWindow", "Duration", nullptr));
        lineEdit->setText(QApplication::translate("MainWindow", "5", nullptr));
        buttonCapture->setText(QApplication::translate("MainWindow", "Capture", nullptr));
        checkIP->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Destination IP", nullptr));
        checkMac->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Destination Mac Adress", nullptr));
        checkPort->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "Destination Port", nullptr));
        editPort->setText(QApplication::translate("MainWindow", "80", nullptr));
        checkTtl->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "Time to Live", nullptr));
        editTTL->setText(QApplication::translate("MainWindow", "12", nullptr));
        checkFlag->setText(QString());
        label_6->setText(QApplication::translate("MainWindow", "Flag Urgent", nullptr));
        buttonOutput->setText(QApplication::translate("MainWindow", "Output File", nullptr));
        checkTCP->setText(QApplication::translate("MainWindow", "TCP", nullptr));
        checkUDP->setText(QApplication::translate("MainWindow", "UDP", nullptr));
        buttonEdit->setText(QApplication::translate("MainWindow", "Edit and Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
