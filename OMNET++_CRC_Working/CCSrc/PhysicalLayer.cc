/*
 * PhysicalLayer.cc
 */
#include<stdio.h>
#include<string.h>
#include<omnetpp.h>
#include"Packet_m.h"
using namespace omnetpp;

class PhysicalLayer : public cSimpleModule{
    protected:
        virtual void initialize() override;
        virtual void handleMessage(cMessage *msg) override;
};
Define_Module(PhysicalLayer);
void PhysicalLayer::initialize(){  }
void PhysicalLayer::handleMessage(cMessage *msg){
    TcpIpPacket *pkt = check_and_cast<TcpIpPacket*>(msg);
    //For packet receiving from Data Link Layer
    if(pkt->arrivedOn("phyGate$i",0)){
        char packetInfo [40];
        //For setting and sending of IP Packet
        pkt->setPhyHeader (uniform(1,6));
        sprintf(packetInfo,"PHY Header [%d] Added ",
        pkt->getPhyHeader());
        pkt->setPacketFormat(packetInfo);
        bubble(pkt->getPacketFormat());
        //Send packet on PC port
        send(pkt, "phyGate$o",1);
    }
    //Packet reception on PC port
    else if(pkt->arrivedOn("phyGate$i",1)){
        pkt->setPhyHeader(0);
        //Send packet to Data Link layer
        send(pkt, "phyGate$o",0);
    }
}



