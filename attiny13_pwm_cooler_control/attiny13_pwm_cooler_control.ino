//attiny13 pwm control

#define motor 0
#define button 4

uint8_t pwm[4]={70,150,200,255};
uint8_t scale = 0;
//unsigned long t;


void setup() {
  pinMode(motor,OUTPUT);
  pinMode(button,INPUT);
  digitalWrite(button,HIGH);
}

void loop() {
  if(!digitalRead(button)){
    delay(100);
    if(!digitalRead(button)){
      scale++;
      if(scale>=4) scale = 0;
      analogWrite(motor,pwm[scale]);
    }
  }
  delay(400);
}//loop
