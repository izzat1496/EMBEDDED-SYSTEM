/* In this project, we want to use Arduino UNO to prints out values from Analog input pin.
 * When the position of the potentiometer was adjusted, the serial monitor will print value from 0 to 1023 (according to the position of the potentiometer).
 * Owner: Muhammad Izzat 1717987
 * Date: 13 November 2020
 */

//global variable declaration
unsigned long value=0;

void setup() {
  
  Serial.begin(9600); //Setting up Serial Baudrate at 9600
  pinMode(A0, INPUT); //Set pin A0 as Input
}

void loop() {
  
  value = analogRead(A0); //store the analog input from potentiometer inside variable value.
  Serial.println(value);  //Print the value in serial monitor.
}
