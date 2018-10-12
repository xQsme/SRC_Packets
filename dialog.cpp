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
        if (!(netInterface.flags() & QNetworkInterface::IsLoopBack))
        {
            ui->lineEditMac->setText(netInterface.hardwareAddress());
            srcMAC=netInterface.hardwareAddress().toStdString();
            break;
        }
    }
    foreach (const QHostAddress &address, QNetworkInterface::allAddresses())
    {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != QHostAddress(QHostAddress::LocalHost))
        {
            srcIP=address.toString().toStdString();
            break;
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

    ethernetLayer = packet->getLayerOfType<pcpp::EthLayer>();
    ethernetLayer->setDestMac(pcpp::MacAddress(ui->lineEditMac->text().toStdString()));
    ethernetLayer->setSourceMac(pcpp::MacAddress(srcMAC));

    ipLayer = packet->getLayerOfType<pcpp::IPv4Layer>();
    ipLayer->setDstIpAddress(pcpp::IPv4Address(ui->lineEditIP->text().toStdString()));
    ipLayer->setSrcIpAddress(pcpp::IPv4Address(srcIP));

    tcpLayer = packet->getLayerOfType<pcpp::TcpLayer>();
    tcpLayer->getTcpHeader()->portSrc = htons(1337);
    tcpLayer->getTcpHeader()->portDst = htons(ui->lineEditPort->text().toInt());

    ui->textEdit->setText(QString::fromStdString(packet->toString()));
    this->set=true;
}

void Dialog::on_buttonBox_accepted()
{
    if (!dev->sendPacket(packet))
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Error");
        msgBox.setText("Could not send packet!");
        msgBox.exec();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Success");
        msgBox.setText("Packet sent!");
        msgBox.exec();
    }
}

void Dialog::on_lineEditPort_textChanged(const QString &arg1)
{
    if(set)
    {
        tcpLayer->getTcpHeader()->portDst = htons(ui->lineEditPort->text().toInt());
        ui->textEdit->setText(QString::fromStdString(packet->toString()));
    }
}

void Dialog::on_lineEditMac_textChanged(const QString &arg1)
{
    if(set)
    {
        ethernetLayer->setDestMac(pcpp::MacAddress(ui->lineEditMac->text().toStdString()));
        ui->textEdit->setText(QString::fromStdString(packet->toString()));
    }
}

void Dialog::on_lineEditIP_textChanged(const QString &arg1)
{
    if(set)
    {
        ipLayer->setDstIpAddress(pcpp::IPv4Address(ui->lineEditIP->text().toStdString()));
        ui->textEdit->setText(QString::fromStdString(packet->toString()));
    }
}
