#define green 6
#define yellow 7
#define blue 8
#define white 4

#define minblink 1
#define maxblink 100

uint8_t g=90,y=10,b=60;
boolean gd=true; 
boolean yd=true; 
boolean bd=false;
boolean wg=true;
unsigned long t,t1;
const long interval=10;

void setup() {
  pinMode(green,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(white,OUTPUT);
}

void loop() {
  t=millis();
  if (t-t1>=interval){
    t1=t; 
    if (gd){
      g++; if(g>=maxblink){gd=false;digitalWrite(white,HIGH);}
    } else {
      g--; if(g<=minblink){gd=true;digitalWrite(white,LOW);}
    }// else

    if (yd){
      y++; if(y>=maxblink){yd=false;}
    } else {
      y--; if(y<=minblink){yd=true;}
    }// else

    if (bd){
      b++; if(b>=maxblink){bd=false;}
    } else {
      b--; if(b<=minblink){bd=true;}
    }// else    
  analogWrite(green,g);
  analogWrite(yellow,y);
  analogWrite(blue,b);  
  }//if interval

}//loop
