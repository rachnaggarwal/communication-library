#include <Communication.h>
Communication cmt;

String read_bytes;
char write_byte;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
cmt.PinSetup();
}

void loop() {
// put your main code here, to run repeatedly:
/*we need to connect different node again so Connect function 
will work in void loop not void setup*/
cmt.Credentials("WifiName", "WifiPassword");
while(cmt.Connect()!=1)
{
  //module keep connecting until return from Connect function is 1
}
read_bytes = cmt.Read();
if(1==1) //read==value we want to read
{
write_byte = cmt.Write('h');
while(write_byte!='y')
{
 Serial.println(cmt.Feedback()); //print 1 for error or 0 for still performing the task
}
}
 Serial.println(cmt.Disconnect());//disconnect and print connection_status
}
