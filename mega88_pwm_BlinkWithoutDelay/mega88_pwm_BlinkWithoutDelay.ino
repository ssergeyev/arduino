const int ledPin =  LED_BUILTIN;// the number of the LED pin
#define l4 4
#define l12 12
#define l13 13


unsigned long t,t1=0,t2=0,w=100,w2=2000;
uint8_t l[6]={3,5,6,9,10,11};  //led 
uint8_t v[6]={1,40,80,140,180,220}; //pwm value
uint8_t d[6]={1,1,1,1,1,1};  //direction
uint8_t s[6]={1,1,1,1,1,1};  //step

void setup() {
   for(int i=0;i<=6;i++)pinMode (l[i],OUTPUT);
  pinMode(l4,OUTPUT);
  pinMode(l12,OUTPUT);
  pinMode(l13,OUTPUT);
}

void loop() {
  t=millis();
  if(t-t1>w){
    t1=t;
    for(int i=0;i<=6;i++){
      if (d[i]==0) {if(v[i]>(2+s[i])) {v[i]-=s[i];} else {d[i]=1;}}
      if (d[i]==1) {if(v[i]<=(254-s[i])) {v[i]+=s[i];} else {d[i]=0;}}
    }
  } // if time out

  if(t-t2>w2){
    t2=t;
    digitalWrite(l12,!digitalRead(l12));
  }

  for(int i=0;i<=6;i++) analogWrite(l[i],v[i]);


}// loop
