#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->editTTL->setText("12");
    ui->comboFlag->addItem("0");
    ui->comboFlag->addItem("1");
    foreach(QNetworkInterface netInterface, QNetworkInterface::allInterfaces())
    {
        if (!(netInterface.flags() & QNetworkInterface::IsLoopBack))
        {
            ui->editMac->setText(netInterface.hardwareAddress());
            break;
        }
    }
    foreach (const QHostAddress &address, QNetworkInterface::allAddresses())
    {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != QHostAddress(QHostAddress::LocalHost))
        {
            ui->editIp->setText(address.toString());
            break;
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonOutput_clicked()
{
    output = QFileDialog::getOpenFileName(this, tr("Open File"));
}

void MainWindow::on_buttonCapture_clicked()
{
    ui->textBrowser->clear();
    std::string interfaceIPAddr;
    foreach (const QHostAddress &address, QNetworkInterface::allAddresses())
    {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != QHostAddress(QHostAddress::LocalHost))
                 interfaceIPAddr =  address.toString().toStdString();
    }

    // find the interface by IP address
    dev = pcpp::PcapLiveDeviceList::getInstance().getPcapLiveDeviceByIp(interfaceIPAddr.c_str());
    if (dev == NULL)
    {
        ui->textBrowser->append("Cannot find interface with IPv4 address of '" + QString(interfaceIPAddr.c_str()) + "'");
        return;
    }
    if(!dev->open())
    {
        ui->textBrowser->append("Cannot open device");
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Processing");
        msgBox.setText("Please Wait");
        msgBox.show();
        dev->startCapture(onPacketArrives, &stats);
        PCAP_SLEEP(ui->lineEdit->text().toInt());
        msgBox.hide();
        dev->stopCapture();
        ui->textBrowser->clear();
        ui->textBrowser->append(stats.returnCount());
    }
}

void MainWindow::onPacketArrives(pcpp::RawPacket* packet, pcpp::PcapLiveDevice* dev, void* cookie)
{
    PacketStats* stats = (PacketStats*)cookie;
    pcpp::Packet parsedPacket(packet);
    stats->consumePacket(parsedPacket);
}

void MainWindow::on_buttonEdit_clicked()
{
    pcpp::EthLayer* ethernetLayer;
    pcpp::IPv4Layer* ipLayer;
    pcpp::TcpLayer* tcpLayer;
    pcpp::UdpLayer* udpLayer;
    std::string srcMAC;
    std::string srcIP;
    pcpp::PcapFileWriterDevice writer(output.toLocal8Bit().data(), pcpp::LINKTYPE_ETHERNET);
    if(!writer.open()){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Error");
        msgBox.setText("Could not open file to write!");
        msgBox.exec();
        return;
    }
    foreach(QNetworkInterface netInterface, QNetworkInterface::allInterfaces())
    {
        if (!(netInterface.flags() & QNetworkInterface::IsLoopBack))
        {
            srcMAC = netInterface.hardwareAddress().toStdString();
            break;
        }
    }
    foreach (const QHostAddress &address, QNetworkInterface::allAddresses())
    {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != QHostAddress(QHostAddress::LocalHost))
        {
            srcIP = address.toString().toStdString();
            break;
        }
    }
    foreach(pcpp::Packet packet, stats.tcp)
    {
        ethernetLayer = packet.getLayerOfType<pcpp::EthLayer>();
        if(ui->checkMac->isChecked()){
            ethernetLayer->setDestMac(pcpp::MacAddress(ui->editMac->text().toStdString()));
        }/*else{
            ethernetLayer->setDestMac(pcpp::MacAddress(ethernetLayer->getSourceMac().toString()));
        }*/



        ethernetLayer->setSourceMac(pcpp::MacAddress(srcMAC));

        ipLayer = packet.getLayerOfType<pcpp::IPv4Layer>();

        if(ui->checkIP->isChecked()){
            ipLayer->setDstIpAddress(pcpp::IPv4Address(ui->editIp->text().toStdString()));
        }

        ipLayer->setSrcIpAddress(pcpp::IPv4Address(srcIP));
        //ipLayer->getIPv4Header()->ipId = htons(4000);
        ui->editTTL->setValidator(new QIntValidator(0, 255, this));

        QString str;
        int pos = 0;
        QIntValidator v(0, 255, this);

        str = ui->editTTL->text();
        QValidator::State estado = v.validate(str, pos);

        if(estado == QValidator::Invalid){
            QMessageBox msgBox;
            msgBox.setWindowTitle("Error");
            msgBox.setText("Enter a integer between 0 and 1");
            msgBox.exec();
            return;
        }

        ipLayer->getIPv4Header()->timeToLive = ui->editTTL->text().toInt();

        tcpLayer = packet.getLayerOfType<pcpp::TcpLayer>();
        tcpLayer->getTcpHeader()->portSrc = htons(1337);

        if(ui->checkPort->isChecked()){
            tcpLayer->getTcpHeader()->portDst = htons(ui->editPort->text().toInt());
        }

        tcpLayer->getTcpHeader()->urgFlag = ui->comboFlag->currentText().toInt();

        /*uint16_t mssValue = htons(1460);
        tcpLayer->addTcpOptionAfter(pcpp::TCPOPT_MSS, PCPP_TCPOLEN_MSS, (uint8_t*)&mssValue, NULL);*/
        packet.computeCalculateFields();
        writer.writePacket(*packet.getRawPacket());
    }
    foreach(pcpp::Packet packet, stats.udp)
    {
        ethernetLayer = packet.getLayerOfType<pcpp::EthLayer>();

        if(ui->checkMac->isChecked()){
            ethernetLayer->setDestMac(pcpp::MacAddress(ui->editMac->text().toStdString()));
        }
        ethernetLayer->setSourceMac(pcpp::MacAddress(srcMAC));

        ipLayer = packet.getLayerOfType<pcpp::IPv4Layer>();

        if(ui->checkIP->isChecked()){
            ipLayer->setDstIpAddress(pcpp::IPv4Address(ui->editIp->text().toStdString()));
        }

        ipLayer->setSrcIpAddress(pcpp::IPv4Address(srcIP));

        udpLayer = packet.getLayerOfType<pcpp::UdpLayer>();
        udpLayer->getUdpHeader()->portSrc = htons(1337);

        if(ui->checkPort->isChecked()){
            udpLayer->getUdpHeader()->portDst = htons(ui->editPort->text().toInt());
        }

        packet.computeCalculateFields();
        writer.writePacket(*packet.getRawPacket());
    }
    QMessageBox msgBox;
    msgBox.setWindowTitle("Success");
    msgBox.setText("All packets saved!");
    msgBox.exec();
}
