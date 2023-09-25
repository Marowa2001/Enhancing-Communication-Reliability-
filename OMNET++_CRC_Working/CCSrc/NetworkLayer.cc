/*
 * NetworkLayer.cc
 */
#include<stdio.h>
#include<string.h>
#include<omnetpp.h>
#include"Packet_m.h"
using namespace omnetpp;

class NetworkLayer : public cSimpleModule{
    protected:
        virtual void initialize() override;
        virtual void handleMessage(cMessage *msg) override;
};
Define_Module(NetworkLayer);
void NetworkLayer::initialize(){ }
void NetworkLayer::handleMessage(cMessage *msg){
    TcpIpPacket *pkt = check_and_cast<TcpIpPacket *>(msg);
//For packet receiving from Transport Layer
    if(pkt->arrivedOn("ipGate$i",0)){
        char packetInfo[40];
//For setting and sending of IP Packet
        pkt->setIpHeader(uniform(1,6));
        sprintf(packetInfo,"IP Header [%d] Added ", pkt->getIpHeader());
        pkt->setPacketFormat(packetInfo);
        bubble(pkt->getPacketFormat());
//Sending packet to Data Link layer
        send(pkt, "ipGate$o",1);
    }
    if(pkt->arrivedOn("ipGate$i",1)){
        pkt->setIpHeader(0);
        //Sending packet to Transport layer
        send(pkt, "ipGate$o",0);
    }
}



