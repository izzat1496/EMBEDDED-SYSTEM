/* In this project, we will create a program that continuously prints out the analog value of PC3 (A3 Analog pin) through the serial port. 
 * Assuming that clock speed of Arduino at 16MHz, desired clock speed of ADC is 125kHz, using AVCC as analog reference and on-demand mode.
 * Then we will print the value in serial monitor when the position of the potentiometer was adjusted from 0 to 1023.
 * The Potentiometer will be assigned to the analog pin PC3(Analog pin A3) of Arduino UNO.
 * Owner: Muhammad Izzat 1717987
 * Date: 13 November 2020
 */


char*admux= (char*)0x7C; //Signed or unsigned does not matter if we do not do any decimal work.
volatile unsigned char*adcsra = (unsigned char*)0x7A;
volatile unsigned char*adch = (unsigned char*)0x79;
volatile unsigned char*adcl = (unsigned char*)0x78;



void setup() {
  
  *admux=0b01000011; //Set analog reference to AVCC and analog source to PC3.
  *adcsra=0b11000111; //Enable ADC, start conversion and set pre-scalerto 128.
  Serial.begin(9600); //Setting up the Baudrate at 9600

}

void loop() {
  
  while(1)
  {
     *adcsra|=0b01000000; //Start conversion (Set ADSC bit)
     while (((*adcsra) &0b01000000))//As long as ADSC bit is HIGH
     {
      //Do nothing
     }
    int lowbyte= (*adcl); //Capture low byte
    int highbyte= (*adch); //Capture high byte
    int value = (highbyte<<8) | lowbyte; //Merge high byte and low byte
    Serial.println(value);  //print the value in Serial monitor
  }

}
