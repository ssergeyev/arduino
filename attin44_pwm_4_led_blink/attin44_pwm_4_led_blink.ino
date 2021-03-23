#define l1 6 //yellow
#define l2 5 //red
#define l3 8 //left
#define l4 7 //right

unsigned long t,t1=0,w=1;
uint8_t l[4]={7,8,5,6};  //led 
uint8_t v[4]={1,80,160,240}; //pwm value
uint8_t d[4]={1,1,1,1};  //direction
uint8_t s[4]={1,1,1,1};  //step

void setup() {
   for(int i=0;i<4;i++)pinMode (l[i],OUTPUT);
}

void loop() {
  t=millis();
  if(t-t1>w){
    t1=t;
    for(int i=0;i<=4;i++){
      if (d[i]==0) {if(v[i]>(2+s[i])) {v[i]-=s[i];} else {d[i]=1;}}
      if (d[i]==1) {if(v[i]<=(254-s[i])) {v[i]+=s[i];} else {d[i]=0;}}
    }
  } // if time out

  for(int i=0;i<=4;i++) analogWrite(l[i],v[i]);

}// loop
