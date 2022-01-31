#define m 8
#define r 9
#define g 10
#define b 11

int state_r=255, state_g=255, state_b=0;
long t1,t2; 
void setup() {
  // put your setup code here, to run once:
  pinMode(m,OUTPUT);
  digitalWrite(m,HIGH);

  pinMode(r,OUTPUT);
  analogWrite(r,state_r);

  pinMode(g,OUTPUT);
  digitalWrite(g,state_g);

  pinMode(b,OUTPUT);
  digitalWrite(b,state_b);
}

void loop() {
t1=millis();
  if  (t2-t1>10){
    t2=t1;
  }


}
