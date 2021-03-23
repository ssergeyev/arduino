//attiny13 impulsnik

//Out pin 5 main load(PB0/0/MOSI/OC0A)
//In pin 2 potentiometer (PB3/ADC3/A3/3/CLKI)
//Out pin 3 potentiometer enable (PB4/ADC2/A2/4)
//In pin 7 button (PB2/A1/2/SCK/ADC1)


#define out 0
#define button 2
#define pot 3
#define pot_enable 4

uint16_t value;
volatile uint8_t pwm,k;

void setup(){
  pinMode(out, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(pot,INPUT);
  pinMode(pot_enable,OUTPUT);
  digitalWrite(pot_enable,HIGH);
  k=5;
}

void loop(){
  value=analogRead(pot);
/*
  if(!digitalRead(button)){
    if(k<9){k+=2;}else{k=1;}
    delay(200);
  }
*/  
  pwm=value/8;
  digitalWrite(out,HIGH);
  delay(2+(pwm*k)/5);
  digitalWrite(out,LOW);
  delay(2+(pwm*(10-k))/5);
}
