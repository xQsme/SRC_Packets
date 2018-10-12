#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QNetworkInterface>
#include <QMessageBox>
#include <arpa/inet.h>
#include "Packet.h"
#include "EthLayer.h"
#include "VlanLayer.h"
#include "IPv4Layer.h"
#include "TcpLayer.h"
#include "HttpLayer.h"
#include "UdpLayer.h"
#include "DnsLayer.h"
#include <PcapLiveDeviceList.h>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    void setStuff(pcpp::Packet* packet, pcpp::PcapLiveDevice* dev);
    ~Dialog();

private slots:
    void on_buttonBox_accepted();

    void on_lineEditPort_textChanged(const QString &arg1);

    void on_lineEditMac_textChanged(const QString &arg1);

    void on_lineEditIP_textChanged(const QString &arg1);

private:
    Ui::Dialog *ui;
    pcpp::Packet* packet;
    pcpp::PcapLiveDevice* dev;
    pcpp::EthLayer* ethernetLayer;
    pcpp::IPv4Layer* ipLayer;
    pcpp::TcpLayer* tcpLayer;
    std::string srcMAC;
    std::string srcIP;
    bool set = false;
};

#endif // DIALOG_H
