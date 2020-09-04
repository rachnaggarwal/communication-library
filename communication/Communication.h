#ifndef Communication_h
#define Communication_h
#include "Arduino.h"
#include "WiFi.h"
#include "WiFiClient.h"
#include "WiFiServer.h"
#include "WiFiUdp.h"

class Communication{
    public:
    String wifi_name;
    String wifi_password;
    int conn_status;
    int acknowledge_number;
    char chr_write;
    String st_read=" ";
    WiFiServer server(const 80);
    WiFiClient client; 
     


    int retries = 0;
    
    void PinSetup();
    int Credentials(String wifi_name,String wifi_password);
    int Connect();
    int Feedback();
    char Write(char chr_write);
    String Read();
    int Disconnect();
    
};

#endif
