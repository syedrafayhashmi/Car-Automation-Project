const int RELAY1 = 15;  //for door lock relay 1 and 2
const int RELAY2 = 2;
const int RELAY3 = 0;  //for car self
int del = 0;

#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
   pinMode(RELAY1, OUTPUT);
  digitalWrite(RELAY1  ,HIGH);
  pinMode(RELAY2, OUTPUT);
  digitalWrite(RELAY2  ,LOW);
  pinMode(RELAY3,OUTPUT);
  digitalWrite(RELAY3,LOW);
 }

void loop() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
   int ip =  SerialBT.read();
   Serial.println(ip);
   
  //ALL DOORS
  if (ip == 1)
  {digitalWrite(RELAY1, HIGH);
   digitalWrite(RELAY2, LOW);
   
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
delay(20);
}
