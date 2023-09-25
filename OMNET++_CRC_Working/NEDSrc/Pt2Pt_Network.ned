package NEDSrc;//auto create hoise
//package tcpipstack1.NEDSrc; //code theke copy krsi
// Creation of a Network consisting of two modules of type PC
network Pt2Pt_Network{      
    submodules:
        PC1: PC; 
    	PC2: PC; 
    connections: 
    	PC1.gate++ <--> PC2.gate++;
}
