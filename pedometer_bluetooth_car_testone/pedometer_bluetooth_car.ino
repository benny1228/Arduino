#include<SoftwareSerial.h>
#include<Servo.h>

 Servo servoRight;
 Servo servoLeft;
 SoftwareSerial BTSerial(10, 11);
 char c;
 char cmmd;
 byte var;
void setup() {
  // put your setup code here, to run once:
servoRight.attach(12);
servoLeft.attach(13);
BTSerial.begin(9600);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int insize;   
if(BTSerial.available()){
 
//cmmd=BTSerial.read();


var = BTSerial.read();
  


/*if(cmmd[16]==0){
  
  }*/

Serial.println(var);
 switch(cmmd){
  case 97:
  forward(1000);
  //Serial.print("A");
  break;
   case 100:
    trunLeft(400);
    break;
    case 98:
    trunRight(400);
    break;
    case 99:
    backward(400);
    //Serial.print("C");
    break;
    case 101:
    bestop(400);
    break;
  }
  }
}

void forward(int time){
  servoRight.writeMicroseconds(1700);
  servoLeft.writeMicroseconds(1300);
  delay(time);
  }
void trunLeft(int time){
  servoRight.writeMicroseconds(1300);
  servoLeft.writeMicroseconds(1300);
  delay(time);
  }
 void trunRight(int time){
  servoRight.writeMicroseconds(1700);
  servoLeft.writeMicroseconds(1700);
  delay(time);
  } 
 void backward(int time){
    servoRight.writeMicroseconds(1300);
     servoLeft.writeMicroseconds(1700);
     delay(time);
  } 
 void bestop(int time){
  servoRight.write(1525);
  servoLeft.write(1525);
  delay(time);
  } 
