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
    ui->textBrowser_2->clear();
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
        ui->textBrowser_2->append("Cannot find interface with IPv4 address of '" + QString(interfaceIPAddr.c_str()) + "'");
        return;
    }
    if(!dev->open())
    {
        ui->textBrowser_2->append("Cannot open device");
    }
    else
    {
        dev->startCapture(onPacketArrives, &stats);
        PCAP_SLEEP(ui->lineEdit->text().toInt());
        dev->stopCapture();
        ui->textBrowser_2->clear();
        ui->textBrowser_2->append(stats.returnCount());
    }
}

void MainWindow::onPacketArrives(pcpp::RawPacket* packet, pcpp::PcapLiveDevice* dev, void* cookie)
{
    PacketStats* stats = (PacketStats*)cookie;
    pcpp::Packet parsedPacket(packet);
    stats->consumePacket(parsedPacket);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->listWidget->clear();
    switch(ui->comboBox->currentIndex())
    {
        case 0://TCP
            for(int i = 0; i < stats.tcp.length(); i++)
            {
                QString packet = QString::fromStdString(stats.tcp[i].toString());
                if(packet.contains("IPv4"))
                {
                    ui->listWidget->addItem(packet.split("IPv4 Layer, ")[1].split("\n")[0]);
                }
                else
                {
                    ui->listWidget->addItem(packet.split("IPv6 Layer, ")[1].split("\n")[0]);
                }
            }
        break;
        case 1://UDP
            for(int i = 0; i < stats.udp.length(); i++)
            {
                QString packet = QString::fromStdString(stats.udp[i].toString());
                if(packet.contains("IPv4"))
                {
                    ui->listWidget->addItem(packet.split("IPv4 Layer, ")[1].split("\n")[0]);
                }
                else
                {
                    ui->listWidget->addItem(packet.split("IPv6 Layer, ")[1].split("\n")[0]);
                }
            }
        break;
        case 2://DNS
            for(int i = 0; i < stats.dns.length(); i++)
            {
                QString packet = QString::fromStdString(stats.dns[i].toString());
                if(packet.contains("IPv4"))
                {
                    ui->listWidget->addItem(packet.split("IPv4 Layer, ")[1].split("\n")[0]);
                }
                else
                {
                    ui->listWidget->addItem(packet.split("IPv6 Layer, ")[1].split("\n")[0]);
                }
            }
        break;
        case 3://HTTP
            for(int i = 0; i < stats.http.length(); i++)
            {
                QString packet = QString::fromStdString(stats.http[i].toString());
                if(packet.contains("IPv4"))
                {
                    ui->listWidget->addItem(packet.split("IPv4 Layer, ")[1].split("\n")[0]);
                }
                else
                {
                    ui->listWidget->addItem(packet.split("IPv6 Layer, ")[1].split("\n")[0]);
                }
            }
        break;
        case 4://SSL
            for(int i = 0; i < stats.ssl.length(); i++)
            {
                QString packet = QString::fromStdString(stats.ssl[i].toString());
                if(packet.contains("IPv4"))
                {
                    ui->listWidget->addItem(packet.split("IPv4 Layer, ")[1].split("\n")[0]);
                }
                else
                {
                    ui->listWidget->addItem(packet.split("IPv6 Layer, ")[1].split("\n")[0]);
                }
            }
        break;
    }
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    int i = ui->listWidget->currentRow();
    switch(ui->comboBox->currentIndex())
    {
        case 0://TCP
            ui->textBrowser->setText(QString::fromStdString(stats.tcp[i].toString()));
            type="TCP";
            index=i;
        break;
        case 1://UDP
            ui->textBrowser->setText(QString::fromStdString(stats.udp[i].toString()));
            type="UDP";
            index=i;
        break;
        case 2://DNS
            ui->textBrowser->setText(QString::fromStdString(stats.dns[i].toString()));
            type="DNS";
            index=i;
        break;
        case 3://HTTP
            ui->textBrowser->setText(QString::fromStdString(stats.http[i].toString()));
            type="HTTP";
            index=i;
        break;
        case 4://SSL
            ui->textBrowser->setText(QString::fromStdString(stats.ssl[i].toString()));
            type="SSL";
            index=i;
        break;
    }
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    ui->listWidget->clear();
}

void MainWindow::on_pushButton_3_clicked()
{
    pcpp::Packet* packet;
    if(type=="TCP")
    {
        packet = &stats.tcp[index];
    }
    else if(type=="UDP")
    {
        packet = &stats.udp[index];
    }
    else if(type=="DNS")
    {
        packet = &stats.dns[index];
    }
    else if(type=="HTTP")
    {
        packet = &stats.http[index];
    }
    else if(type=="SSL")
    {
        packet = &stats.ssl[index];
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Error");
        msgBox.setText("No packet selected!");
        msgBox.exec();
        return;
    }

    Dialog* dialog =  new Dialog();
    dialog->setStuff(packet, dev);
    dialog->setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint);
    dialog->setAttribute(Qt::WA_DeleteOnClose, true);
    dialog->show();
}
