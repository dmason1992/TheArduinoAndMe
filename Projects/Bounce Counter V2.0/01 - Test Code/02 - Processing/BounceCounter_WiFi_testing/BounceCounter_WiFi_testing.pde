 import hypermedia.net.*;
 
 // UDP variables
 UDP udp; // define the UDP object
 int port = 8888;
 String broadcastIp       = "255.255.255.255"; // Broadcast message ip address
 String[] ip = {"","","","",""}; //ip of device that responds
 
 void setup(){
   udp = new UDP (this,port);
   udp.log(false);
   udp.listen(true);
   size(300,300);
 }
 
 void draw(){
   background(0);
   delay(10);
   udp.send("CMD_LOCATE", broadcastIp, port );
 }
 
void receive( byte[] data, String ipIn, int port) {          // <-- default handler
   
   println(ipIn);
   println(port);
   for(int i=0; i < data.length; i++) {
     print(char(data[i]));  
   };
   println();   
   
 }