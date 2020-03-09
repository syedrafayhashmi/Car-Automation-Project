const int pinIRd = 7;

int irdata = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(pinIRd,INPUT);



}

void loop()
{ irdata = digitalRead(pinIRd);
  if(!irdata){
    Serial.println("YES"); 
  }
  
}
