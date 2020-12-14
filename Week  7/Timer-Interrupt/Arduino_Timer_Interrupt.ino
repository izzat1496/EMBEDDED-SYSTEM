/* In this project, we want to write an interrupt-based program for the Arduino.
   On Arduino, timer0 is configured as 8-bit fast PWM with pre-scaler= 64.
   If the frequency of the system is 16MHz, the timer0 overflows 976.56 times per second.
   Blink an LED (1 sec ON and 1 sec OFF) on PD5 without any library (using timer2 overflow interrupt)
   The period of timer flow interrupt is 1.024 ms.
   Owner: Muhammad Izzat 1717987
*/

volatile unsigned long ms;
unsigned char* tccr2a = (unsigned char*) 0xB0;
unsigned char* tccr2b = (unsigned char*) 0xB1;
unsigned char* timsk2 = (unsigned char*) 0x70;
unsigned char* portb = (unsigned char*) 0x25;
unsigned char* ddrb = (unsigned char*) 0x24;
unsigned char* sreg = (unsigned char*) 0x5F;
unsigned long previousTime;

ISR(TIMER2_OVF_vect)
{
  ms++;
}

unsigned long getMilliseconds()
{
  *timsk2 = 0; //Disable timer2 interrupts
  unsigned long val = ms; //Read the variable
  *timsk2 = 1; //Re-enable timer2 interrupts
  return val;
}

void setup()
{
  *ddrb = 32; //Set PD5 as output
  *tccr2a = 3; //8-bit Fast PWM on timer2
  *tccr2b = 4; //Set pre-scaler to 64
  *sreg |= 1 << 7; //Enable interrupts
  *timsk2 = 1; //Enable timer2 overflow interrupt
  while (1)
  {
    unsigned long currentTime = getMilliseconds();
    if ((*portb) & 32) //If LED is currently ON
    {
      if (currentTime - previousTime >= 1000)
      {
        *portb = 0; //Turn it OFF
        previousTime = currentTime;
      }
    }
    else //If LED is currently OFF
    {
      if (currentTime - previousTime >= 1000)
      {
        *portb = 32; //Turn it ON
        previousTime = currentTime;
      }
    }
  }
}
