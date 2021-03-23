#define pwm 3
#define led 13
unsigned long t,t1,period;
boolean l;

void setup() {
  // put your setup code here, to run once:
  pinMode(pwm,OUTPUT);
  pinMode(led,OUTPUT);
  analogWrite(pwm,128);
  period=500;
}

void loop() {
t=millis();
  if(t-t1>=period){
    t1=t;
    if(l){l=false;}else{l=true;}
    digitalWrite(led,l);
  }
  
}
