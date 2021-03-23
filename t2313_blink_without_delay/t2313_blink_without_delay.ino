#define l 0
unsigned long t,t1;

void setup() {
  pinMode(l,OUTPUT);
  digitalWrite(l,HIGH);
}

void loop() {
  t=millis();
  if(t-t1>500){
    digitalWrite(l,HIGH);
  }
  if(t-t1>1000){
    t1=t;
    digitalWrite(l,LOW);
  }
  for (int i=1;i<254;i++){
    analogWrite(l,i);
    delay(10);
  }
  for (int i=253; i>1;i--){
    analogWrite(l,i);
    delay(10);
  }
}
