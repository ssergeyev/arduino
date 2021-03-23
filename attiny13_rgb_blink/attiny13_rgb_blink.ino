//attiny13 rgb blink

uint8_t pins[3]={0,1,2}; //led pins 0,1,2 is 5,6 and 7 legg on chip
uint8_t position = 0, i;
bool leds[3]={false,false,false};
unsigned long t,t1;
const long interval=500;

void setup() {
  for(i=0;i<3;i++){pinMode(pins[i],OUTPUT);}
}

void loop() {
  t=millis();
  
  if (t-t1>=interval){
    t1=t;
    for(i=0;i<3;i++) leds[i]=false;
    if(position<3){position++;}else{position=0;}
    leds[position]=true;
  }//if interval
  
  for(i=0;i<3;i++){digitalWrite(pins[i],leds[i]);}
}//loop
