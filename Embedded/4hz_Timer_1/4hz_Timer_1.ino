void setup() {

  Serial.begin(115200);

  //clear interrupts
  cli();

  //set timer1 interrupt at 4Hz
  //clear TTCR1A and TCCR1B registers
  TCCR1A = 0;
  TCCR1B = 0;

  //initialize counter value to 0
  TCNT1  = 0;

  // set compare match register for 4hz increments
  OCR1A = (F_CPU / (4 * 256)) - 1;

  // turn on CTC mode
  TCCR1B |= (1 << WGM12);

  // Set CS12 bit for 256 prescaler
  TCCR1B |= (1 << CS12);

  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);

  //re-enable timer interrupts
  sei();
}

void loop() {

}

static int n = 0;
//called 4 times every second
ISR(TIMER1_COMPA_vect) {
  Serial.println(++n);
  if(n >= 4){ n = 0; Serial.print("\n");}
}
