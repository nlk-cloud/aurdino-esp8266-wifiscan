

#include "ESP8266WiFi.h"

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
WiFi.mode ( WIFI_STA);
WiFi.disconnect();
delay (100);

}

void loop() {
  // put your main code here, to run repeatedly:

Serial.println ( " start scanning....");
// Scan for nearby WIFI SSIDs and save their number into n

int n= WiFi.scanNetworks();
// in case no network is found, print info
if (n==0)
{
  Serial.println(" No SSIDs nearby ....");
  
}
else
{
  Serial.print(n);
  Serial.println (" wifi networks SSIDs nearby...");

  // listing name, signal, strength and security of all wifi networks nearby

  for ( int i=0; i<n; ++i)
  {

    Serial.print ( i+1);
    Serial.print (":");
    Serial.print ( WiFi.SSID (i));
   Serial.print("(");
    Serial.print(WiFi.RSSI());
    Serial.print(")");
    Serial.println (WiFi.encryptionType(i));
    delay(10);
    
  }
}
//Exit
Serial.println(" ");
// Pause for 15 sec before new scan
delay(15000);

}