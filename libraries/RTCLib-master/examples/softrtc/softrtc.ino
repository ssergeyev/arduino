// Date and time functions using just software, based on millis() & timer

#include <Wire.h>
#include "RTClib.h"

RTC_Millis rtc;

void setup() {
  Serial.begin(9600);
  // following line sets the RTC to the date & time this sketch was compiled
  rtc.begin(DateTime(__DATE__, __TIME__));
}

void loop() {
  DateTime now = rtc.now();

  Serial.println(now.toStr());

  Serial.print(" seconds since 1970: ");
  Serial.println(now.unixtime());

  // calculate a date which is 7 days and 30 seconds into the future
  DateTime future(now + TimeDelta(7 * 86400L + 30));

  Serial.println(future.toStr());

  Serial.println();
  delay(3000);
}
