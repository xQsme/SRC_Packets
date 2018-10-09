#ifndef THREAD_H
#define THREAD_H
#include <QtCore>
#include <PcapLiveDeviceList.h>
#include <PlatformSpecificUtils.h>

class Thread : public QThread
{
    Q_OBJECT
public:
    Thread(std::string interface);
    Thread();
    void run();
private:
    std::string interface;
    static void onPacketArrives(pcpp::RawPacket* packet, pcpp::PcapLiveDevice* dev, void* cookie);
signals:
    void error(QString message);
    void captured(QString packet);
};
#endif // THREAD_H
