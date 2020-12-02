/* In this project, I will use Arduino needs to keep track of how many times each switch has been pressed.
 * There are 3 switches (A,B and C). When any of this switch was pressed, Arduino need to send out the information through the serial port.
 * Owner: Muhammad Izzat 1717987
 * Date: 4 November 2020
 */

 
//pin assignment declaration
#define SWITCH_A 10 //Assign switch A to digital pin 10
#define SWITCH_B 9  //Assign switch B to digital pin 9
#define SWITCH_C 8  //Assign switch C to digital pin 8

//global variable declaration
int A_COUNT = 0;
int B_COUNT = 0;
int C_COUNT = 0;

//function declaration
void disp(); //function to display output

void setup() {

  Serial.begin(9600);       //setting up Serial Baudrate at 9600

  pinMode(SWITCH_A, INPUT); //set switch A as input 
  pinMode(SWITCH_B, INPUT); //set switch B as input
  pinMode(SWITCH_C, INPUT); //set switch C as input

  disp(); //Initially display the output before starting up.
}

void loop() {

  //Check for switch condition
  if (digitalRead(SWITCH_A) == HIGH)
  {  
      A_COUNT++;   //count pressed switch
      disp();      //Call function display

      //To ensure that it will only count once before the switch released
      delay(200);  
      while(true)
      {
        if(digitalRead(SWITCH_A) == LOW)
        break;
      }
  }

  else if (digitalRead(SWITCH_B) == HIGH)
  {
      B_COUNT++;   //count pressed switch
      disp();      //Call function display
      delay(200);  

      //To ensure that it will only count once before the switch released
      while(true)
      {
        if(digitalRead(SWITCH_B) == LOW)
        break;
      }
  }

  else if (digitalRead(SWITCH_C) == HIGH)
  { 
      C_COUNT++;   //count pressed switch
      disp();      //Call function display

      //To ensure that it will only count once before the switch released
      delay(200);  
      while(true)
      {
        if(digitalRead(SWITCH_C) == LOW)
        break;
      }
  }

}

//This function is to display the count of each switch pressed
void disp() {
  Serial.print("A = ");
  Serial.print(A_COUNT);
  Serial.print("  B = ");
  Serial.print(B_COUNT);
  Serial.print("  C = ");
  Serial.println(C_COUNT);
}
