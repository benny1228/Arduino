#include <SoftwareSerial.h>
#include <dht.h>
#define dht_dpin 2 //定義訊號要從Pin A0 進來  




#define DEBUG FALSE //comment out to remove debug msgs

//*-- Hardware Serial

#define _baudrate 9600

//*-- Software Serial

//

#define _rxpin 4

#define _txpin 5

SoftwareSerial debug( _rxpin, _txpin ); // RX, TX

//*-- IoT Information

#define SSID "benny1228"
#define PASS "benny7669264"

#define IP "184.106.153.149" // ThingSpeak IP Address: 184.106.153.149

// GET /update?key=[THINGSPEAK_KEY]&field1=[data 1]&field2=[data 2]...;

String GET = "GET /update?api_key=AWY733DEHRN7CSGE";
dht DHT;   
void setup() {

Serial.begin( _baudrate );

debug.begin( _baudrate );

sendDebug("AT");

delay(5000);

if(debug.find("OK"))

{

Serial.println("RECEIVED: OK\nData ready to sent!");

Wifi_connect();

}

}

void loop() {
DHT.read11(dht_dpin);   //去library裡面找DHT.read11  
Serial.print("Humidity = ");   
Serial.print(DHT.humidity);   
Serial.print("% ");   
Serial.print("temperature = ");   
Serial.print(DHT.temperature);   
Serial.println("C ");   
updateTS(DHT.humidity,DHT.temperature);
delay(1000);            //每1000ms更新一次   

}

//----- update the Thingspeak string with 1 value


void updateTS( double humidity, double temperature)
{

// ESP8266 Client

String cmd = "AT+CIPSTART=\"TCP\",\"";// Setup TCP connection

cmd += IP;

cmd += "\",80";

sendDebug(cmd);

delay(2000);

if( debug.find( "Error" ) )
    {
        Serial.print( "RECEIVED: Error\nExit1" );
        return;
    }

cmd = GET + "&field1=" +humidity +"&field2="+temperature+"\r\n";

Serial.print( "AT+CIPSEND=" );

Serial.println( cmd.length() );
   debug.print( "AT+CIPSEND=" );
    debug.println( cmd.length() );

if(debug.find( ">" ) )

{

Serial.print(">");
Serial.print(cmd);
debug.print(cmd);



}

else

{

debug.print( "AT+CIPCLOSE" );//close TCP connection

}

if( debug.find("OK") )

{

Serial.println( "RECEIVED: OK" );

}

else

{

Serial.println( "RECEIVED:ok\nExit2" );

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
