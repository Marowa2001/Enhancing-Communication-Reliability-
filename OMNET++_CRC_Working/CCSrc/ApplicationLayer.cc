/*
 * ApplicationLayer.cc
 */
#include<stdio.h>
#include<string.h>
#include<omnetpp.h>
#include"Packet_m.h"
using namespace omnetpp;
class ApplicationLayer : public cSimpleModule{
    protected:
        virtual void initialize() override;
        virtual void handleMessage(cMessage *msg) override;
        virtual TcpIpPacket* generateNextMessage();
};
Define_Module(ApplicationLayer);
void ApplicationLayer::initialize(){
//To initialize Message Passing from PC1
    if(strcmp(par("AppID").operator const char *(),"PC1")==0){
       scheduleAt (0.0, generateNextMessage());
    }
}
void ApplicationLayer::handleMessage(cMessage *msg){
    TcpIpPacket* pkt = check_and_cast<TcpIpPacket *>(msg);
//On message arrival at input port of Application Layer
   if(pkt->arrivedOn("appGate$i",0)){ pkt->setAppHeader(0);
       delete pkt;
}
//For initialized or resend packet scenario
   if(msg->isSelfMessage()){
       //To display packet parameters
       char packetInfo[20];
       //To store Application Header & Data in packet
       sprintf(packetInfo,"AppHeader= %d\nData= %d",
       pkt->getAppHeader(),pkt->getData());
       send(pkt,"appGate$o",0);
       //To reschedule the Self message after every 100ms Delay
       scheduleAt(simTime()+.1, generateNextMessage());
       //To show packet details
       bubble (packetInfo);
   }
}
//For random massage generation
 TcpIpPacket* ApplicationLayer:: generateNextMessage(){
     char nextData[20];
//To generate random data as an integer value
     int generatedData = uniform(6,9);
     //To assign app Header
     int appHdr = uniform(1,6);
     sprintf(nextData,"%d%d",appHdr, generatedData);
     //To create new packet of created data
     TcpIpPacket* nextPkt = new TcpIpPacket(nextData);
     //Settings of Packet Parameters
     nextPkt->setData(generatedData);
     nextPkt->setAppHeader(appHdr);
     nextPkt->setPacketFormat(nextData);
     return nextPkt;
 }



