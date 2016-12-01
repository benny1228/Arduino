#include<SoftwareSerial.h>
#include<Servo.h>

 Servo servoRight;
 Servo servoLeft;
 Servo servoY;
 SoftwareSerial BTSerial(10, 11);
 char c;
void setup() {
  // put your setup code here, to run once:
servoRight.attach(12);
servoLeft.attach(13);
servoY.attach(4);
BTSerial.begin(9600);
Serial.begin(9600);
}
char var[35];

void loop() {
  // put your main code here, to run repeatedly:
  int insize;
  char cmd ;
  int i = 0;
if(BTSerial.available()){

while(i<34){
  var[i]=BTSerial.read();
  i++;
  }
 

Serial.println(var);

Serial.println(var[0]);

Serial.println(var[1]);

Serial.println(var[2]);

if(var[0]='0'){
  if(var[1]='0'){
    if(var[2]='0'){
      servoY.write(0);
      }else if(var[2]='1'){
      servoY.write(1);
        }else if(var[2]='2'){
           servoY.write(2);
          }else if(var[2]='3'){
             servoY.write(3);
             }
    }
  }


/* switch(cmmd[0]){
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
  }*/
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
