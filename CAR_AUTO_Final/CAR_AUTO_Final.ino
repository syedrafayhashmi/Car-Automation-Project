const int DOOR1 = 15;
const int DOOR2 = 2;
const int DOOR3 = 4;
const int DOOR4 = 16;
#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
   pinMode(DOOR1, OUTPUT);
  digitalWrite(DOOR1  ,LOW);
  pinMode(DOOR2, OUTPUT);
  digitalWrite(DOOR2  ,LOW);
  pinMode(DOOR3, OUTPUT);
  digitalWrite(DOOR3  ,LOW);
  pinMode(DOOR3, OUTPUT);
  digitalWrite(DOOR1  ,LOW);
}

void loop() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
   int ip =  SerialBT.read();
   //DOOR 1
  if (ip == 1)
  {digitalWrite(DOOR1, HIGH);}  
  if (ip == 2)
  {digitalWrite(DOOR1, LOW);} 
  //DOOR 2
  if (ip == 3)
  {digitalWrite(DOOR2, HIGH);}  
  if (ip == 4)
  {digitalWrite(DOOR2, LOW);}    
  //DOOR 3
  if (ip == 5)
  {digitalWrite(DOOR3, HIGH);}  
  if (ip == 6)
  {digitalWrite(DOOR3, LOW);} 
  //DOOR 4
  if (ip == 7)
  {digitalWrite(DOOR4, HIGH);}  
  if (ip == 8)
  {digitalWrite(DOOR4, LOW);} 
  //ALL DOORS
  if (ip == 9)
  {digitalWrite(DOOR1, HIGH);
   digitalWrite(DOOR2, HIGH);
   digitalWrite(DOOR3, HIGH);
   digitalWrite(DOOR4, HIGH);
  }  
  if (ip == 0)
  {digitalWrite(DOOR1, LOW);
   digitalWrite(DOOR2, LOW);
   digitalWrite(DOOR3, LOW);
   digitalWrite(DOOR4, LOW);
  } 
}
delay(20);
}
