#include<SoftwareSerial.h>
#include<Servo.h>

 Servo servoRight;
 Servo servoLeft;
 Servo servoY;
 SoftwareSerial BTSerial(10, 11);
 char c;
 byte cmmd;
 byte var;
 int i;
void setup() {
  // put your setup code here, to run once:
servoRight.attach(12);
servoLeft.attach(13);
servoY.attach(10);
BTSerial.begin(9600);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int insize;   
if(BTSerial.available()){
 
//cmmd=BTSerial.read();


var = BTSerial.read();
Serial.println(var);
/*if(var==176){
  if(var==89){
    if(var==48){
      if(var==48){
        if(var==48){
          servoY.write(0);
          }else if(var==49){
            servoY.write(1);
            }else if(var==50){
            servoY.write(2);
            }else if(var==51){
            servoY.write(3);
            }else if(var==52){
            servoY.write(4);
            }else if(var==53){
            servoY.write(5);
            }else if(var==54){
            servoY.write(6);
            }else if(var==55){
            servoY.write(7);
            }else if(var==56){
            servoY.write(8);
            }else if(var==57){
            servoY.write(9);
            }
        }else if(var==49){
           if(var==48){
          servoY.write(10);
          }else if(var==49){
            servoY.write(11);
            }else if(var==50){
            servoY.write(12);
            }else if(var==51){
            servoY.write(13);
            }else if(var==52){
            servoY.write(14);
            }else if(var==53){
            servoY.write(15);
            }else if(var==54){
            servoY.write(16);
            }else if(var==55){
            servoY.write(17);
            }else if(var==56){
            servoY.write(18);
            }else if(var==57){
            servoY.write(19);
            }
          }else if(var==50){
              if(var==48){
          servoY.write(20);
          }else if(var==49){
            servoY.write(21);
            }else if(var==50){
            servoY.write(22);
            }else if(var==51){
            servoY.write(23);
            }else if(var==52){
            servoY.write(24);
            }else if(var==53){
            servoY.write(25);
            }else if(var==54){
            servoY.write(26);
            }else if(var==55){
            servoY.write(27);
            }else if(var==56){
            servoY.write(28);
            }else if(var==57){
            servoY.write(29);
            }
            }else if(var==51){
               if(var==48){
          servoY.write(30);
          }else if(var==49){
            servoY.write(31);
            }else if(var==50){
            servoY.write(32);
            }else if(var==51){
            servoY.write(33);
            }else if(var==52){
            servoY.write(34);
            }else if(var==53){
            servoY.write(35);
            }else if(var==54){
            servoY.write(36);
            }else if(var==55){
            servoY.write(37);
            }else if(var==56){
            servoY.write(38);
            }else if(var==57){
            servoY.write(39);
            }
              }else if(var==52){
                 if(var==48){
          servoY.write(40);
          }else if(var==49){
            servoY.write(41);
            }else if(var==50){
            servoY.write(42);
            }else if(var==51){
            servoY.write(43);
            }else if(var==52){
            servoY.write(44);
            }else if(var==53){
            servoY.write(45);
            }else if(var==54){
            servoY.write(46);
            }else if(var==55){
            servoY.write(47);
            }else if(var==56){
            servoY.write(48);
            }else if(var==57){
            servoY.write(49);
            }
                }else if(var==53){
                   if(var==48){
          servoY.write(50);
          }else if(var==49){
            servoY.write(51);
            }else if(var==50){
            servoY.write(52);
            }else if(var==51){
            servoY.write(53);
            }else if(var==52){
            servoY.write(54);
            }else if(var==53){
            servoY.write(55);
            }else if(var==54){
            servoY.write(56);
            }else if(var==55){
            servoY.write(57);
            }else if(var==56){
            servoY.write(58);
            }else if(var==57){
            servoY.write(59);
            }
                  }else if(var==54){
                     if(var==48){
          servoY.write(60);
          }else if(var==49){
            servoY.write(61);
            }else if(var==50){
            servoY.write(62);
            }else if(var==51){
            servoY.write(63);
            }else if(var==52){
            servoY.write(64);
            }else if(var==53){
            servoY.write(65);
            }else if(var==54){
            servoY.write(66);
            }else if(var==55){
            servoY.write(67);
            }else if(var==56){
            servoY.write(68);
            }else if(var==57){
            servoY.write(69);
            }
                    }else if(var==55){
                       if(var==48){
          servoY.write(70);
          }else if(var==49){
            servoY.write(71);
            }else if(var==50){
            servoY.write(72);
            }else if(var==51){
            servoY.write(73);
            }else if(var==52){
            servoY.write(74);
            }else if(var==53){
            servoY.write(75);
            }else if(var==54){
            servoY.write(76);
            }else if(var==55){
            servoY.write(77);
            }else if(var==56){
            servoY.write(78);
            }else if(var==57){
            servoY.write(79);
            }
                      }else if(var==56){
                         if(var==48){
          servoY.write(80);
          }else if(var==49){
            servoY.write(81);
            }else if(var==50){
            servoY.write(82);
            }else if(var==51){
            servoY.write(83);
            }else if(var==52){
            servoY.write(84);
            }else if(var==53){
            servoY.write(85);
            }else if(var==54){
            servoY.write(86);
            }else if(var==55){
            servoY.write(87);
            }else if(var==56){
            servoY.write(88);
            }else if(var==57){
            servoY.write(89);
            }
                        }else if(var==57){
                           if(var==48){
          servoY.write(90);
          }else if(var==49){
            servoY.write(91);
            }else if(var==50){
            servoY.write(92);
            }else if(var==51){
            servoY.write(93);
            }else if(var==52){
            servoY.write(94);
            }else if(var==53){
            servoY.write(95);
            }else if(var==54){
            servoY.write(96);
            }else if(var==55){
            servoY.write(97);
            }else if(var==56){
            servoY.write(98);
            }else if(var==57){
            servoY.write(99);
            }
                          }
      }else if(var==49){
         if(var==48){
        if(var==48){
          servoY.write(100);
          }else if(var==49){
            servoY.write(101);
            }else if(var==50){
            servoY.write(102);
            }else if(var==51){
            servoY.write(103);
            }else if(var==52){
            servoY.write(104);
            }else if(var==53){
            servoY.write(105);
            }else if(var==54){
            servoY.write(106);
            }else if(var==55){
            servoY.write(107);
            }else if(var==56){
            servoY.write(108);
            }else if(var==57){
            servoY.write(109);
            }
        }else if(var==49){
           if(var==48){
          servoY.write(110);
          }else if(var==49){
            servoY.write(111);
            }else if(var==50){
            servoY.write(112);
            }else if(var==51){
            servoY.write(113);
            }else if(var==52){
            servoY.write(114);
            }else if(var==53){
            servoY.write(115);
            }else if(var==54){
            servoY.write(116);
            }else if(var==55){
            servoY.write(117);
            }else if(var==56){
            servoY.write(118);
            }else if(var==57){
            servoY.write(119);
            }
          }else if(var==50){
              if(var==48){
          servoY.write(120);
          }else if(var==49){
            servoY.write(121);
            }else if(var==50){
            servoY.write(122);
            }else if(var==51){
            servoY.write(123);
            }else if(var==52){
            servoY.write(124);
            }else if(var==53){
            servoY.write(125);
            }else if(var==54){
            servoY.write(126);
            }else if(var==55){
            servoY.write(127);
            }else if(var==56){
            servoY.write(128);
            }else if(var==57){
            servoY.write(129);
            }
            }else if(var==51){
               if(var==48){
          servoY.write(130);
          }else if(var==49){
            servoY.write(131);
            }else if(var==50){
            servoY.write(132);
            }else if(var==51){
            servoY.write(133);
            }else if(var==52){
            servoY.write(134);
            }else if(var==53){
            servoY.write(135);
            }else if(var==54){
            servoY.write(136);
            }else if(var==55){
            servoY.write(137);
            }else if(var==56){
            servoY.write(138);
            }else if(var==57){
            servoY.write(139);
            }
              }else if(var==52){
                 if(var==48){
          servoY.write(140);
          }else if(var==49){
            servoY.write(141);
            }else if(var==50){
            servoY.write(142);
            }else if(var==51){
            servoY.write(143);
            }else if(var==52){
            servoY.write(144);
            }else if(var==53){
            servoY.write(145);
            }else if(var==54){
            servoY.write(146);
            }else if(var==55){
            servoY.write(147);
            }else if(var==56){
            servoY.write(148);
            }else if(var==57){
            servoY.write(149);
            }
                }else if(var==53){
                   if(var==48){
          servoY.write(150);
          }else if(var==49){
            servoY.write(151);
            }else if(var==50){
            servoY.write(152);
            }else if(var==51){
            servoY.write(153);
            }else if(var==52){
            servoY.write(154);
            }else if(var==53){
            servoY.write(155);
            }else if(var==54){
            servoY.write(156);
            }else if(var==55){
            servoY.write(157);
            }else if(var==56){
            servoY.write(158);
            }else if(var==57){
            servoY.write(159);
            }
                  }else if(var==54){
                     if(var==48){
          servoY.write(160);
          }else if(var==49){
            servoY.write(161);
            }else if(var==50){
            servoY.write(162);
            }else if(var==51){
            servoY.write(163);
            }else if(var==52){
            servoY.write(164);
            }else if(var==53){
            servoY.write(165);
            }else if(var==54){
            servoY.write(166);
            }else if(var==55){
            servoY.write(167);
            }else if(var==56){
            servoY.write(168);
            }else if(var==57){
            servoY.write(169);
            }
                    }else if(var==55){
                       if(var==48){
          servoY.write(170);
          }else if(var==49){
            servoY.write(171);
            }else if(var==50){
            servoY.write(172);
            }else if(var==51){
            servoY.write(173);
            }else if(var==52){
            servoY.write(174);
            }else if(var==53){
            servoY.write(175);
            }else if(var==54){
            servoY.write(176);
            }else if(var==55){
            servoY.write(177);
            }else if(var==56){
            servoY.write(178);
            }else if(var==57){
            servoY.write(179);
            }
                      }else if(var==56){
                         if(var==48){
          servoY.write(180);
          }
        }
    }
  }
}*/


/** switch(cmmd){
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
