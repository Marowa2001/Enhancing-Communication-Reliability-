/*
 * TransportLayer.cc
 */
#include<stdio.h>
#include<string.h>
#include<omnetpp.h>
#include"Packet_m.h"
using namespace omnetpp;

class TransportLayer : public cSimpleModule{
    protected:
        virtual void initialize() override;
        virtual void handleMessage(cMessage *msg) override;
};
Define_Module(TransportLayer);

void TransportLayer::initialize(){  }
void TransportLayer::handleMessage(cMessage *msg){
    TcpIpPacket *pkt = check_and_cast<TcpIpPacket *>(msg);
    //For packet receiving from Application Layer
    if(pkt->arrivedOn("tcpGate$i",0)){
    char packetInfo [40];
    //For Generation and setting of TCP header
    pkt->setTcpHeader(uniform(1,6));
    sprintf(packetInfo,"TCP Header [%d] added", pkt->getTcpHeader());
    pkt->setPacketFormat(packetInfo);
    *pkt = TcpIpPacket(packetInfo,0);
    bubble(packetInfo);
    send(pkt, "tcpGate$o",1);
}
    //For packet receiving from Network Layer
    if(pkt->arrivedOn("tcpGate$i",1)){
        pkt->setTcpHeader(0);
        send(pkt, "tcpGate$o",0);
    }
}


