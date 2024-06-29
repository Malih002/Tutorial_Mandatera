
#include <Wire.h>
#include "LiquidCrystal_I2C.h"
#include "RTClib.h"
#include "customChar.h"

RTC_DS3231 rtc;
 
LiquidCrystal_I2C lcd(0x27, 16, 2);

unsigned long prev = 0;
 
void setup() {
  Serial.begin(9600);
  rtc.begin();
  lcd.init();
  
  lcd.backlight();
  lcd.home();

  rtc.adjust(DateTime(2024, 6, 29, 15, 9, 0));
  lcd.createChar(0, LT);
  lcd.createChar(1, UB);
  lcd.createChar(2, RT);
  lcd.createChar(3, LL);
  lcd.createChar(4, LB);
  lcd.createChar(5, LR);
  lcd.createChar(6, MB);
  lcd.createChar(7, block);

  lcd.clear();
}


void loop() {
  digitalClockDisplay();
}

