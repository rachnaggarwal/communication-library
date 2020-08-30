#include <Communication.h>

Communication cmt;

int read_bytes;
char write_byte;
string WifiName[]={"ET","EE","E1","EE","E2","EE","E3","EE"};
string WifiPassword[]={"1234","5678","9101","1121","3141","5161","7181","9120"};
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
}

void loop() {
// put your main code here, to run repeatedly:
/*we need to connect different node again so Connect function 
will work in void loop not void setup*/
for(int i=0;i<8;i++)
{
cmt.Credentials(WifiName[i], WifiPassword[i]);
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
 Serial.println(cmt.Feedback()); //print 1 for error or 0 for still performing the task
}
}
 Serial.println(cmt.Disconnect());//disconnect and print connection_status
}
 Serial.println("One cycle is completed");
}
