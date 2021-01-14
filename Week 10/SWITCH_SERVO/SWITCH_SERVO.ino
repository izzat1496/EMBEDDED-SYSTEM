#include <Servo.h>

#define BUTTON1 4
#define BUTTON2 3

Servo myservo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position

void setup() {
  // put your setup code here, to run once:
  pinMode (BUTTON1, OUTPUT);
  pinMode (BUTTON2, OUTPUT);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  // put your main code here, to run repeatedly:

  if (digitalRead(BUTTON1) == HIGH)
  {
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }

  }
  
  if (digitalRead(BUTTON2) == HIGH)
  {
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
  }

}
