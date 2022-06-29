#define LF A0
#define LR A2
#define RF A4
#define RR A5
char t;
#define light_FL  3    //LED Front Right   pin A0 for Arduino Uno 
#define horn_Buzz 5  
void setup() {
pinMode(A0,OUTPUT);   //left motors forward
pinMode(A2,OUTPUT);   //left motors reverse
pinMode(A4,OUTPUT);   //right motors forward
pinMode(A5,OUTPUT);//right motors reverse
pinMode(light_FL, OUTPUT);
pinMode(horn_Buzz, OUTPUT);
//Led
Serial.begin(9600);
 
}
 
void loop() {
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
if(t == 'F'){            //move forward(all motors rotate in forward direction)
  digitalWrite(LF,HIGH);
  digitalWrite(RF,HIGH);
  digitalWrite(LR,LOW);
  digitalWrite(RR,LOW);
}
 
else if(t == 'B'){      //move reverse (all motors rotate in reverse direction)
  digitalWrite(LR,HIGH);
  digitalWrite(RR,HIGH);
  digitalWrite(LF,LOW);
  digitalWrite(RF,LOW);
}
 
else if(t == 'L'){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  digitalWrite(LF,HIGH);
  digitalWrite(LR,LOW);
  digitalWrite(RR,LOW);
  digitalWrite(RF,LOW);
}
 
else if(t == 'R'){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
  digitalWrite(RF,HIGH);
  digitalWrite(LR,LOW);
  digitalWrite(RR,LOW);
  digitalWrite(LF,LOW);
}

else if(t == 'W'){    //turn led on or off)
  digitalWrite(light_FL ,HIGH);
}
else if(t == 'w'){
  digitalWrite(light_FL ,LOW);
} 
else if(t == 'V'){    //turn led on or off)
  digitalWrite(horn_Buzz ,HIGH);
}
else if(t == 'v'){
  digitalWrite(horn_Buzz ,LOW);
}
 
else if(t == 'S'){      //STOP (all motors stop)
  digitalWrite(LF,LOW);
  digitalWrite(LR,LOW);
  digitalWrite(RF,LOW);
  digitalWrite(RR,LOW);
}
//delay(100);
}
