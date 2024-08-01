#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int relayPin = 23;            // Pin relay yang digunakan
const String correctCode = "1234";  // Kode yang benar untuk membuka kunci
String inputCode = "";              // Menyimpan kode yang dimasukkan

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Alamat I2C untuk LCD (0x27 atau 0x3F)

const byte ROWS = 4;  // 4 baris pada keypad
const byte COLS = 3;  // 3 kolom pada keypad
char keys[ROWS][COLS] = {
  { '1', '2', '3' },
  { '4', '5', '6' },
  { '7', '8', '9' },
  { '*', '0', '#' }
};

byte rowPins[ROWS] = { 14, 27, 26, 25 };  // Pin baris pada keypad (GPIO14, GPIO27, GPIO26, GPIO25)
byte colPins[COLS] = { 33, 32, 13 };      // Pin kolom pada keypad (GPIO33, GPIO32, GPIO13)

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);  // Mematikan relay (kunci terkunci)

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Enter Code:");

  Serial.begin(115200);
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    Serial.println(key);
    if (key == '*') {
      inputCode = "";  // Reset input jika tombol * ditekan
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Enter Code:");
    } else if (key == '#') {
      if (inputCode == correctCode) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Access Granted");
        digitalWrite(relayPin, LOW);   // Mengaktifkan relay (kunci terbuka)
        delay(5000);                   // Tetap terbuka selama 5 detik
        digitalWrite(relayPin, HIGH);  // Mematikan relay (kunci terkunci)
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Enter Code:");
        inputCode = "";  // Reset input setelah membuka kunci
      } else {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Access Denied");
        delay(2000);  // Menampilkan pesan selama 2 detik
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Enter Code:");
        inputCode = "";  // Reset input setelah kesalahan
      }
    } else {
      inputCode += key;  // Menambahkan karakter ke inputCode
      lcd.setCursor(0, 1);
      lcd.print(inputCode);
    }
  }
}
