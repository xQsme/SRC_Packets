#include "thread.h"

Thread::Thread(std::string interface)
{
    this->interface=interface;
}

Thread::Thread()
{

}

void Thread::run()
{
    pcpp::PcapLiveDevice* dev = pcpp::PcapLiveDeviceList::getInstance().getPcapLiveDeviceByIp(interface.c_str());
    if (dev == NULL)
    {
        emit error("Cannot find interface with IPv4 address of '" + QString(interface.c_str()) + "'");
        return;
    }
    if(!dev->open())
    {
        emit error("Cannot open device");
    }else{
        dev->startCapture(onPacketArrives, NULL);
        //dev->stopCapture();
    }
}

void Thread::onPacketArrives(pcpp::RawPacket* packet, pcpp::PcapLiveDevice* dev, void* cookie)
{

    // parsed the raw packet
    pcpp::Packet parsedPacket(packet);

    //emit captured(QString::fromStdString(parsedPacket.toString()));
}
