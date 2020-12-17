/*
 * In this project, we want to control the timer port of the Arduino.
 * The brightness of the LED was controlled by varyung the value of the potentiometer.
 * Author: Muhammad Izzat (1717987)
 */

int LED_PIN = 6;  // the PWM pin the LED is attached to
int POTENTIOMETER_PIN = A0; // setting the analog pin of the potentiometer

void setup() {
  
  // declare LED pin to be an output:
  pinMode(LED_PIN, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  
  // reads the input on analog pin A0 (value between 0 and 1023)
  int analogValue = analogRead(POTENTIOMETER_PIN);

  // scales it to brightness (value between 0 and 255)
  int brightness = map(analogValue, 0, 1023, 0, 255);

  // sets the brightness LED that connects to  pin 3
  analogWrite(LED_PIN, brightness);
}
