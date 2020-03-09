const int headlight = 17;
const int horn = 16;
const int indicators = 4;
const int doors = 0;
const int ignition = 2;
const int selfstart = 15;
const int trunk = 13;
const int ir = 12;
const int car_state = 14;
int del = 3;
int count = 0;

int bypassir = 0;

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
  pinMode(ir, INPUT);
  pinMode(car_state,INPUT);
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
    if(ip == 118)
  {
    bypassir = 1;
  }
//
  if (ip == 121)
  { 
    if (del == 0){
      del = 3;
    }
    int irdata = digitalRead(ir);
    if (!irdata || bypassir)
    {  
    digitalWrite(ignition, HIGH);
    delay(3000);
    digitalWrite(selfstart,HIGH);
    //delay((del*1000));
    
    for (int i = 1; i<del*2+1;i++)
    {      
      int ip =  SerialBT.read();
       Serial.println(ip);
      count+=1;
      if (count == del*2)
      {
        count = 0;
        break;
       }
       if (ip == 122)
       {
        digitalWrite(selfstart,LOW);
       }
       delay(500);
       
    }
    digitalWrite(selfstart,LOW); 
    int car_data = digitalRead(car_state);
    // considering recieving high signal if car doesn't start
    if (car_data == 1) 
    {
      digitalWrite((ignition,LOW);
    }
  }}
  //
  if (ip == 117)
  {
    digitalWrite(ignition,LOW);
  }
   else
   {
    del = ip;
   
   }
}
}
