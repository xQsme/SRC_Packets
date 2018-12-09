#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QMessageBox>
#include <QNetworkInterface>
#include <QFileDialog>
#include "PcapLiveDeviceList.h"
#include "PlatformSpecificUtils.h"
#include "PcapFileDevice.h"
#include "EthLayer.h"
#include "IPv4Layer.h"
#include "TcpLayer.h"
#include "UdpLayer.h"
#include <arpa/inet.h>

struct PacketStats
{
    QList<pcpp::Packet> tcp;
    QList<pcpp::Packet> udp;

    PacketStats() { }

    void consumePacket(pcpp::Packet& packet)
    {
        if (packet.isPacketOfType(pcpp::TCP)){
            tcp.append(packet);
        }
        if (packet.isPacketOfType(pcpp::UDP)){
            udp.append(packet);
        }
    }

    QString returnCount()
    {
        return ("Captured Packets:\nTCP packet count:\t" + QString::number(tcp.length()) +
        "\nUDP packet count:\t" + QString::number(udp.length()));
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


    void on_buttonOutput_clicked();

    void on_buttonCapture_clicked();

    void on_buttonEdit_clicked();

    void on_comboBoxInterface_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    static void onPacketArrives(pcpp::RawPacket* packet, pcpp::PcapLiveDevice* dev, void* cookie);
    PacketStats stats;
    QString output;
    pcpp::PcapLiveDevice* dev;
};

#endif // MAINWINDOW_H
