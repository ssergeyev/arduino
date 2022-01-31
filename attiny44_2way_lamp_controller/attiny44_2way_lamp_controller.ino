//
# define Left_SW  9
# define Right_SW 10
# define Busser 8
# define L_ID 7
# define R_ID 6
# define State 5
# define L_lamp 2
# define R_lamp 1
# define L_sensor 0

uint8_t state=0,l_id=0,r_id=0,busser=0;
uint32_t t,t1,t2,time1,time2;
char direct=0b00000000;//1-state,2-L-ID, 3-R-ID

void setup() {
  // put your setup code here, to run once:
  pinMode(Busser,OUTPUT);
  digitalWrite(Busser,HIGH);
  pinMode(State,OUTPUT);
  pinMode(Left_SW,INPUT);
  pinMode(Right_SW,INPUT);
  pinMode(L_lamp,OUTPUT);
  pinMode(R_ID,OUTPUT);
  pinMode(L_ID,OUTPUT);
  pinMode(R_lamp,OUTPUT);
  delay(100);
  digitalWrite(Busser,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
t=millis();
  if(t-t2>20){t2=t;
    state=blink(state,1,5,250,5); analogWrite(State,state);
    //analogWrite(State,blink(state,1,5,250,5));
    //l_id= blink(l_id,2,2,30,1);  analogWrite(L_ID,l_id);
    //r_id= blink(r_id,3,128,250,3);  analogWrite(R_ID,r_id);
  }

  if (digitalRead(Left_SW)) {digitalWrite(L_lamp,HIGH);digitalWrite(Busser,HIGH);}
  if (digitalRead(Right_SW)){digitalWrite(R_lamp,HIGH);}

  if(t-t1>500){  
  if(busser>245){digitalWrite(L_lamp,HIGH);busser=0;}
  }

  if(t-t1>1000){
  t1=t;
  digitalWrite(L_lamp,LOW);digitalWrite(Busser,LOW);
  digitalWrite(R_lamp,LOW);    
  }
}//loop

uint8_t blink(uint8_t result,uint8_t dir,uint8_t b_min,uint8_t b_max,uint8_t b_step){
    if(!bitRead(direct,dir)){
      if(result>b_min){result-=b_step;}
      if(result<=b_min){bitSet(direct,dir);}
    }else{
      if(result<b_max){result+=b_step;}
      if(result>=b_max){bitClear(direct,dir);}
    }
    return(result);
}//blink

void lamp(utin8_t set_l){
  
}
