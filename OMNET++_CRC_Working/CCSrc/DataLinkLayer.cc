/*
 * DataLinkLayer.cc
 */
#include<string.h>
#include<omnetpp.h>
#include"Packet_m.h"
using namespace omnetpp;

class DataLinkLayer : public cSimpleModule{
    private:
        int headersConcatenation;
        const int crcDivider =13;
        int crcValue;
    protected:
        virtual void initialize() override;
        virtual void handleMessage(cMessage *msg) override;
};
Define_Module(DataLinkLayer);
void DataLinkLayer::initialize(){}
void DataLinkLayer::handleMessage(cMessage *msg){
    TcpIpPacket *pkt = check_and_cast<TcpIpPacket *>(msg);
     //For packet receiving from Network Layer
    if(pkt->arrivedOn("dllGate$i",0)){
    //Setting of Data Link layer header
        pkt->setDllHeader(uniform(1,6));
         /* Concatenation of all header values+data for CRC code Calculation */
        headersConcatenation =(pkt->getAppHeader()+ pkt->getData()*10+ pkt->getTcpHeader()*100+ pkt->getIpHeader()*1000+  pkt->getDllHeader()*10000);
         //Calculation of CRC code
        crcValue = crcDivider -((headersConcatenation *100)%crcDivider);
        //Attach CRC code in packet before transmission
        pkt->setCrc(crcValue);
        bubble("CRC Added");
         //Send packet to Physical Layer
        send(pkt, "dllGate$o",1);
}
    //For packet receiving from Physical Layer
    if (pkt->arrivedOn("dllGate$i",1)){
        /* Artificial random error creation in received packets for
        Error Detection through CRC */
        int error = uniform(1,4);
        if(error!= 2)
        pkt->setAppHeader(7);
        /* At receiver side, concatenation of all header values + data
        for CRC */
        headersConcatenation = (pkt->getAppHeader()+ pkt->getData()*10+ pkt->getTcpHeader()*100+pkt->getIpHeader()*1000+ pkt->getDllHeader()*10000);
         //Applying CRC check on received frame
        if((headersConcatenation *100 +  pkt->getCrc())%crcDivider== 0){
         //No Error Message Display
            bubble("CRC checked NO error");
         //Send packet to Network layer
            send(pkt, "dllGate$o",0);
      }
        else{
            bubble("ERROR Detected");
            delete pkt;
        }
    }
}


