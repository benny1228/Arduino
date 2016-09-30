#include<SoftwareSerial.h>
#include <Servo.h>
Servo servo;
Servo myservo;
SoftwareSerial BTSerial(8, 9);
int i;
int val;
  


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println( "Enter AT commands:");
BTSerial.begin(9600);
servo.attach(12);
myservo.attach(4);
   myservo.write(90);
   servo.write(90);
}

void loop() {
  // put your main code here, to run repeatedly:


  val = BTSerial.read();
  delay(10); 
//int data=int(val);
/*if(val=='-'){
  Serial.print("no");
   servo.write(10);
  }else{
    Serial.print("yes");
     servo.write(170);
    }*/
 Serial.println(val);


/*String s;
switch(data){
  case 45:
  s="-";
  servo.write(10);
  myservo.write(10);
  break;
  case 43:
  s="+";
    servo.write(180);
  myservo.write(180);
  break;
  case 46:
  s=".";
  break;
  case 48:
  s="0";
  break;
  case 49:
  s="1";
  break;
   case 50:
  s="2";
  break;
   case 51:
  s="3";
  break;
   case 52:
  s="4";
  break;
   case 53:
  s="5";
  break;
   case 54:
  s="6";
  break;
   case 55:
  s="7";
  break;
   case 56:
  s="8";
  break;
   case 57:
  s="9";
  break;
  }*/



    
    

 

    

  
      

  }




