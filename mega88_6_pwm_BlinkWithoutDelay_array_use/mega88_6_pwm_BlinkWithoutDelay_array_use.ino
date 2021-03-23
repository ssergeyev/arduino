uint8_t i=0, i1=3;
int dlCount=3;                             //Количество задействованных цифровых выходов
int dl[3]={7,12,13};                      //Список задействованных цифровых выводов
byte dlState=0b00000000;                  //Состояние задействованных цифровых выводов
int alCount=6;                             //Количество задействованных аналоговых выводов (для atmega8 поставить 3)
int al[6]={9,10,11,6,5,3};                //Список задействованных аналоговых выводов (atmega8 только первые 3 вывода)
uint8_t alState[6]={1,1,1,1,1,1};         //Значение ШИМ задействованных аналоговых выводов
byte alDirect=0xFF;                 //Направление изменения ШИМ

unsigned long dlPrevTime[3]={0,0,0};             //Счётчик для цифровых выводов
unsigned long dlInterval1[3]={500,500,100};     //Интервал на включение 
unsigned long dlInterval2[3]={510,1000,1000};     //Интервал на отключение 
unsigned long alPrevTime[6]={0,0,0,0,0,0};       //Счётчик для аналоговых выводов
unsigned long alInterval[6]={1,2,3,4,5,1}; //Интервалы изменения ШИМ для аналоговых выводов

void setup() {
  for(int i=0; i<dlCount;i++) pinMode(dl[i],OUTPUT);  //Инициализация цифровых выводов
  for(int i=0; i<alCount;i++) pinMode(al[i],OUTPUT);  //Инициализация аналоговых выводов
}

void loop() {
  unsigned long currentMillis = millis();

    while (i < dlCount){
    //for(i=0;i<dlCount;i++){
    if(currentMillis - dlPrevTime[i] > dlInterval1[i]) bitSet(dlState,i); // Включение вывода из списка в свой интервал
    if(currentMillis - dlPrevTime[i] > dlInterval2[i]) {bitClear(dlState,i); dlPrevTime[i]=currentMillis;} // Выключение вывода в свой интервал
    digitalWrite(dl[i],bitRead(dlState,i));
    i++;}
    if (i == dlCount) i=0;


//    while (i1 < alCount) {
/*
    if(currentMillis - alPrevTime[i1] > alInterval[i1]){
     dlPrevTime[i1]=currentMillis;
     if(bitRead(alDirect,i1)&&alState[i1]<254){alState[i1]++;}else{bitClear(alDirect,i1);}
     if(!bitRead(alDirect,i1)&&alState[i1]>2){alState[i1]--;}else{bitSet(alDirect,i1);}
     analogWrite(al[i1],alState[i1]);
    }

//     i1++;}
//    if (i1 == alCount) i1=0; 


/*
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    if(d1&&l1<=120){l1++;}else{d1=false;}
    if(!d1&&l1>=2){l1--;}else{d1=true;}

    if(d2&&l2<=154){l2++;}else{d2=false;}
    if(!d2&&l2>=2){l2--;}else{d2=true;}

    if(d3&&l3<=240){l3++;}else{d3=false;}
    if(!d3&&l3>=2){l3--;}else{d3=true;}

    if(d4&&l4<=254){l4++;}else{d4=false;}
    if(!d4&&l4>=2){l4--;}else{d4=true;}

    if(d5&&l5<=200){l5++;}else{d5=false;}
    if(!d5&&l5>=2){l5--;}else{d5=true;}

    if(d6&&l6<=100){l6++;}else{d6=false;}
    if(!d6&&l6>=2){l6--;}else{d6=true;}

    analogWrite(3,l3);
    analogWrite(5,l2);
    analogWrite(6,l3);
    analogWrite(9,l4);
    analogWrite(10,l5);
    analogWrite(11,l6);

  }

  if (currentMillis - t1 > 500){
    t1=currentMillis;
    if (ledState) {ledState = LOW;} else {ledState = HIGH;}
    digitalWrite(ledPin, ledState);
    digitalWrite(7,ledState);
    digitalWrite(12,ledState);
  }
*/
}
