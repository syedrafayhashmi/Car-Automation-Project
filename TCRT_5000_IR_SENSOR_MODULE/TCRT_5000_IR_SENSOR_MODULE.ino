const int pinIRd = 15;
const int pinIRa = A0;
//const int pinLED = 9;
int IRvalueA = 0;
int IRvalueD = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(pinIRd,INPUT);
  pinMode(pinIRa,INPUT);
 // pinMode(pinLED,OUTPUT);

}

void loop()
{
  Serial.print("Analog Reading=");
  Serial.print(IRvalueA);
  Serial.print("\t Digital Reading=");
  Serial.println(IRvalueD);
  delay(500);
  
  IRvalueA = analogRead(pinIRa);
  IRvalueD = digitalRead(pinIRd);
}
