const int ignition = 2;
const int selfstart = 15;

int del  = 10;
int count = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(ignition, OUTPUT);
  digitalWrite(ignition, LOW);    //5
  pinMode(selfstart, OUTPUT);
  digitalWrite(selfstart, LOW);   //6
}

void loop() {
 for(int i=1;i<del*2+1;i++)
 {
   Serial.printf("iteration:%d",i);
   Serial.print("\n");
  count+=1;
  if (count == del*2){
    Serial.printf("count:%d",count);
    Serial.print("\n");
    count = 0;
    break;}
  
  
  delay(500);
  } 
    
  
}
