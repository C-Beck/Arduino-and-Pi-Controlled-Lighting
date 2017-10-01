#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;

void setup() {
  // put your setup code here, to run once:
  servo1.attach(2);
  servo2.attach(3);
  servo3.attach(4);
  servo1.write(45);
  servo2.write(45);
  servo3.write(45);
  pinMode(52,OUTPUT);
  digitalWrite(52,HIGH);
  pinMode(53,OUTPUT);
  digitalWrite(53,HIGH);
  Serial.begin(57600);
}
char incomingBytes[11];
int servoPos = 0;
int ledR = 0;
int ledG = 0;
int ledB = 0;
void loop() {
  // put your main code here, to run repeatedly:
  // have to send SXRXXGXXBXX
  if (Serial.available() > 0) {
    // read the incoming byte:
    readSerial();

    // say what you got:
    for(int x = 0; x < 11; x++){
      Serial.print("I received: ");
      Serial.println(incomingBytes[x]);
    }
    dataParse();
    setServos();
  }
}

void readSerial(){
  incomingBytes[0] = char(Serial.read());
  delay(2); //necessary because serial read executes as soon as data arrives, second runs before second bit gets here
  incomingBytes[1] = char(Serial.read());
  incomingBytes[2] = char(Serial.read());
  incomingBytes[3] = char(Serial.read());
  incomingBytes[4] = char(Serial.read());
  incomingBytes[5] = char(Serial.read());
  incomingBytes[6] = char(Serial.read());
  incomingBytes[7] = char(Serial.read());
  incomingBytes[8] = char(Serial.read());
  incomingBytes[9] = char(Serial.read());
  incomingBytes[10] = char(Serial.read());
}

void dataParse(){
  String str(incomingBytes);
  char temp1[5];
  str.substring(str.indexOf("S")+1,str.indexOf("S")+2).toCharArray(temp1,5);
  servoPos = strtol(temp1,NULL,16);
  char temp2[5];
  str.substring(str.indexOf("R")+1,str.indexOf("R")+3).toCharArray(temp2,5);
  ledR = strtol(temp2,NULL,16);
  char temp3[5];
  str.substring(str.indexOf("G")+1,str.indexOf("G")+3).toCharArray(temp3,5);
  ledG = strtol(temp3,NULL,16);
  char temp4[5];
  str.substring(str.indexOf("U")+1,str.indexOf("U")+3).toCharArray(temp4,5);
  ledB = strtol(temp4,NULL,16);
  Serial.println(servoPos);
  Serial.println(ledR);
  Serial.println(ledG);
  Serial.println(ledB);
}

void setServos(){
  switch(servoPos){
    case 0:
      servo1.write(45);
      servo2.write(45);
      servo3.write(45);
      break;
    case 1:
      servo1.write(135);
      servo2.write(45);
      servo3.write(45);
      break;
    case 2:
      servo1.write(45);
      servo2.write(135);
      servo3.write(45);
      break;
    case 3:
      servo1.write(135);
      servo2.write(135);
      servo3.write(45);
      break;
    case 4:
      servo1.write(45);
      servo2.write(45);
      servo3.write(135);
      break;
    case 5:
      servo1.write(135);
      servo2.write(45);
      servo3.write(135);
      break;
    case 6:
      servo1.write(45);
      servo2.write(135);
      servo3.write(135);
      break;
    case 7:
      servo1.write(135);
      servo2.write(135);
      servo3.write(135);
      break;
  }
}

