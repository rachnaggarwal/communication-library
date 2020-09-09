#ifndef Communication_h
#define Communication_h
#include "Arduino.h"
#include "WiFi.h"
#include "WiFiClient.h"
#include "WiFiServer.h"
#include "WiFiUdp.h"
#include "SPI.h"

class Communication{
    
 public:
    String wifi_name = "";
    String wifi_password = "";
    int conn_status;
    int acknowledge_number;
    String chr_write="";
    String st_read=" ";
    WiFiClient client; 
    int retries = 0;
    
    void PinSetup();
    int Credentials(String wifi_name,String wifi_password);
    int Connect();
    int Feedback();
    int Write(String chr_write);
    String Read();
    int Disconnect();
    
};
#endif
