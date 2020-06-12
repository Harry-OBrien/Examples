
void setup() {
pinMode (13, OUTPUT);
}

void loop() {
  randomSeed(getSeed());
  byte delay1 = random(1000, 1000000);
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delayMicroseconds(delay1);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delayMicroseconds(delay1);              // wait for a second


}

int getSeed() {
  int seed = 0;
  int bit = 1;

  while(bit) {
    byte a = analogRead(0);
    delay(1);
    byte b = analogRead(0);
    delay(1);

    if((a & 1) != (b & 1)) {
      if(a&1) seed |= bit;
      bit <<= 1;
    }
  }

  return seed;
}
