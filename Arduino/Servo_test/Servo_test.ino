#include <Servo.h>

Servo servo1;
Servo servo2;

void setup() {
  // put your setup code here, to run once:
  servo1.attach(2);
  servo2.attach(3);
  pinMode(52,OUTPUT);
  digitalWrite(52,HIGH);
  pinMode(53,OUTPUT);
  digitalWrite(53,HIGH);
  Serial.begin(57600);
}
int incomingBytes[11];
void loop() {
  // put your main code here, to run repeatedly:
  // have to send 0SXRXXGXXBXX
  // include leading zero as stopgap
  if (Serial.available() > 0) {
    // read the incoming byte:
    readSerial();

    // say what you got:
    for(int x = 0; x < 11; x++){
      Serial.print("I received: ");
      Serial.println(char(incomingBytes[x]));
    }
  }
}

void readSerial(){
  incomingBytes[0] = Serial.read();
  delay(2); //necessary because serial read executes as soon as data arrives, second runs before second bit gets here
  incomingBytes[1] = Serial.read();
  incomingBytes[2] = Serial.read();
  incomingBytes[3] = Serial.read();
  incomingBytes[4] = Serial.read();
  incomingBytes[5] = Serial.read();
  incomingBytes[6] = Serial.read();
  incomingBytes[7] = Serial.read();
  incomingBytes[8] = Serial.read();
  incomingBytes[9] = Serial.read();
  incomingBytes[10] = Serial.read();
}

