#define lamp 3
#define sensor 0

void setup() {

  pinMode (lamp,OUTPUT);
  pinMode (sensor,INPUT);
  
}

void loop() {

  if (digitalRead(sensor)){
    digitalWrite(lamp,HIGH);
    delay(180000);
 }
  
  digitalWrite(lamp,LOW);
  
}
