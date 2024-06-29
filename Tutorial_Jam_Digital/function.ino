

void custom0(int x) {

  lcd.setCursor(x, 0);
  lcd.write(0);
  lcd.write(1);
  lcd.write(2);
  lcd.setCursor(x, 1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
}

void custom1(int x) {
  lcd.setCursor(x, 0);
  lcd.write(1);
  lcd.write(2);
  lcd.print(" ");
  lcd.setCursor(x, 1);
  lcd.write(4);
  lcd.write(7);
  lcd.write(4);
}

void custom2(int x) {
  lcd.setCursor(x, 0);
  lcd.write(6);
  lcd.write(6);
  lcd.write(2);
  lcd.setCursor(x, 1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(4);
}

void custom3(int x) {
  lcd.setCursor(x, 0);
  lcd.write(6);
  lcd.write(6);
  lcd.write(2);
  lcd.setCursor(x, 1);
  lcd.write(4);
  lcd.write(4);
  lcd.write(5);
}

void custom4(int x) {
  lcd.setCursor(x, 0);
  lcd.write(3);
  lcd.write(4);
  lcd.write(7);
  lcd.setCursor(x, 1);
  lcd.print(" ");
  lcd.print(" ");
  lcd.write(7);
}

void custom5(int x) {
  lcd.setCursor(x, 0);
  lcd.write(3);
  lcd.write(6);
  lcd.write(6);
  lcd.setCursor(x, 1);
  lcd.write(4);
  lcd.write(4);
  lcd.write(5);
}

void custom6(int x) {
  lcd.setCursor(x, 0);
  lcd.write(0);
  lcd.write(6);
  lcd.write(6);
  lcd.setCursor(x, 1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
}

void custom7(int x) {
  lcd.setCursor(x, 0);
  lcd.write(1);
  lcd.write(1);
  lcd.write(2);
  lcd.setCursor(x, 1);
  lcd.print(" ");
  lcd.print(" ");
  lcd.write(7);
}

void custom8(int x) {
  lcd.setCursor(x, 0);
  lcd.write(0);
  lcd.write(6);
  lcd.write(2);
  lcd.setCursor(x, 1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
}

void custom9(int x) {
  lcd.setCursor(x, 0);
  lcd.write(0);
  lcd.write(6);
  lcd.write(2);
  lcd.setCursor(x, 1);
  lcd.print(" ");
  lcd.print(" ");
  lcd.write(7);
}
void custom10(int x) {
  lcd.setCursor(x, 0);
  lcd.write(4); 
}


void digitalClockDisplay() {
  DateTime now = rtc.now();
 
  printDigits((now.hour()) / 10, 0);
  printDigits((now.hour()) % 10, 4); 

  if (millis() - prev > 499) {
    printDigits((now.minute()) / 10, 9);
    printDigits((now.minute()) % 10, 13);
  }
  if (millis() - prev > 999) {
    lcd.clear();
    prev = millis();
  } 
}



void printDigits(int digits, int x) {
  switch (digits) {
    case 0:
      custom0(x);
      break;
    case 1:
      custom1(x);
      break;
    case 2:
      custom2(x);
      break;
    case 3:
      custom3(x);
      break;
    case 4:
      custom4(x);
      break;
    case 5:
      custom5(x);
      break;
    case 6:
      custom6(x);
      break;
    case 7:
      custom7(x);
      break;
    case 8:
      custom8(x);
      break;
    case 9:
      custom9(x);
      break;
    case 10:
      custom10(x);
      break;
  }
}
