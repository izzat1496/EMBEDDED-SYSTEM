/* In this project, we want to control the timer port of Arduino.
   This program will produce a PWM signal with 25% duty cycle on Channel A of timer1. Use 10-bit Phase Correct PWM-mode and pre-scalervalue of 8. The output signal generated can be seen at the oscilloscope.
   Owner: Muhammad Izzat 1717987
*/

#include <avr/io.h>


int main(void)
{
    unsigned char*ddrb = (unsigned char*)0x24;
    unsigned char*ocr1al = (unsigned char*)0x88;
    unsigned char*tccr1a = (unsigned char*)0x80;
    unsigned char*tccr1b = (unsigned char*)0x81;
    *ddrb = 2;
    *ocr1al = 255;
    *tccr1a = 0b10000011;
    *tccr1b = 0b00000010;
}

