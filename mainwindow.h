#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QNetworkInterface>
#include <PcapLiveDeviceList.h>
#include <PlatformSpecificUtils.h>
#include "dialog.h"

struct PacketStats
{
    QList<pcpp::Packet> tcp;
    QList<pcpp::Packet> udp;
    QList<pcpp::Packet> http;
    QList<pcpp::Packet> ssl;
    QList<pcpp::Packet> dns;

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
        if (packet.isPacketOfType(pcpp::TCP)){
            tcp.append(packet);
            tcpPacketCount++;
        }
        if (packet.isPacketOfType(pcpp::UDP)){
            udp.append(packet);
            udpPacketCount++;
        }
        if (packet.isPacketOfType(pcpp::HTTP)){
            http.append(packet);
            httpPacketCount++;
        }
        if (packet.isPacketOfType(pcpp::SSL)){
            ssl.append(packet);
            sslPacketCount++;
        }
    }

    /**
    * Print stats to console
    */
    QString returnCount()
    {
        return ("Ethernet packet count:\t" + QString::number(ethPacketCount) +
        "\nIPv4 packet count:\t" + QString::number(ipv4PacketCount) +
        "\nIPv6 packet count:\t" + QString::number(ipv6PacketCount) +
        "\nTCP packet count:\t" + QString::number(tcpPacketCount) +
        "\nUDP packet count:\t" + QString::number(udpPacketCount) +
        "\nDNS packet count:\t" + QString::number(dnsPacketCount) +
        "\nHTTP packet count:\t" + QString::number(httpPacketCount) +
        "\nSSL packet count:\t" + QString::number(sslPacketCount));
    }
};


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    static void onPacketArrives(pcpp::RawPacket* packet, pcpp::PcapLiveDevice* dev, void* cookie);
    PacketStats stats;
    pcpp::PcapLiveDevice* dev;
    QString type;
    int index;
};

#endif // MAINWINDOW_H
