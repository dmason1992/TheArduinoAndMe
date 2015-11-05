/* ------------------------------------------------------------------------------------- \\
                                     Configuration Settings
\\ ------------------------------------------------------------------------------------- */
const boolean Master = false;

/* ------------------------------------------------------------------------------------- \\
                                   Functional Code begins here
\\ ------------------------------------------------------------------------------------- */

// external libraries
#include <ESP8266WiFi.h>
#include <WiFiUDP.h>

void setup() {

  // initialise Serial for debugging
  Serial.begin(115200);
  Serial.println("\n\n\n"); // seperate from the random printout generated by the board
  
  // initialise WiFi (host or slave)
  InitialiseWifi(Master);

  // respond to broadcast from PC
  UDP_RespondToBroadcast();
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
