#include "mainwindow.h"
#include "ui_mainwindow.h"

struct PacketStats
{
    int ethPacketCount;
    int ipv4PacketCount;
    int ipv6PacketCount;
    int tcpPacketCount;
    int udpPacketCount;
    int dnsPacketCount;
    int httpPacketCount;
    int sslPacketCount;


    /**
    * Clear all stats
    */
    void clear() { ethPacketCount = 0; ipv4PacketCount = 0; ipv6PacketCount = 0; tcpPacketCount = 0; udpPacketCount = 0; tcpPacketCount = 0; dnsPacketCount = 0; httpPacketCount = 0; sslPacketCount = 0; }

    /**
    * C'tor
    */
    PacketStats() { clear(); }

    /**
    * Collect stats from a packet
    */
    void consumePacket(pcpp::Packet& packet)
    {
        if (packet.isPacketOfType(pcpp::Ethernet))
            ethPacketCount++;
        if (packet.isPacketOfType(pcpp::IPv4))
            ipv4PacketCount++;
        if (packet.isPacketOfType(pcpp::IPv6))
            ipv6PacketCount++;
        if (packet.isPacketOfType(pcpp::TCP))
            tcpPacketCount++;
        if (packet.isPacketOfType(pcpp::UDP))
            udpPacketCount++;
        if (packet.isPacketOfType(pcpp::HTTP))
            httpPacketCount++;
        if (packet.isPacketOfType(pcpp::SSL))
            sslPacketCount++;
    }

    /**
    * Print stats to console
    */
    void printToConsole()
    {
        printf("Ethernet packet count: %d\n", ethPacketCount);
        printf("IPv4 packet count:     %d\n", ipv4PacketCount);
        printf("IPv6 packet count:     %d\n", ipv6PacketCount);
        printf("TCP packet count:      %d\n", tcpPacketCount);
        printf("UDP packet count:      %d\n", udpPacketCount);
        printf("DNS packet count:      %d\n", dnsPacketCount);
        printf("HTTP packet count:     %d\n", httpPacketCount);
        printf("SSL packet count:      %d\n", sslPacketCount);
    }
};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
        //Messagebox
        //ui->textBrowser->append("Cannot find interface with IPv4 address of '" + QString(interfaceIPAddr.c_str()) + "'");
    }/*else{
        ui->textBrowser->append("Interface info:");
        // get interface name
        ui->textBrowser->append("   Interface name:\t" + QString(dev->getName()));
        // get interface description
        //ui->textBrowser->append("   Interface description:" + QString(dev->getDesc()));
        // get interface MAC address
        ui->textBrowser->append("   MAC address:\t" + QString(dev->getMacAddress().toString().c_str()));
        // get default gateway for interface
        ui->textBrowser->append("   Default gateway:\t" + QString(dev->getDefaultGateway().toString().c_str()));
        // get interface MTU
        ui->textBrowser->append("   Interface MTU:\t" + QString::number(dev->getMtu()));
        // get DNS server if defined for this interface
        if (dev->getDnsServers().size() > 0)
            ui->textBrowser->append("   DNS server:\t\t" + QString(dev->getDnsServers().at(0).toString().c_str()));
    }*/
    if(!dev->open())
    {
        //MessageBox
    }else{
        PacketStats stats;
        dev->startCapture(onPacketArrives, &stats);

        PCAP_SLEEP(10);

        // stop capturing packets
        dev->stopCapture();
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
