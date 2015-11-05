// wifi connection variables
const char* ssid = "BounceCounter";
const char* password = "12345678";

// UDP variables
WiFiUDP udp; // udp object
int udp_port = 8888; // port
byte pc_ip[4] = {0,0,0,0}; // ip address of PC

/* Initialise WiFi
 * 
 * This function initialises the WiFi (whether it is the host or just joining the
 * host network) and initialises the UDP port
 */
void InitialiseWifi(boolean Master){
  
  // check if this node is a master (the host) or a slave
  if (Master){
    Serial.println("Master Node initiating WiFi");
    WiFi.softAP(ssid,password,1); // Setup wifi network
  }
  else {
    // loop until able to connect to the WiFi network
    Serial.print("Attempting to connect to ");
    Serial.println(ssid);
    WiFi.begin(ssid, password); // connect to the bounce counter network
    // wait until connection is established
    while (WiFi.status() != WL_CONNECTED) {
      Serial.print(".");
      delay(500);
    }
    Serial.println(".");
    Serial.println("WiFi Connected");
  }

  // Initialise UDP
  udp.begin(udp_port);

}

/* Respond to WiFi broadcast
 *  
 * This function responds to the broadcast message from the PC so that the IP address' of
 * the nodes can be stored.
 */
void UDP_RespondToBroadcast(){

  // continue checking until UDP broadcast is found
  Serial.print("Waiting for broadcast");
  boolean PacketAvailable = false;
  while (!PacketAvailable){
    Serial.print(".");
    delay(500);
  
  int packetSize = udp.parsePacket();
  if (packetSize){
    Serial.println("UDP broadcast received");
    Serial.print("Packet size: ");
    Serial.println(packetSize);
    char packetBuffer[packetSize]; // create char array to store packet
    udp.read(packetBuffer, packetSize);
    Serial.print("Data Received: ");
    Serial.println(packetBuffer);
//        if (packetBuffer == "CMD_LOCATE"){
//          PacketAvailable = true;
//          Serial.println("PC located");
//        }
//        else {
//          Serial.println("Invalid command received");
//        } 
    PacketAvailable = true;
  }
}
    
  

}

