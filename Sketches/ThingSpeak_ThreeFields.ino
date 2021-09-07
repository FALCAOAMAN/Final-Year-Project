#include <SoftwareSerial.h>



float t=0;


char data = 0;
#define RX 2
#define TX 3
String AP = "Amanwifi";       // AP NAME
String PASS = "falcaoaman"; // AP PASSWORD
String API = "RV0F3F1HFS822VFJ";   // Write API KEY
String HOST = "api.thingspeak.com";
String PORT = "80";
String field = "field1";
int countTrueCommand;
int countTimeCommand; 
boolean found = false; 
int valSensor = 1;
SoftwareSerial esp8266(RX,TX); 
 
  
void setup() {
  Serial.begin(9600);
  esp8266.begin(115200);
  sendCommand("AT",5,"OK");
  sendCommand("AT+CWMODE=1",5,"OK");
  sendCommand("AT+CWJAP=\""+ AP +"\",\""+ PASS +"\"",20,"OK");
}
 

void loop()

{

  delay(1000);

  t = analogRead(A0);

  Serial.print("Airquality = ");

  Serial.println(t);


  esp8266();


}


void esp8266()

{

   // TCP connection AT+CIPSTART=4,"TCP","184.106.153.149",80 

    String cmd = "AT+CIPSTART=4","TCP","";

    cmd += "184.106.153.149"; // api.thingspeak.com

    cmd += "80";

    ser.println(cmd);

    Serial.println(cmd); 

    if(ser.find("Error"))

    {

      Serial.println("AT+CIPSTART error");

      return;

    }

  

  // prepare GET string GET https://api.thingspeak.com/update?api_key=LHAG4NSIYJ5UWS6U&field1=0rnrn

  String getStr = "GET /update?api_key=";

  getStr += apiKey;

  //getStr +="&field1=";

  //getStr +=String(h);

  getStr +="&field1=";

  getStr +=String(t);

  getStr += "rnrn";

  // send data length

  cmd = "AT+CIPSEND=4,";

  cmd += String(getStr.length());

  ser.println(cmd);

  Serial.println(cmd);

  delay(1000);

  ser.print(getStr);

  Serial.println(getStr);

     

  // thingspeak needs 15 sec delay between updates

  delay(16000);  

}
