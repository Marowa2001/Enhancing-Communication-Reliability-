
 packet TcpIpPacket { 
   int  appHeader = 0; 
   int  tcpHeader = 0; 
   int  ipHeader = 0; 
   int  dllHeader = 0; 
   int  phyHeader = 0; 
   int  crc = 0; 
   int  data = 0; 
   string packetFormat = NULL; 
 }