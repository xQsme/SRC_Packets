#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QNetworkInterface>
#include <QMessageBox>
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

private:
    Ui::Dialog *ui;
    pcpp::Packet* packet;
    pcpp::PcapLiveDevice* dev;
};

#endif // DIALOG_H
