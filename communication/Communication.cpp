#include "Arduino.h"
#include "WiFi.h"
#include "WiFiClient.h"
#include "WiFiServer.h"
#include "WiFiUdp.h"
#include "SPI.h"
#include "Communication.h"
 WiFiServer server(80);
void Communication::PinSetup(){
  //connecting server
    server.begin(); 
    
    //connecting client to the server
    Serial.println("Connected to wifi");
    Serial.println("\nStarting connection...");
    // if you get a connection, report back via serial:
    if (client.connect(server, 80)) {
      Serial.println("connected");
      // Make a HTTP request:
      client.println("GET /search?q=arduino HTTP/1.0");
      client.println();
    }
    Serial.println("** Scan Networks **");
    int numSsid = WiFi.scanNetworks();
    if (numSsid == -1) {
    Serial.println("Couldn't get a wifi connection");
    while (true);
  }

  // print the list of networks seen:
  Serial.print("number of available networks:");
  Serial.println(numSsid);

  // print the network number and name for each network found:
  for (int thisNet = 0; thisNet < numSsid; thisNet++) {
    Serial.print(thisNet);
    Serial.print(") ");
    Serial.print(WiFi.SSID(thisNet));
    Serial.print("\tSignal: ");
    Serial.print(WiFi.RSSI(thisNet));
    Serial.print(" dBm");
    
  }
}


int Communication::Credentials(String wifi_name, String wifi_password){
    
    // Only try 15 times to connect to the WiFi
    WiFi.begin(String wifi_name, String wifi_password);
    while (WiFi.status()!= WL_CONNECTED && retries < 15){
    delay(500);
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(wifi_name);
    retries++;
  }

  Serial.println("Tried to connect 15 times. Error ");
  
  return acknowledge_number;
}

int Communication::Connect(){
    int conn_status = WL_IDLE_STATUS;
    if (WiFi.status() == WL_CONNECTED){
    Serial.println("Connection successful with");
    return conn_status;
    }
    else
    {
    Serial.println("Cannot connect to the main node");
    return conn_status;
    }
}

int Communication::Feedback(){
return acknowledge_number;
}

char Communication::Write(String char_write){
 client = server.available();
  if (client == true) {
       // read bytes from the incoming client and write them back
    // to any clients connected to the server:
    server.write(char_write);
    //length of byte we are sending at a time we can send 76 bytes at a time for AVR boards
  }
 return acknowledge_number;
}

String Communication::Read(){
  if (client.available()){
    char c = client.read();  
    st_read = st_read + c;   
  }
  return st_read;
}

int Communication::Disconnect(){
    WiFi.disconnect();
    client.stop();
    return connection_status;
}

