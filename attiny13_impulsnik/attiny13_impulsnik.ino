//attiny13 impulsnik

//Out pin 5 main load(PB0/0/MOSI/OC0A)
//In pin 2 potentiometer (PB3/ADC3/A3/3/CLKI)
//In pin 7 button (PB2/A1/2/SCK/ADC1)

#define out 0
#define button 2
#define pot 3


uint8_t value,pwm;

void setup(){
  pinMode(out, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(pot,INPUT);
}

void loop(){
  value=analogRead(pot);
  pwm=map(value,0,1023,0,255);
  analogWrite(out,pwm);
}






/*
bool status = false;
float count1=0;
float scale=3200;
float shift=128;
uint16_t r,t;
uint8_t p=0;

void setup() {
  pinMode(0,OUTPUT);
  pinMode(3,INPUT);
}

void loop() {
  r=analogRead(3);
/*  
  count1++;
  
  if(r>512){t=r-512;}
  if(r<512){t=1+(1/r);}
  shift=t;
/*  
  if(!status && count1>=shift && count1<=shift+10){
    status=true;
  }
  
  if(status && count1>=scale){
    status=false;
    count1=0;
  }
  digitalWrite(0,status);
*/
*/

/*
  p=map(r,0,4096,0,255);
  analogWrite(0,p);
}//loop
