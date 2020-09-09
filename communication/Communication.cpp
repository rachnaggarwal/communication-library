#include "Arduino.h"
#include "SPI.h"
#include "WiFi.h"
#include "WiFiClient.h"
#include "WiFiServer.h"
#include "WiFiUdp.h"
#include "Communication.h"

WiFiServer server(80);
void Communication::PinSetup(){
 
}


int Communication::Credentials(String wifi_name, String wifi_password){
    /*
    // Only try 15 times to connect to the WiFi
    WiFi.begin(wifi_name,wifi_password);
    while (WiFi.status()!= WL_CONNECTED && retries < 15){
    delay(500);
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(wifi_name);
    retries++;*/

  Serial.println("Tried to connect 15 times. Error ");
  
  return acknowledge_number;
}

int Communication::Connect(){
    server.begin();
return acknowledge_number;
}

int Communication::Feedback(){
return acknowledge_number;
}

int Communication::Write(String char_write){
 client = server.available();
  if (client.connected()) {
       // read bytes from the incoming client and write them back
    // to any clients connected to the server:
    
    //length of byte we are sending at a time we can send 76 bytes at a time for AVR boards
  }
 return acknowledge_number;
}

String Communication::Read(){
  while (client.available()){
    char c = client.read();  
    st_read = st_read + String(c);   
  }
  return st_read;
}

int Communication::Disconnect(){
    WiFi.disconnect();
    client.stop();
    return conn_status;
}

