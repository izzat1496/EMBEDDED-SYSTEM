//This is a memory game where the user need to remember the sequence of the led. The sequence of the LED is random.
//After the LED finished showing the sequence, the user need to press the pushbutton and touch sensor that represent
//each LED respectively. Failure to follow the sequence will make the game reset to the lowest level (level 1)

#include <Wire.h>                                   // Library for IIC Serial Communication
#include <LiquidCrystal_I2C.h>                      // Library to use LCD 16x2

LiquidCrystal_I2C lcd(0x27, 16, 2);                 // set the LCD address to 0x27 for a 16 chars and 2 line display

// Pin initialization
const int button1 = 2;                              // 1st button controls First LED pin
const int button2 = 3;                              // 2nd button controls Second LED pin
const int button3 = 4;                              // 3rd button controls Third LED pin
const int button4 = 5;                              // 4th button controls Forth LED pin
const int ir = 6;                                   // IR Sensor pin
const int led1 = 7;                                 // First LED pin
const int led2 = 8;                                 // Second LED pin
const int led3 = 9;                                 // Third LED pin
const int led4 = 10;                                // Forth LED pin
const int buzzer = 11;                              // Buzzer pin
const int tones[] = {1915, 1700, 1519, 1432, 2700}; // tones when you press the LED's - the last one is when you fail.

// Variables declaration
int buttonState[] = {0, 0, 0, 0};                   // current state of the each button in array
int lastButtonState[] = {0, 0, 0, 0};               // previous state of the each button in array
int buttonPushCounter[] = {0, 0, 0, 0};


// Function to play the buzzer tone
void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    //Code to make the sound
    digitalWrite(buzzer, HIGH);
    delayMicroseconds(tone);
    digitalWrite(buzzer, LOW);
    delayMicroseconds(tone);
  }
}

//Setup function, only run once
void setup() {

  lcd.init();                // Initialize or turn on the IIC Communication for LCD
  lcd.backlight();           // Turn on LCD backlight

  // initialize all inputs:
  randomSeed(analogRead(0)); // Seed random for random number generator
  pinMode(button1, INPUT);   // First Button
  pinMode(button2, INPUT);   // Second Button
  pinMode(button3, INPUT);   // Third Button
  pinMode(button4, INPUT);   // Forth Button

  // initialize all outputs:
  pinMode(led1, OUTPUT);     // First LED
  pinMode(led2, OUTPUT);     // Second LED
  pinMode(led3, OUTPUT);     // Third LED
  pinMode(led4, OUTPUT);     // Forth LED
  pinMode(buzzer, OUTPUT);   // Buzzer

  // Display welcome message
  lcd.setCursor(0, 0);            //Set display cursor at first column first row
  lcd.print("   Welcome to   ");
  lcd.setCursor(0, 1);
  lcd.print("   Memory Game  ");  //Set display cursor at first column second row
  delay(3000);

  //Display the messsage if the user is ready or not
  lcd.clear();
  lcd.setCursor(0, 0);            //Set display cursor at first column first row
  lcd.print("     Ready?     ");
  lcd.setCursor(0, 1);            //Set display cursor at first column second row
  lcd.print(" Wave IR if Yes ");

  //keep on this loop until user trigger the ir sensor
  while (true)
  {
    if (digitalRead(ir) == 0)
      break;
  }

  // Display Loading message
  lcd.clear();                       //Clear old display
  lcd.setCursor(0, 0);               //Set display cursor at first column first row
  lcd.print("   Please wait  ");
  for (int i = 1; i < 6; i++)
  {
    lcd.setCursor(3 + i, 1);         //Set cursor at first row and column depending on i+3
    lcd.print(".");
    delay(1000);
  }

}

int game_on = 0;
int wait = 0;
int currentlevel = 1;       // This is the level (also the number of button presses to pass to next level)
long rand_num = 0;          //initialize long variable for random number from 0-100.
int rando = 0;              //initialize random integer for loopgame_on. Will be from 1-4 later.
int butwait = 500;          //amount of time to wait for next button input (ghetto de-bounce)
int ledtime = 500;          //amount of time each LED flashes for when button is pressed
int n_levels = 8;           //-1 number of levels until the game is won
int pinandtone = 0;         //This integer is used when the sequence is displayed
int right = 0;              //This variable must be 1 in order to go to the next level
int speedfactor = 5;        //This is the final speed of the lights and sounds for the last level. This increases as more games are won
int leddelay = 200;         //Initializing time for LED. This will decrease as the level increases

// Loop function, run repreatedly
void loop() {

  //Array level initialization
  int n_array[n_levels];
  int u_array[n_levels];

  int i, m;                                         // Variable declaration

  lcd.clear();                       //Clear old display
  lcd.setCursor(0, 0);               //Set display cursor at first column first row
  lcd.print("Start in:  ");
  for (int m = 3; m > 0; m--)
  {
    lcd.setCursor(12, 0);
    lcd.print(m);
    delay(1000);
  }

  lcd.clear();
  lcd.setCursor(0, 0);                              // Set display cursor at first column first row
  lcd.print("Current Level: ");
  lcd.setCursor(15, 0);                             // Set display cursor at first column second row
  lcd.print(currentlevel);

  //clears arrays both "n_array" and "u_array" and starts a new game
  if (game_on == 0) {
    for (i = 0; i < n_levels; i = i + 1) {
      n_array[i] = 0;
      u_array[i] = 0;
      rand_num = random(1, 200);                    // generate random number

      //Check generated number
      if (rand_num <= 50)                           // If less than or equal 50, then number to turn on LED is First LED for the current level on next sequence
        rando = 0;
      else if (rand_num > 50 && rand_num <= 100)    // If more than 50, less or equal 100, then number to turn on LED is Second LED for the current level on next sequence
        rando = 1;
      else if (rand_num > 100 && rand_num <= 150)   // If more than 100, less or equal 150, then number to turn on LED is Third LED for the current level on next sequence
        rando = 2;
      else if (rand_num <= 200)                     // If less than 200 ,then number to turn on LED is Second LED for the current level on next sequence
        rando = 3;
      //saves a random number in our n_array
      n_array[i] = rando;
    }
    game_on = 1;

  }


  // Shows the user the current sequence
  if (wait == 0) {
    delay (200);
    i = 0;
    for (i = 0; i < currentlevel; i = i + 1) {
      leddelay = ledtime / (1 + (speedfactor / n_levels) * (currentlevel - 1));
      pinandtone = n_array[i];
      digitalWrite(pinandtone + 7, HIGH);
      playTone(tones[pinandtone], leddelay);
      digitalWrite(pinandtone + 7, LOW);
      delay(100 / speedfactor);
    }
    wait = 1;
  }
  i = 0;
  int buttonchange = 0;
  int j = 0;                                           // This is the current position in the sequence
  while (j < currentlevel) {
    while (buttonchange == 0) {
      for (i = 0; i < 4; i = i + 1) {
        buttonState[i] = digitalRead(i + 2);
        buttonchange = buttonchange + buttonState[i];
      }
    }
    for (i = 0; i < 4; i = i + 1) {
      if (buttonState[i] == HIGH) {
        digitalWrite(i + 7, HIGH);
        playTone(tones[i], ledtime);
        digitalWrite(i + 7, LOW);
        wait = 0;
        u_array[j] = i;
        buttonState[i] = LOW;
        buttonchange = 0;
      }
    }
    if (u_array[j] == n_array[j]) {
      j++;
      right = 1;
    }
    else {

      right = 0;
      i = 4;
      j = currentlevel;
      wait = 0;
    }
  }

  // This is the code for LED and buzzer as indication if the user fail to the follow the correct sequence and reset to beginning
  if (right == 0) {

    lcd.clear();
    lcd.setCursor(0, 0);                   //Set display cursor at first column first row
    lcd.print("Wrong Sequence!");
    delay(300);
    i = 0;
    game_on = 0;
    currentlevel = 1;
    for (i = 0; i < 4; i = i + 1) {
      digitalWrite(i + 7, HIGH);
    }
    playTone(tones[4], ledtime);
    for (i = 0; i < 4; i = i + 1) {
      digitalWrite(i + 7, LOW);
    }
    delay (200);
    for (i = 0; i < 4; i = i + 1) {
      digitalWrite(i + 7, HIGH);
    }
    playTone(tones[4], ledtime);
    for (i = 0; i < 4; i = i + 1) {
      digitalWrite(i + 7, LOW);
    }

    delay(500);
    game_on = 0;

    //Display message if user want to play again
    lcd.clear();
    lcd.setCursor(0, 0);                    //Set display cursor at first column first row
    lcd.print("   Play again?  ");
    lcd.setCursor(0, 1);                    //Set display cursor at first column second row
    lcd.print(" Wave IR if Yes ");

    //keep on this loop until user trigger the ir sensor
    while (true)
    {
      if (digitalRead(ir) == 0)
        break;
    }

    // Display Loading message
    lcd.clear();                       //Clear old display
    lcd.setCursor(0, 0);               //Set display cursor at first column first row
    lcd.print("   Please wait  ");
    for (int i = 1; i < 6; i++)
    {
      lcd.setCursor(3 + i, 1);         //Set cursor at first row and column depending on i+3
      lcd.print(".");
      delay(1000);
    }

  }

  // If user insert the right sequence, increase level by one
  if (right == 1) {
    currentlevel++;
    wait = 0;
  }

  // If user finish the game, this is the tone and LED sequence as indication finished the game
  if (currentlevel == n_levels) {

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Congratulation! ");
    lcd.setCursor(0, 1);
    lcd.print("  You've won!   ");

    delay(500);
    // The following is the victory sound:
    int notes[] = {2, 2, 2, 2, 0, 1, 2, 1, 2};
    int note = 0;
    int tempo[] = {200, 200, 200, 400, 400, 400, 200, 200, 600};
    int breaks[] = {100, 100, 100, 200, 200, 200, 300, 100, 200};
    for (i = 0; i < 9; i = i + 1) {
      note = notes[i];
      digitalWrite(note + 7, HIGH);
      playTone(tones[note], tempo[i]);
      digitalWrite(note + 7, LOW);
      delay(breaks[i]);
    }

    // Sets everything back to the beginning
    game_on = 0;
    currentlevel = 1;
    n_levels = n_levels + 2;
    speedfactor = speedfactor + 1;

    //Display message if user want to play again
    lcd.clear();
    lcd.setCursor(0, 0);              //Set display cursor at first column first row
    lcd.print("   Play again?  ");
    lcd.setCursor(0, 1);              //Set display cursor at first column second row
    lcd.print(" Wave IR if Yes ");

    //keep on this loop until user trigger the ir sensor
    while (true)
    {
      if (digitalRead(ir) == 0)
        break;
    }

    // Display Loading message
    lcd.clear();                       //Clear old display
    lcd.setCursor(0, 0);               //Set display cursor at first column first row
    lcd.print("   Please wait  ");
    for (int i = 1; i < 6; i++)
    {
      lcd.setCursor(3 + i, 1);         //Set cursor at first row and column depending on i+3
      lcd.print(".");
      delay(1000);
    }
  }

}
