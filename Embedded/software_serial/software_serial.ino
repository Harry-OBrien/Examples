#include <SoftwareSerial.h>

SoftwareSerial ble(4,5);

void setup() {
  Serial.begin(9600);
  ble.begin(9600);
}

void loop() {
  if (Serial.available()) {
    ble.write(Serial.read());
  }
  if (ble.available()) {
    Serial.write(ble.read());
  }
}
