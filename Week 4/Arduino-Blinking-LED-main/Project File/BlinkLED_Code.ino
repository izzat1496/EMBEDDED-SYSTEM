/*In this project, we will use arduino to control the blink of 2 LED with different ON and OFF time.
 * The yellow LED will be flashing with ON time of 750ms and OFF time of 350ms. Then, the red LED will be flashing needs to be flashing with ON time of 400ms and OFF time of 600ms.
 * Owner: Muhammad Izzat 1717987
 * Date: 4 November 2020
 */


//pin assignment declaration
#define RED_LED 9                       //Assign red LED to pin 9
#define YELLOW_LED 8                    //Assign yellow LED to pin 8

// Setup/initialization function(Only run once)
void setup() {

  pinMode (RED_LED, OUTPUT);            //Set pin 9 as output
  pinMode (YELLOW_LED, OUTPUT);         //Set pin 8 as output

  digitalWrite(RED_LED, LOW);           //Set red LED off initially
  digitalWrite(YELLOW_LED, LOW);        //Set red LED off initially
  
}

// Loop function (Run repeatedly)
void loop() {

  digitalWrite(YELLOW_LED, HIGH);       //Turn on yellow LED
  delay(750);                           //Delay for 750ms
  digitalWrite(YELLOW_LED, LOW);        //Turn off yellow LED
  delay(350);                           //Delay for 350ms
  digitalWrite(RED_LED, HIGH);          //Turn on red LED
  delay(400);                           //delay for 400ms
  digitalWrite(RED_LED, LOW);           //Turn off red LED
  delay(600);                           //delay for 600ms
  
}
