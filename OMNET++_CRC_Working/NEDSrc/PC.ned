package NEDSrc;
// Package statement 
//package tcpipstack1.NEDSrc; 
 // A compound module creation named PC having two gates 
module PC{ 
   parameters: 
 			@display("i=device/pc2,gold"); 
   gates: 
         inout gate[]; 
 // Inclusion of Layers as submodules in PC module 
   submodules: 
    appL: ApplicationLayer { 
          @display("p=45,26;i=block/sink"); 
     } 
     tcpL: TransportLayer { 
          @display("p=123,56;i=block/filter"); 
     } 
     ipL: NetworkLayer { 
          @display("p=123,137;i=old/proc2"); 
     } 
     dlL: DataLinkLayer { 
          @display("p=123,216;i=device/card"); 
     } 
     phyL: PhysicalLayer { 
          @display("p=57,226;i=device/card"); 
     } 
    connections: 
       appL.appGate[0] <--> tcpL.tcpGate[0]; 
       tcpL.tcpGate[1] <--> ipL.ipGate[0]; 
       ipL.ipGate[1] <--> dlL.dllGate[0]; 
       dlL.dllGate[1] <--> phyL.phyGate[0]; 
       phyL.phyGate[1] <--> gate++;
 
}