/* In this project, we will use arduino to control the blink of 8 LED with different ON and OFF time.
 *  
 *           ON TIME       OFF TIME        
 *LED 1       781ms         515ms
 *LED 2       2014ms        1348ms
 *LED 3       343ms         573ms
 *LED 4       678ms         1839ms
 *LED 5       342ms         534ms
 *LED 6       1478ms        326ms
 *LED 7       1859ms        351ms
 *LED 8       777ms         888ms
 *
 * Owner: Muhammad Izzat 1717987
 * Date: 4 November 2020
 */


//pin assignment declaration
#define LED_1 0 //Assign LED 1 to pin 0                      
#define LED_2 1 //Assign LED 2 to pin 1 
#define LED_3 2 //Assign LED 3 to pin 2 
#define LED_4 3 //Assign LED 4 to pin 3                     
#define LED_5 4 //Assign LED 5 to pin 4 
#define LED_6 5 //Assign LED 6 to pin 5 
#define LED_7 6 //Assign LED 7 to pin 6
#define LED_8 7 //Assign LED 8 to pin 7 

// Setup/initialization function(Only run once)
void setup() {

  pinMode (LED_1, OUTPUT);            //Set LED 1 as output
  pinMode (LED_2, OUTPUT);            //Set LED 2 as output
  pinMode (LED_3, OUTPUT);            //Set LED 3 as output
  pinMode (LED_4, OUTPUT);            //Set LED 4 as output
  pinMode (LED_5, OUTPUT);            //Set LED 5 as output
  pinMode (LED_6, OUTPUT);            //Set LED 6 as output
  pinMode (LED_7, OUTPUT);            //Set LED 7 as output
  pinMode (LED_8, OUTPUT);            //Set LED 8 as output

  digitalWrite(LED_1, LOW);           //Set LED 1 off initially
  digitalWrite(LED_2, LOW);           //Set LED 2 off initially
  digitalWrite(LED_3, LOW);           //Set LED 3 off initially
  digitalWrite(LED_4, LOW);           //Set LED 4 off initially
  digitalWrite(LED_5, LOW);           //Set LED 5 off initially
  digitalWrite(LED_6, LOW);           //Set LED 6 off initially
  digitalWrite(LED_7, LOW);           //Set LED 7 off initially
  digitalWrite(LED_8, LOW);           //Set LED 8 off initially
  
}

// Loop function (Run repeatedly)
void loop() {

  digitalWrite(LED_1, HIGH);       //Turn on LED 1
  delay(781);                      //Delay for 781ms
  digitalWrite(LED_1, LOW);        //Turn off LED 1
  delay(515);                      //Delay for 515ms
  digitalWrite(LED_2, HIGH);       //Turn on LED 2
  delay(2014);                      //Delay for 2014ms
  digitalWrite(LED_2, LOW);        //Turn off LED 2
  delay(1348);                      //Delay for 1348ms
  digitalWrite(LED_3, HIGH);       //Turn on LED 3
  delay(343);                      //Delay for 343ms
  digitalWrite(LED_3, LOW);        //Turn off LED 3
  delay(573);                      //Delay for 573ms
  digitalWrite(LED_4, HIGH);       //Turn on LED 4
  delay(678);                      //Delay for 678ms
  digitalWrite(LED_4, LOW);        //Turn off LED 4
  delay(1839);                      //Delay for 1839ms
  digitalWrite(LED_5, HIGH);       //Turn on LED 5
  delay(342);                      //Delay for 342ms
  digitalWrite(LED_5, LOW);        //Turn off LED 4
  delay(534);                      //Delay for 534ms
  digitalWrite(LED_6, HIGH);       //Turn on LED 6
  delay(1478);                      //Delay for 781ms
  digitalWrite(LED_6, LOW);        //Turn off LED 6
  delay(326);                      //Delay for 515ms
  digitalWrite(LED_7, HIGH);       //Turn on LED 7
  delay(1859);                      //Delay for 1859ms
  digitalWrite(LED_7, LOW);        //Turn off LED 7
  delay(351);                      //Delay for 351ms
  digitalWrite(LED_8, HIGH);       //Turn on LED 8
  delay(777);                      //Delay for 777ms
  digitalWrite(LED_8, LOW);        //Turn off LED 8
  delay(888);                      //Delay for 888ms
  
}
