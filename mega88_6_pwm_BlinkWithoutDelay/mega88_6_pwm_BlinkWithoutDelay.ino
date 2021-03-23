const int ledPin =  LED_BUILTIN;// the number of the LED pin
int ledState = LOW;             // ledState used to set the LED
uint8_t l1=1,l2=50,l3=100,l4=150,l5=20,l6=250;
bool d1=true; 
bool d2=true;
bool d3=true;
bool d4=true;
bool d5=true;
bool d6=true;
unsigned long previousMillis = 0, t1=0;        // will store last time LED was updated
const long interval = 10;           // interval at which to blink (milliseconds)

void setup() {
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

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

}
