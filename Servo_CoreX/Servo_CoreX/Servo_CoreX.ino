#include <CoreX.h>
#include "Connection.h"
#include <Servo.h>

// Ubah nilai auth_token dan device Anda
const char* AUTH_TOKEN = "wS6oCTUuO7A1p48";
const char* DEVICE_ID = "HJGeJy9nF";

// Ubah nilai berikut sesuai jaringan Anda.
const char ssid[] = "KLINIK LED";
const char pass[] = "kl1n1kled";

Servo myservo;

void receive(String& bucket, String& data) {
  if (bucket == "data") {
    myservo.write(data.toInt());
  }
}

void setup() {
  myservo.attach(12);  //  Inisialisasi servo pada GPIO12 (D6)
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
  corex.begin(net);

  corex.onMessage(receive);  // Lakukan receive pada fungsi receive().

  setupCoreX();
}

void loop() {
  corex.loop();
  //delay(10);                          // Hapus komentar untuk memberikan delay 10 milidetik jika terjadi kendala pada stabilitas WiFi.

  // Periksa apakah perangkat masih terhubung.
  if (!corex.connected()) {
    setupCoreX();
  }

  //==LETAKAN KODE PROGRAM DISINI UNTUK DILAKUKAN PROSES==//
}
