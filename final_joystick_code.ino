#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // RX, TX


void setup() {
  // put your setup code here, to run once:
//  pinMode(5, OUTPUT);
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop()
{
 // digitalWrite(5, HIGH);
  if (analogRead(A0) > 1000)
  {
    mySerial.println('F');
    Serial.println('F');
  }
  if (450<analogRead(A0) and analogRead(A0)<550 and 450<analogRead(A1) and analogRead(A0)<550 )
  {
    mySerial.println('S');
    Serial.println('S');
  }
  if (analogRead(A0) < 300)
  {
    mySerial.println('B');
    Serial.println('B');
  }

  if (analogRead(A1) > 1000)
  {
    mySerial.println('L');
    Serial.println('L');
  }

  if (analogRead(A1) < 200)
  {
    mySerial.println('R');
    Serial.println('R');
  }
}





























































































































































































































































































































