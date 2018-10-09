#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem("TCP");
    ui->comboBox->addItem("UDP");
    ui->comboBox->addItem("DNS");
    ui->comboBox->addItem("HTTP");
    ui->comboBox->addItem("SSL");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    std::string interfaceIPAddr;
    foreach (const QHostAddress &address, QNetworkInterface::allAddresses()) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != QHostAddress(QHostAddress::LocalHost))
                 interfaceIPAddr =  address.toString().toUtf8().constData();
    }

    // find the interface by IP address
    pcpp::PcapLiveDevice* dev = pcpp::PcapLiveDeviceList::getInstance().getPcapLiveDeviceByIp(interfaceIPAddr.c_str());
    if (dev == NULL)
    {
        ui->textBrowser->append("Cannot find interface with IPv4 address of '" + QString(interfaceIPAddr.c_str()) + "'");
        return;
    }
    if(!dev->open())
    {
        ui->textBrowser->append("Cannot open device");
    }else{

        dev->startCapture(onPacketArrives, &stats);

        PCAP_SLEEP(ui->lineEdit->text().toInt());

        dev->stopCapture();
        ui->textBrowser_2->clear();
        ui->textBrowser_2->append(stats.returnCount());
    }
}

void MainWindow::onPacketArrives(pcpp::RawPacket* packet, pcpp::PcapLiveDevice* dev, void* cookie)
{
    // extract the stats object form the cookie
    PacketStats* stats = (PacketStats*)cookie;

    // parsed the raw packet
    pcpp::Packet parsedPacket(packet);

    // collect stats from packet
    stats->consumePacket(parsedPacket);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->textBrowser->clear();
    switch(ui->comboBox->currentIndex()){
    case 0://TCP
        for(int i = 0; i < stats.tcp.length(); i++){
             ui->textBrowser->append(QString::fromStdString(stats.tcp[i].toString()));
        }
    break;
    case 1://UDP
        for(int i = 0; i < stats.udp.length(); i++){
             ui->textBrowser->append(QString::fromStdString(stats.udp[i].toString()));
        }
    break;
    case 2://DNS
        for(int i = 0; i < stats.dns.length(); i++){
             ui->textBrowser->append(QString::fromStdString(stats.dns[i].toString()));
        }
    break;
    case 3://HTTP
        for(int i = 0; i < stats.http.length(); i++){
             ui->textBrowser->append(QString::fromStdString(stats.http[i].toString()));
        }
    break;
    case 4://SSL
        for(int i = 0; i < stats.ssl.length(); i++){
             ui->textBrowser->append(QString::fromStdString(stats.ssl[i].toString()));
        }
    break;
    }
}
