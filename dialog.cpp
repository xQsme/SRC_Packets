#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
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

void Dialog::setStuff(pcpp::Packet* packet, pcpp::PcapLiveDevice* dev, QString type)
{
    this->packet=packet;
    this->dev=dev;
    this->type=type;

    ethernetLayer = packet->getLayerOfType<pcpp::EthLayer>();
    ethernetLayer->setDestMac(pcpp::MacAddress(ui->lineEditMac->text().toStdString()));
    ethernetLayer->setSourceMac(pcpp::MacAddress(srcMAC));

    ipLayer = packet->getLayerOfType<pcpp::IPv4Layer>();
    ipLayer->setDstIpAddress(pcpp::IPv4Address(ui->lineEditIP->text().toStdString()));
    ipLayer->setSrcIpAddress(pcpp::IPv4Address(srcIP));
    ipLayer->getIPv4Header()->ipId = htons(4000);
    ipLayer->getIPv4Header()->timeToLive = 12;

    if(type == "UDP")
    {
        udpLayer = packet->getLayerOfType<pcpp::UdpLayer>();
        udpLayer->getUdpHeader()->portSrc = htons(1337);
        udpLayer->getUdpHeader()->portDst = htons(ui->lineEditPort->text().toInt());
    }
    else
    {
        tcpLayer = packet->getLayerOfType<pcpp::TcpLayer>();
        tcpLayer->getTcpHeader()->portSrc = htons(1337);
        tcpLayer->getTcpHeader()->portDst = htons(ui->lineEditPort->text().toInt());
        tcpLayer->getTcpHeader()->urgFlag = 1;
        uint16_t mssValue = htons(1460);
        tcpLayer->addTcpOptionAfter(pcpp::TCPOPT_MSS, PCPP_TCPOLEN_MSS, (uint8_t*)&mssValue, NULL);
    }

    if(type == "HTTP"){
        pcpp::HttpRequestLayer* httpRequestLayer = packet->getLayerOfType<pcpp::HttpRequestLayer>();
        httpRequestLayer->getFirstLine()->setMethod(pcpp::HttpRequestLayer::HttpTRACE);
        httpRequestLayer->getFieldByName(PCPP_HTTP_HOST_FIELD)->setFieldValue("www.google.com");
        //httpRequestLayer->getFieldByName(PCPP_HTTP_REFERER_FIELD)->setFieldValue("www.aol.com");
        httpRequestLayer->removeField(PCPP_HTTP_COOKIE_FIELD);
        httpRequestLayer->insertField(httpRequestLayer->insertField(httpRequestLayer->getFieldByName(PCPP_HTTP_HOST_FIELD), "X-Forwarded-For", "127.0.0.1"), "Cache-Control", "max-age=0");
    }
    ui->textEdit->setText(QString::fromStdString(packet->toString()));
    this->set=true;
}

void Dialog::on_lineEditPort_textChanged(const QString &arg1)
{
    if(set)
    {
        if(type == "UDP")
        {
            udpLayer->getUdpHeader()->portDst = htons(ui->lineEditPort->text().toInt());
        }
        else{
            tcpLayer->getTcpHeader()->portDst = htons(ui->lineEditPort->text().toInt());
        }
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

void Dialog::on_pushButton_clicked()
{
    packet->computeCalculateFields();
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
