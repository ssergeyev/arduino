#define a1 8
#define a2 9
#define b1 10
#define b2 11
#define pot A0

unsigned long t,t1,ta1,ta2,tb1,tb2;
boolean statusa1,statusa2,statusb1,statusb2;
int step;


void setup() {
  pinMode(a1,OUTPUT);
  pinMode(a2,OUTPUT);
  pinMode(b1,OUTPUT);
  pinMode(b2,OUTPUT);
  pinMode(pot,INPUT);
  digitalWrite(a1,LOW);
  digitalWrite(a2,LOW);
  digitalWrite(b1,LOW);
  digitalWrite(b2,LOW);
  step=100;
}

void loop() {
t=millis();

  digitalWrite(b2,HIGH);
  delay(1);
  digitalWrite(b2,LOW);
  delay(1);
   
  
  //step=map(analogRead(pot),0,1023,0,100);;
  /*
  digitalWrite(a2,LOW);
  digitalWrite(a1,HIGH);
  delay(step);
  digitalWrite(b1,LOW);
  digitalWrite(a2,HIGH);
  delay(step);
  digitalWrite(a1,LOW);
  digitalWrite(b1,HIGH);
  delay(step);
*/
}
