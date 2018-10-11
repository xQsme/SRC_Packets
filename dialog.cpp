#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->buttonBox->setCenterButtons(true);
    foreach(QNetworkInterface netInterface, QNetworkInterface::allInterfaces())
    {
        // Return only the first non-loopback MAC Address
        if (!(netInterface.flags() & QNetworkInterface::IsLoopBack))
        {
            ui->lineEditMac->setText(netInterface.hardwareAddress());
            return;
        }
    }
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setStuff(pcpp::Packet* packet, pcpp::PcapLiveDevice* dev)
{
    this->packet=packet;
    this->dev=dev;
    ui->textEdit->setText(QString::fromStdString(packet->toString()));
}

void Dialog::on_buttonBox_accepted()
{
    if (!dev->sendPacket(packet))
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Error");
        msgBox.setText("Could not send packet!");
        msgBox.exec();
    }else{
        QMessageBox msgBox;
        msgBox.setWindowTitle("Success");
        msgBox.setText("Packet sent!");
        msgBox.exec();
    }
}
