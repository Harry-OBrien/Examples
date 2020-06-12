#define  Eb5 622.25
//
//
//
//
#define Ab5 830.61
//
#define Bb5 932.33
//
//
//
//
#define Eb6 1244.51


void setup() {
  //start serial communication
  Serial.begin(9600);
}

void loop() {

  tone(13, Eb6);
  delay(500);

  tone(13, Eb5);
  delay(80);

  tone(13, Bb5);
  delay(80);

  tone(13, Eb5);
  delay(80);

  tone(13, Bb5);
  delay(120);

  tone(13, Ab5);
  delay(500);

  tone(13, Eb6);
  delay(220);
  noTone(13);
  delay(60);

  tone(13, Bb5);
  delay(600);

  noTone(13);
  delay(3000);


}

