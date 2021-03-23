#include <GyverEncoder.h>

#define right 5
#define left 6
#define s_right 7
#define s_left 8
#define s1 9
#define s2 10
#define key 11

// r_t_q = rigth time current , s_l_t_c = state left time current
unsigned long r_t_c, l_t_c, s_r_t, s_l_t, s_r_t_c, s_l_t_c, menu_t;

unsigned long r_w = 5; // wait for right pwm
unsigned long l_w = 20; // wait for left pwm
unsigned long s_r_w = 100;  //wait for state right led
unsigned long s_l_w = 500;  //wait for state left led
unsigned long menu_w = 1;

uint8_t r_s = 0; // right pwm state [0-255]
uint8_t l_s = 0; // left pwm state [0-255]

uint8_t r_d = 0; //right direction 0 to up, 1 to down
uint8_t l_d = 0; //left direction 0 to up, 1 to down

uint8_t r_ls=LOW; //right led state
uint8_t l_ls=HIGH; //left led state

uint8_t menu = 0; //0=full; 1=left; 2=right
Encoder enc1(s2, s1, key);  // для работы c кнопкой

void setup() {
  pinMode(left,OUTPUT);
  pinMode(right,OUTPUT);
  pinMode(s_left,OUTPUT);
  pinMode(s_right,OUTPUT);
  pinMode(s1,INPUT);
  pinMode(s2,INPUT);
  pinMode(key,INPUT);
  
  Serial.begin(9600);

  enc1.setType(TYPE2);
}

void loop() {
  enc1.tick();
  unsigned long cur = millis();
/*
  //right pwm
  if (cur - r_w > r_t_c){
    r_t_c = cur;
    if (r_d == 0 && r_s < 254){ r_s ++;} else { r_d = 1;}
    if (r_d == 1 && r_s > 1) { r_s --;} else { r_d = 0;}
  }//right pwm
*/
  //left pwm
  if (cur - l_w > l_t_c){
    l_t_c = cur;
    if (l_d == 0 && l_s < 254){ l_s ++;} else { l_d = 1; l_s --;}
    if (l_d == 1 && l_s > 1) { l_s --;} else { l_d = 0; l_s ++;}
  }//left pwm

  //right state led
  if (cur - s_r_w > s_r_t_c) {
    s_r_t_c = cur;
    r_ls = !r_ls;
  }//right state led

    //left state led
  if (cur - s_l_w > s_l_t_c) {
    s_l_t_c = cur;
    l_ls = !l_ls;
  }//left state led

  // set LED
  analogWrite(right,r_s);
  
  if (enc1.isTurn()) {     // если был совершён поворот (индикатор поворота в любую сторону)
    Serial.println(r_s);
  }

 // analogWrite(left,l_s);
  
//  digitalWrite(s_right, r_ls);
//  digitalWrite(s_left, l_ls);

  if (enc1.isRight()) {Serial.println("Right");
    if (r_s <=254){r_s++;}
  }         // если был поворот
  
  if (enc1.isLeft()) {Serial.println("Left");
    if (r_s >=1){r_s --;}
  }
  
  if (enc1.isRightH()) Serial.println("Right holded"); // если было удержание + поворот
  if (enc1.isLeftH()) Serial.println("Left holded");
  
  if (enc1.isPress()) Serial.println("Press");         // нажатие на кнопку (+ дебаунс)
  if (enc1.isClick()) Serial.println("Click");         // отпускание кнопки (+ дебаунс)
  //if (enc1.isRelease()) Serial.println("Release");     // то же самое, что isClick
  
  if (enc1.isHolded()) Serial.println("Holded");       // если была удержана и энк не поворачивался
  //if (enc1.isHold()) Serial.println("Hold");         // возвращает состояние кнопки

  if (enc1.isFastR()){ 
    if (r_s<=240)r_s += 10;    // если был быстрый поворот направо, увеличиваем на 10
    //Serial.println(r_s);
  }
  if (enc1.isFastL()) {
    if (r_s>=10) r_s -= 10;    // если был быстрый поворот налево, уменьшаем на 10
     //Serial.println(r_s);
  }


  /*
  Serial.print(digitalRead(s1));
  Serial.print("; ");
  Serial.print(digitalRead(s2));
  Serial.print("; ");
  Serial.print(digitalRead(key));
  Serial.print("; ");
  Serial.println (menu);
  */
}
