const int headlight = 23;
const int horn = 22;
const int indicators = 21;
const int doors = 19;
const int ignition = 18;
const int selfstart = 5;
const int trunk = 4;

int del = 3;

#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("CarESP32"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  pinMode(headlight, OUTPUT);
  digitalWrite(headlight, LOW);   //1
  pinMode(horn, OUTPUT);
  digitalWrite(horn, LOW);        //2
  pinMode(indicators, OUTPUT);
  digitalWrite(indicators, LOW);  //3
  pinMode(doors, OUTPUT);
  digitalWrite(doors, LOW);       //4
  pinMode(ignition, OUTPUT);
  digitalWrite(ignition, LOW);    //5
  pinMode(selfstart, OUTPUT);
  digitalWrite(selfstart, LOW);   //6
  pinMode(trunk, OUTPUT);
  digitalWrite(trunk, LOW);       //7
  
  
  
 }

void loop() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
   int ip =  SerialBT.read();
   Serial.println(ip);
   
  if (ip == 125)
  {
    digitalWrite(doors,LOW);
  }
  if (ip == 123)
  {
    digitalWrite(doors,HIGH);
  }
  if (ip == 126)
  {
    digitalWrite(headlight, !digitalRead(headlight));
  }
  if (ip == 124)
  {
    digitalWrite(horn, !digitalRead(horn));
  }
  if (ip == 120)
  {
    digitalWrite(indicators, !digitalRead(indicators));
  }
  if (ip == 119)
  {
    digitalWrite(trunk, !digitalRead(trunk));
  }
  if (ip == 121)
  {
    if (del == 0){
      del = 3;
    }
    digitalWrite(ignition, HIGH);
    delay(3000);
    digitalWrite(selfstart,HIGH);
    delay((del*1000));
    digitalWrite(selfstart,LOW); 
  }
  if (ip == 122)
    {
    digitalWrite(selfstart,LOW)
    } 
}
}
