#include <Communication.h>

Communication cmt;

int read_bytes;
char write_byte;

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
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
if(read_byte == int_value)
{
write_byte = cmt.Write(/*command you want to give after reading*/);
while(write_byte!='y')
{
 Serial.println(cmt.feedback()); //print 1 for error or 0 for still performing the task
}
}
 Serial.println(cmt.Disconnect());//disconnect and print connection_status
}
