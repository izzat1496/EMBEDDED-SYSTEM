# Arduino External Interrupt
In this project, we want to write an interrupt-based program for the Arduino.

On Arduino, timer0 is configured as 8-bit fast PWM with pre-scaler= 64.

If the frequency of the system is 16MHz, the timer0 overflows 976.56 times per second.

Blink an LED (1 sec ON and 1 sec OFF) on PD5 without any library (using timer2 overflow interrupt)

The period of timer flow interrupt is 1.024 ms.

The green LED is connected to digital pin 13 of Arduino.

List of component:

Arduino UNO x1

Breadboard x1

Green LED x1

Jumper wire x2

Resistor 1kΩ x1

Refer to this link for coding explaination with demonstration: (Currently editing the video. Please look for temporary video in the Project File folder)
