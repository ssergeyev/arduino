#include <OneWire.h>

    #include "DHT.h"
    #define plus 4
    #define DHTPIN 5 // Тот самый номер пина, о котором упоминалось выше
    #define minus 7

// пример использования библиотеки OneWire DS18S20, DS18B20, DS1822
OneWire ds(2); // на пине 10 (нужен резистор 4.7 КОм)
DHT dht(DHTPIN, DHT11);

void setup(void) {
  dht.begin();
Serial.begin(9600);
      pinMode(3,OUTPUT);
      pinMode(plus,OUTPUT);
      pinMode(minus,OUTPUT);
      digitalWrite(3,HIGH);
      digitalWrite(plus,HIGH);
      digitalWrite(minus,LOW);
}

void loop(void) {
byte i;
byte present = 0;
byte type_s;
byte data[12];
byte addr[8];
float celsius, fahrenheit;
if ( !ds.search(addr)) {
Serial.println("No more addresses.");
Serial.println();
ds.reset_search();
delay(250);
return;
}

      delay(5000); // 2 секунды задержки
      float h = dht.readHumidity(); //Измеряем влажность
      float t = dht.readTemperature(); //Измеряем температуру
      if (isnan(h) || isnan(t)) {  // Проверка. Если не удается считать показания, выводится «Ошибка считывания», и программа завершает работу
        Serial.println("Ошибка считывания");
        return;
      }
      Serial.print("Влажность: ");
      Serial.print(h);
      Serial.print(" %\t");
      Serial.print("Температура: ");
      Serial.print(t);
      Serial.println(" *C "); //Вывод показателей на экран
      

Serial.print("ROM =");
for( i = 0; i < 8; i++) {
Serial.write(' ');
Serial.print(addr[i], HEX);
}

if (OneWire::crc8(addr, 7) != addr[7]) {
Serial.println("CRC is not valid!");
return;
}

Serial.println();
// первый байт определяет чип
switch (addr[0]) {
case 0x10:
Serial.println(" Chip = DS18S20"); // или более старый DS1820
type_s = 1;
break;
case 0x28:
Serial.println(" Chip = DS18B20");
type_s = 0;
break;
case 0x22:
Serial.println(" Chip = DS1822");
type_s = 0;
break;
default:
Serial.println("Device is not a DS18x20 family device.");
return;
}
ds.reset();
ds.select(addr);
ds.write(0x44); // начинаем преобразование, используя ds.write(0x44,1) с "паразитным" питанием
delay(1000); // 750 может быть достаточно, а может быть и не хватит
// мы могли бы использовать тут ds.depower(), но reset позаботится об этом
present = ds.reset();
ds.select(addr);
ds.write(0xBE);
Serial.print(" Data = ");
Serial.print(present, HEX);
Serial.print(" ");
for ( i = 0; i < 9; i++) { // нам необходимо 9 байт
data[i] = ds.read();
Serial.print(data[i], HEX);
Serial.print(" ");
}

Serial.print(" CRC=");
Serial.print(OneWire::crc8(data, 8), HEX);
Serial.println();
// конвертируем данный в фактическую температуру
// так как результат является 16 битным целым, его надо хранить в
// переменной с типом данных "int16_t", которая всегда равна 16 битам,
// даже если мы проводим компиляцию на 32-х битном процессоре
int16_t raw = (data[1] << 8) | data[0];
if (type_s) {
raw = raw << 3; // разрешение 9 бит по умолчанию
if (data[7] == 0x10) {
raw = (raw & 0xFFF0) + 12 - data[6];
}
} else {
byte cfg = (data[4] & 0x60);
// при маленьких значениях, малые биты не определены, давайте их обнулим
if (cfg == 0x00) raw = raw & ~7; // разрешение 9 бит, 93.75 мс
else if (cfg == 0x20) raw = raw & ~3; // разрешение 10 бит, 187.5 мс
else if (cfg == 0x40) raw = raw & ~1; // разрешение 11 бит, 375 мс
//// разрешение по умолчанию равно 12 бит, время преобразования - 750 мс
}
celsius = (float)raw / 16.0;
fahrenheit = celsius * 1.8 + 32.0;
Serial.print(" Temperature = ");
Serial.print(celsius);
Serial.print(" Celsius, ");
Serial.print(fahrenheit);
Serial.println(" Fahrenheit");
}
