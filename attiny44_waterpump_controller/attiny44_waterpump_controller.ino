//water pump controller v1
#define relay 4
#define sensor 0

uint8_t pins[4]={6,7,8};
uint8_t values[4]={70,110,150};
bool leds[3]={false,false,false};
unsigned long t,t1;
const long interval=500;
boolean relay_state=false;
uint8_t water_level=0 ,i,j=0;

void setup() {
  for(i=0;i<3;i++){pinMode(pins[i],OUTPUT);}
  pinMode(relay,OUTPUT);
  pinMode(sensor,INPUT);
  //analogReference(INTERNAL);
  analogReference(DEFAULT);
}

void loop() {
  t=millis();
  if (t-t1>=interval){
    t1=t; 
    
    water_level=analogRead(sensor);
    if(water_level<=70){
      relay_state=true;
    } 
    if(water_level>=150){
      relay_state=false;
    }

    for(i=0;i<3;i++){
      if(water_level>=values[i]){
        leds[i]=true;
      } else {
        leds[i]=false;
      }
    }

    
  }//if interval
  digitalWrite(relay,relay_state);
  for(i=0;i<3;i++){digitalWrite(pins[i],leds[i]);}
}//loop
