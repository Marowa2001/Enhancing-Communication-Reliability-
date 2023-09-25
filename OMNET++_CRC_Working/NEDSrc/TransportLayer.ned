
package NEDSrc;
//package tcpipstack1.NEDSrc; 
simple TransportLayer{ 
   parameters:
    int  transPortNo = 20; 
   gates: 
	inout tcpGate[2]; 
}