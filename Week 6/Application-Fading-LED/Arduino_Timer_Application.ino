/* In this project, we want to control the timer port of Arduino.
   This program is to apply the timer port Arduino. We will use PWM to do fading LED.
   Owner: Muhammad Izzat 1717987
*/

//Initializing LED Pin
int led_pin = 6;
void setup() {
  //Declaring LED pin as output
  pinMode(led_pin, OUTPUT);
}
void loop() {
  //Fading the LED
  for (int i = 0; i < 255; i++) {
    analogWrite(led_pin, i);
    delay(5);
  }
  for (int i = 255; i > 0; i--) {
    analogWrite(led_pin, i);
    delay(5);
  }
}
