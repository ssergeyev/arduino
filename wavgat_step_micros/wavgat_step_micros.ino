unsigned long micro1;
unsigned long previousMicros = 0;
unsigned long count;
const long interval = 1000000;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  
  unsigned long currentMicros = micros();

  if (currentMicros - previousMicros >= interval) {
    previousMicros = currentMicros;
    Serial.println(count);
    count = 0;
  } // run one per second
  if(digitalRead(2)){
  count ++;
  }
}
