
int sensorPin = A7;    // select the input pin for the potentiometer
int sensorOn = 3;
int ledPin = 13;      // select the pin for the LED
int button = A6;
//int irOn = 3;
int irPin = 2; //int-0
int m_r = 9;
int m_l =10;
int sensorValue = 0;  // variable to store the value coming from the sensor<
int irData = 0;
unsigned long t = 0,t1 = 0;
unsigned long rotate = 0;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  pinMode(sensorOn, OUTPUT);
  pinMode(sensorPin, INPUT);
  pinMode(button, INPUT_PULLUP);
  //pinMode(irOn, OUTPUT);
  pinMode(irPin, INPUT);
  digitalWrite(sensorOn, HIGH);
  //digitalWrite(irOn, HIGH);
  Serial.begin(9600);
  rotate = 0;
  attachInterrupt(0,rpm,RISING);
}

void rpm(){
  rotate++;
}


void loop() {
  t = millis();
  sensorValue = analogRead(sensorPin);
  //irData = digitalRead(irPin);
  //if(irData) {rotate+=1;}
  
  if(t-t1>=1000){
    t1=t;
    Serial.println((rotate/4)*60);
    rotate=0;
  }
  
  
/*
  if (button){
    
  } 
*/
  
  //Serial.println (sensorValue);
  //Serial.println (digitalRead(button));
  //Serial.println (irData);
  //delay(10);
}
