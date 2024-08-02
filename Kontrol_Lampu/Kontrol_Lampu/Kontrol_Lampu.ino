#include <CoreX.h>
#include "Connection.h"

// Ubah nilai auth_token dan device Anda
const char* AUTH_TOKEN = "4rJnX3YANVUTFy9";
const char* DEVICE_ID = "loEtZcCHD";

// Ubah nilai berikut sesuai jaringan Anda
const char ssid[] = "KLINIK LED";
const char pass[] = "kl1n1kled";

void receive(String& bucket, String& data) {
  if (bucket == "led") {
    digitalWrite(33, !data.toInt());

    if (data == "0") {
      Serial.println("LED ON");
    } else {
      Serial.println("LED OFF");
    }
  }
}

void setup() {
  pinMode(33, OUTPUT);
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