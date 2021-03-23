#define photo 2
uint16_t lux;
volatile uint16_t count;
unsigned long previousMillis = 0;
const long interval = 1000;

void setup() {
  pinMode(photo,INPUT);
  Serial.begin(9600);
  attachInterrupt(0,flash,RISING);
}

void loop() {
//  lux=digitalRead(photo);
//  Serial.println(lux);

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    Serial.println(count);
    count = 0;
  } // run one per second
  
}

void flash(){
  count ++;
}
