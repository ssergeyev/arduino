
int sensorPin = A7;		// input pin for the potentiometer
int sensorOn = 3;		// power +5V for potentiometr and ir LED and ir sensor witch amplifier 
int ledPin = 13;		// select the pin for the LED
int button = A6;		// input pin for jumper switch
int irPin = 2;			// int-0 interrupt from sensor amplifier
int m_r = 9;			// PWM motor right rotate
int m_l =10;			// PWM motor left rotate
int sensorValue = 0;	// variable to store the value coming from the sensor<
unsigned long t = 0,t1 = 0, t2 = 0;
unsigned long rotate = 0;	// sensor have 4 window in sensor disk, one rotate = 4 signals

void setup() {
  // Пины D9 и D10 - 31.4 кГц
  //TCCR1A = 0b00000001;  // 8bit
  //TCCR1B = 0b00000001;  // x1 phase correct
  pinMode(ledPin, OUTPUT);
  pinMode(sensorOn, OUTPUT);
  pinMode(sensorPin, INPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(irPin, INPUT);
  pinMode(m_l, OUTPUT);
  pinMode(m_r, OUTPUT);
  digitalWrite(sensorOn, HIGH);
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
  
  if(t-t1>=1000){		//every each second
    t1=t;
    Serial.println((rotate/4)*60);	// calculate rotates per minuts (RPM) and print
    rotate=0; 						// drop window counter
  }
  
  if(t-t2>=100){
    t2=t;
    sensorValue=analogRead(sensorPin);
    //sensorValue=map(sensorValue,0,4080,255,0);    //for LGT8F32P
    if (sensorValue<500){
      sensorValue=map(sensorValue,0,512,255,0);    //for Atmega328p
      analogWrite(10,sensorValue);
    }
    if (sensorValue>524){
      sensorValue=map(sensorValue,512,1023,0,255);    //for Atmega328p
      analogWrite(9,sensorValue);
    }
    //Serial.println(sensorValue);
    
  }
  
} // main
