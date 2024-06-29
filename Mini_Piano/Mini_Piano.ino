
#include "pitch.h"

#define buzzPin D6
#define btn1 D1
#define btn2 D2
#define btn3 D3
#define btn4 D4


void setup() { 
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  pinMode(btn4, INPUT);
}

void loop() {

  if (digitalRead(btn1) == 0 or digitalRead(btn2) == 0 or digitalRead(btn3) == 0 or digitalRead(btn4) == 0) {
    
    if (digitalRead(btn1) == 0) {
      tone(buzzPin, NOTE_C5);
    }
    if (digitalRead(btn2) == 0) {
      tone(buzzPin, NOTE_D5);
    }
    if (digitalRead(btn3) == 0) {
      tone(buzzPin, NOTE_E5);
    }
    if (digitalRead(btn4) == 0) {
      tone(buzzPin, NOTE_F5);
    }
  } else {
    noTone(buzzPin);
  }
}