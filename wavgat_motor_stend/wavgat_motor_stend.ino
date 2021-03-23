
int sensorPin = A7;    // select the input pin for the potentiometer
int sensorOn = 2;
int ledPin = 13;      // select the pin for the LED
int button = A6;
int m_r = 9;
int m_l =10;
int sensorValue = 0;  // variable to store the value coming from the sensor<

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  pinMode(sensorOn, OUTPUT);
  pinMode(sensorPin, INPUT);
  pinMode(button, INPUT_PULLUP);
  digitalWrite(sensorOn, HIGH);
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensorPin);
/*
  if (button){
    
  } 
*/
  
  Serial.println (sensorValue);
  Serial.println (digitalRead(button));
  delay(10);
}
