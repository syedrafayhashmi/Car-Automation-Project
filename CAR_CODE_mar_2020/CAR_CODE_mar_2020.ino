const int headlight = 23;
const int horn = 22;
const int indicators = 21;
const int doors = 19;
const int ignition = 18;
const int selfstart = 5;
//const int diggy = 4;

int del = 0;

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
  //pinMode(diggy, OUTPUT);
  //digitalWrite(diggy, LOW);       //7
  
  
  
 }

void loop() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
   int ip =  SerialBT.read();
   Serial.println(ip);
   
  if (ip == 3)
  {digitalWrite(headlight, !digitalRead(headlight));
  }
 
  if (ip == 0)
  {digitalWrite(RELAY1, LOW);
   digitalWrite(RELAY2, HIGH);
   
  } 
  if (ip > 2)
   {
    del = ip*1000;
   }
  if (ip == 2)
  {   
    digitalWrite(RELAY3,HIGH);
    Serial.println(del);
    delay(del);
    digitalWrite(RELAY3,LOW);
    }
}
}
