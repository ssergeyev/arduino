#include <LedControl.h>
  LedControl lc=LedControl(A5,A6,A4,1);//cs,clk,load,count

#include <GyverEncoder.h>
#define s1 A0
#define s2 A1
#define key A2
#define power A3
  Encoder enc1(s2, s1, key);  // для работы c кнопкой

#define led1 3
#define led2 5
#define led3 6
#define led4 9
#define led5 10
#define led6 11
#define intled 13

#define s_right 7
#define s_left 8

uint8_t l1,l2,l3,l4,l5,l6,l_all;
uint16_t t_l1, t_l2, t_l3, t_l4, t_l5, t_l6,t_all,t_right,t_left,t_intled;

bool l_r,l_l;

int mode=0;
int value=0;
int ballance;

void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
//  pinMode(led5,OUTPUT);
//  pinMode(led6,OUTPUT);
  pinMode(intled,OUTPUT);
  pinMode(s_left,OUTPUT);
  pinMode(s_right,OUTPUT);

  pinMode(s1,INPUT);
  pinMode(s2,INPUT);
  pinMode(key,INPUT);
  pinMode(power,OUTPUT);

  digitalWrite(power,HIGH);
  
  Serial.begin(9600);

  enc1.setType(TYPE2);

  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);
}

void loop() {
  unsigned int cur=millis();
  enc1.tick();
  if (enc1.isRight()) {Serial.println("Right");if (value <=254){value++;}}         // если был поворот
  if (enc1.isLeft()) {Serial.println("Left"); if (value >=1){value --;}}
  if (enc1.isRightH()) Serial.println("Right holded"); // если было удержание + поворот
  if (enc1.isLeftH()) Serial.println("Left holded");
//  if (enc1.isPress()) Serial.println("Press");         // нажатие на кнопку (+ дебаунс)
  if (enc1.isClick()) {Serial.println("Click");if(mode<4){mode++;}else{mode=0;}Serial.println(mode);}         // отпускание кнопки (+ дебаунс)
  if (enc1.isHolded()) {Serial.println("Holded");mode=0;value=255;}       // если была удержана и энк не поворачивался
  if (enc1.isFastR()){ if (value<=240)value += 10;}    // если был быстрый поворот направо, увеличиваем на 10
  if (enc1.isFastL()){ if (value>=10) value -= 10;}    // если был быстрый поворот налево, уменьшаем на 10

  if (mode==0){
    l_r=LOW;l_l=LOW;
    if (l_all != value){
      l_all=value;
//      l1=l2=l3=l4=l5=l6=value;
        l1=l2=l3=l4=value;
    //  set_light();
    }
  }

  if (mode==1){
    l_r=HIGH;l_l=LOW;
    if (l1!=value){
      l1=l2=l3=value;
     // set_light();
    }
  }

  if (mode==2){
    l_r=LOW;l_l=HIGH;
    if (l4!=value){
      //l4=l5=l6=value;
      l4=value;
     // set_light();
    }
  }

  if (mode==3){
    l_r=HIGH;l_l=HIGH;
//    ballance = (value/51)+1;
    if (ballance==1){
      l1=255,l2=210,l3=170,l4=130,l5=80,l6=30;
    }
   // set_light();
  }

  if (mode==4){
    l_r=LOW;
    if(cur-t_left>500){
      t_left=cur;
      l_l = !l_l;  
    }
   // set_light();
  }

  set_light();

  if(cur-t_intled>300){
    t_intled=cur;
    digitalWrite(intled,!digitalRead(intled));
  }

  //lc.clearDisplay(0);
  lc.setDigit(0,0,(byte)mode,false);
  //lc.setDigit(0,4,(byte)value,false);
  

} // loop

void set_light(){
  digitalWrite(s_right,l_r);
  digitalWrite(s_left,l_l);
  analogWrite(led1,l1);
  analogWrite(led2,l2);
  analogWrite(led3,l3);
  analogWrite(led4,l4);
  analogWrite(led5,l5);
  analogWrite(led6,l6);
} // set_light
