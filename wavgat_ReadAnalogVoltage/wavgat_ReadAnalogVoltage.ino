//wavgat uno r3

uint8_t main_loop=0;
uint8_t i;

void setup() {
  //Serial.begin(9600);
  for(i=0; i<=21; i++){
    pinMode(i,OUTPUT);
  }
  digitalWrite(13,HIGH);
}

void loop() {
  //int sensorValue = analogRead(A5);
  //float voltage = sensorValue * (3.3 / 4064);
  //Serial.println(voltage);

  if(main_loop <= 255) main_loop++; else main_loop=0;


  for(i=0; i<=21; i++){
    if(main_loop>128)digitalWrite(i,HIGH); else digitalWrite(i,LOW);
  }

/*
  analogWrite(3,main_loop);
  analogWrite(5,main_loop);
  analogWrite(6,main_loop);
  analogWrite(9,main_loop);
  analogWrite(10,main_loop);
  analogWrite(11,main_loop);
*/  
  delay(10);

}
