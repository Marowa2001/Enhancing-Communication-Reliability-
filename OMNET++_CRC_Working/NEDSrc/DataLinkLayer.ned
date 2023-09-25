
package NEDSrc;
//package tcpipstack1.NEDSrc; 
simple DataLinkLayer{      
    parameters:
        string macAddress = "NIL"; 
	gates: 
		inout dllGate[2];
}