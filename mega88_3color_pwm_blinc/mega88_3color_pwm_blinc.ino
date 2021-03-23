#define blue 5
#define yellow 6
#define green 9

void setup() {
  pinMode(blue,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(green,OUTPUT);  
}

void loop() {

  digitalWrite(yellow,LOW);
  digitalWrite(blue,HIGH);
  delay(500);
  digitalWrite(green,LOW);
  digitalWrite(yellow,HIGH);
  delay(500);
  digitalWrite(blue,LOW);
  digitalWrite(green,HIGH);
  delay(500);

}
