#include <CoreX.h>
#include <DHT.h>
#include "Connection.h"
// #include <Wire.h>
// #include <LiquidCrystal_I2C.h>

// LiquidCrystal_I2C lcd(0x27, 16, 2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

#define DHTPIN D5      // GPIO 12 untuk pin DHT.
#define DHTTYPE DHT11  // DHT 11
//#define DHTTYPE DHT22                 // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21                 // DHT 21 (AM2301)
m

DHT dht(DHTPIN, DHTTYPE);
CoreXTimer timer;  // Gunakan timer agar dapat mengeksekusi perintah setiap sekian milidetik tanpa blocking.

// Ubah nilai berikut sesuai jaringan Anda.
const char ssid[] = "KLINIK LED";
const char pass[] = "kl1n1kled";

void send() {
  float humid = dht.readHumidity();
  float temp = dht.readTemperature();
 
  // lcd.setCursor(0, 0);
  // lcd.print("SUHU :");
  // lcd.print(temp);
  // lcd.print(" C");
  // lcd.setCursor(0, 1);
  // lcd.print("HUMI :");
  // lcd.print(temp);
  // lcd.print(" %");

  corex.send("kelembaban", humid);  // send data kelembaban ke bucket "kelembaban".
  corex.send("temperatur", temp);   // send data temperatur ke bucket "temperatur".
}

void setup() {
  Serial.begin(115200);
  // lcd.init();  // initialize the lcd
  // lcd.init();
  // // Print a message to the LCD.
  // lcd.backlight();
  
  WiFi.begin(ssid, pass);
  corex.begin(net);
  dht.begin();


  timer.setInterval(3000, send);  // Lakukan send setiap 3000 milidetik.

  setupCorex();
}

void loop() {
  timer.run();  // Jalankan timer.
  //delay(10);                          // Hapus komentar untuk memberikan delay 10 milidetik jika terjadi kendala pada stabilitas WiFi.

  // Periksa apakah perangkat masih terhubung.
  if (!corex.connected()) {
    setupCorex();
  }

  //==LETAKAN KODE PROGRAM DISINI UNTUK DILAKUKAN PROSES==//
}