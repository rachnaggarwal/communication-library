#ifndef Communication_h
#define Communication_h

#include "Wifi.h"
#include "WifiClient.h"
#include "WifiServer.h"
#include "WifiUdp.h"

class Communication{
    public:
    string wifi_name;
    string wifi_password;
    int connection_status;
    int acknowledge_number;
    string write;
    string read;

    int Credentials(string wifi_name, string wifi_password);
    int Connect();
    int Feedback();
    char Write(write);
    string Read();
    int Disconnect();

};

#endif