//attiny13 pwm control

#define blue 0
#define green 1
#define pot 3

uint8_t s_blue = 0;
uint8_t s_green = 255;
int pos;

void setup() {
  pinMode(blue,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(pot,INPUT);
}

void loop() {
  pos=analogRead(pot);
  //s_blue=map(pos,0,1023,0,255);
  //s_green=map(pos,0,1023,255,0);
  s_blue=pos/4;
  s_green=(pos/-4)+255;
  
  analogWrite(blue,s_blue);
  analogWrite(green,s_blue);
  //delay(100);
}//loop
