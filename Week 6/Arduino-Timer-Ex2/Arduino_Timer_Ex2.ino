/* In this project, we want to control the timer port of Arduino.
 * This program will produce a PWM signal with 50% duty cycle on Channel B of timer0. Use Fast PWM mode and pre-scaler value of 1. The output signal generated can be seen at the oscilloscope.
 * Owner: Muhammad Izzat 1717987
 */
 
void setup() {
  
  unsigned char*ddrd = (unsigned char*)0x2A;
  unsigned char*ocr0b = (unsigned char*)0x48;
  unsigned char*tccr0a = (unsigned char*)0x44;
  unsigned char*tccr0b = (unsigned char*)0x45;
  *ddrd = 1 << 5;
  *ocr0b = 127;
  *tccr0a = 0b00100011;
  *tccr0b = 0b00000001;
}

void loop() {
}
