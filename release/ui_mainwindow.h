/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
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
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *buttonCapture;
    QSpacerItem *horizontalSpacer_5;
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
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_8 = new QHBoxLayout(centralWidget);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer_2 = new QSpacerItem(288, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_7->addWidget(label);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_7->addWidget(lineEdit);

        buttonCapture = new QPushButton(centralWidget);
        buttonCapture->setObjectName(QStringLiteral("buttonCapture"));

        horizontalLayout_7->addWidget(buttonCapture);

        horizontalSpacer_5 = new QSpacerItem(287, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_7);

        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        checkIP = new QCheckBox(centralWidget);
        checkIP->setObjectName(QStringLiteral("checkIP"));
        checkIP->setChecked(true);

        horizontalLayout_4->addWidget(checkIP);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_4->addWidget(label_2);

        editIp = new QLineEdit(centralWidget);
        editIp->setObjectName(QStringLiteral("editIp"));

        horizontalLayout_4->addWidget(editIp);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        checkMac = new QCheckBox(centralWidget);
        checkMac->setObjectName(QStringLiteral("checkMac"));
        checkMac->setChecked(true);

        horizontalLayout_3->addWidget(checkMac);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        editMac = new QLineEdit(centralWidget);
        editMac->setObjectName(QStringLiteral("editMac"));

        horizontalLayout_3->addWidget(editMac);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        checkPort = new QCheckBox(centralWidget);
        checkPort->setObjectName(QStringLiteral("checkPort"));
        checkPort->setChecked(true);

        horizontalLayout_2->addWidget(checkPort);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        editPort = new QLineEdit(centralWidget);
        editPort->setObjectName(QStringLiteral("editPort"));

        horizontalLayout_2->addWidget(editPort);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        checkTtl = new QCheckBox(centralWidget);
        checkTtl->setObjectName(QStringLiteral("checkTtl"));
        checkTtl->setChecked(true);

        horizontalLayout->addWidget(checkTtl);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout->addWidget(label_5);

        editTTL = new QLineEdit(centralWidget);
        editTTL->setObjectName(QStringLiteral("editTTL"));

        horizontalLayout->addWidget(editTTL);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        checkFlag = new QCheckBox(centralWidget);
        checkFlag->setObjectName(QStringLiteral("checkFlag"));
        checkFlag->setMaximumSize(QSize(30, 16777215));
        checkFlag->setChecked(true);

        horizontalLayout_6->addWidget(checkFlag);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_6->addWidget(label_6);

        comboFlag = new QComboBox(centralWidget);
        comboFlag->setObjectName(QStringLiteral("comboFlag"));
        comboFlag->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);

        horizontalLayout_6->addWidget(comboFlag);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        buttonOutput = new QPushButton(centralWidget);
        buttonOutput->setObjectName(QStringLiteral("buttonOutput"));

        horizontalLayout_5->addWidget(buttonOutput);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        checkTCP = new QCheckBox(centralWidget);
        checkTCP->setObjectName(QStringLiteral("checkTCP"));

        horizontalLayout_5->addWidget(checkTCP);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        checkUDP = new QCheckBox(centralWidget);
        checkUDP->setObjectName(QStringLiteral("checkUDP"));
        checkUDP->setChecked(true);

        horizontalLayout_5->addWidget(checkUDP);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        buttonEdit = new QPushButton(centralWidget);
        buttonEdit->setObjectName(QStringLiteral("buttonEdit"));

        horizontalLayout_5->addWidget(buttonEdit);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_5);


        horizontalLayout_8->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
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
