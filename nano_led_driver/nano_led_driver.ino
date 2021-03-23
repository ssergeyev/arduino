#define led 3
#define plus A0
#define pot A1
#define minus A2

void setup() {
  // put your setup code here, to run once:
  pinMode (led,OUTPUT);
  pinMode (plus,OUTPUT);
  pinMode (minus,OUTPUT);
  pinMode (pot,INPUT);
  digitalWrite(plus,HIGH);
  digitalWrite(minus,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  uint16_t level;
  level = map (analogRead(pot),0,1023,0,255);
  analogWrite(led,level);

}
