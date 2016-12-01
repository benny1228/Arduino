#include <SoftwareSerial.h>
#include<Servo.h>
#define _baudrate   9600
#define _rxpin      4
#define _txpin      5
SoftwareSerial debug( _rxpin, _txpin ); // RX, TX
//*-- IoT Information
#define SSID "benny1228"
#define PASS "benny7669264"
#define IP "192.168.51.2" // ThingSpeak IP Address: 184.106.153.149
String GET = "GET /echo.php";
char a;
 Servo servoX;
 Servo servoY;
void setup() {
  // put your setup code here, to run once:
  servoX.attach(12);
servoY.attach(11);
     servoY.write(90);
Serial.begin( _baudrate );
debug.begin( _baudrate );
sendDebug("AT");
delay(500);
if(debug.find("OK"))
{
Serial.println("RECEIVED: OK\nData ready to sent!");
Wifi_connect();
}
}

void loop() {
  // put your main code here, to run repeatedly:


    echodata1();
  delay(1000);
  

    

}
void echodata1(){
// ESP8266 Client
String cmd = "AT+CIPSTART=\"TCP\",\"";// Setup TCP connection
cmd += IP;
cmd += "\",80";
sendDebug(cmd);
delay(200);
if( debug.find( "Error" ) )
    {
        Serial.print( "RECEIVED: Error\nExit1" );
        return;
    }
    cmd = GET+"\r\n";

Serial.print( "AT+CIPSEND=" );
Serial.println(cmd.length() );

     debug.print( "AT+CIPSEND=" );
    debug.println( cmd.length());

   if(debug.find( ">" ) )
    {
        Serial.print(">");
        Serial.print(cmd);
        debug.println(cmd);

                if(debug.find("x</td><td>0")) {
          Serial.println("x0");
      servoY.write(0);
    }else if(debug.find("x</td><td>90")) {
          Serial.println("x90");
      servoY.write(90);
    }else{
        Serial.println("x180");
      servoY.write(180);
      }
 
      }
    
     else
    {
      Serial.println("ok");
        debug.println( "AT+CIPCLOSE" );
      
    }   
    if( debug.find("CLOSE") )
    {
        Serial.println( "RECEIVED: OK" );  
  
    }
    else
    {
       Serial.println( "OK" );
      
          debug.println( "AT+CIPCLOSE" );
      
    }
    
  }
 
void sendDebug(String cmd)
{
Serial.print("SEND: ");
Serial.println(cmd);
debug.println(cmd);
}
void Wifi_connect()
{
    String cmd="AT+CWJAP=\"";
    cmd+=SSID;
    cmd+="\",\"";
    cmd+=PASS;
    cmd+="\"";
    sendDebug(cmd);
    Loding("Wifi_connect");
}
void Loding(String state){
    for (int timeout=0 ; timeout<10 ; timeout++)
    {
      if(debug.find("OK"))
      {
          Serial.println("RECEIVED: OK");
          break;
      }
      else if(timeout==9){
        Serial.print( state );
        Serial.println(" fail...\nExit3");
      }
      else
      {
        Serial.print("Wifi Loading...");
        delay(500);
      }
    }
}
