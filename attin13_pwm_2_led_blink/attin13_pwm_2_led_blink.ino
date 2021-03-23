#define l1 0
#define l2 1

unsigned long t=0,t1=0,w=1;
uint8_t v1=1,d1=1,s1=3,v2=255,d2=0,s2=10;

void setup() {
  pinMode (l1,OUTPUT);
  pinMode (l2,OUTPUT);
}

void loop() {
  t=millis();
  if(t-t1>w){
    t1=t;
    //l1 value change
    if (d1==0) { if(v1>(s1+1)) {v1-=s1;} else {d1=1;}}
    if (d1==1) {if(v1<=(254-s1)) {v1+=s1;} else {d1=0;}}
    

    //l2 value change
    if (d2==0) {if(v2>(s2+1)) v2-=s2; else d2=1;}
    if (d2==1) {if(v2<=(254-s2)) v2+=s2; else d2=0;}
    
    
  }

  analogWrite(l1,v1);
  analogWrite(l2,v2);
}// loop
