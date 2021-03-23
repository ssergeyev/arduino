//attiny13 pwm control

//#define motor 0
//#define button 4

uint8_t pwm[6]={10,50,100,150,200,255};

uint8_t scale = 0;

void setup() {
  pinMode(0,OUTPUT);
  pinMode(4,INPUT);
}

void loop() {
  if(!digitalRead(4)){
    delay(10);
    scale++;
    if(scale>=6) scale = 0;
    analogWrite(0,pwm[scale]);
  }
  delay(500);
}//loop
