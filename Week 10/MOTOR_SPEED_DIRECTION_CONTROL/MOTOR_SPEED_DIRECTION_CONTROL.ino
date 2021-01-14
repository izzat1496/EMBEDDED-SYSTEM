#define in1 6
#define in2 7
#define button 4
int rotDirection = 0;
int pressed = false;
void setup() {
  Serial.begin(9600);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(button, INPUT);
  // Set initial rotation direction
  
  digitalWrite(in2, HIGH);
}
void loop() {
  int potValue = analogRead(A0); // Read potentiometer value
  int pwmOutput = map(potValue, 0, 1023, 0 , 255); // Map the potentiometer value from 0 to 255
  Serial.print("Speed: "); 
  Serial.println(pwmOutput);
  analogWrite(in1, pwmOutput); // Send PWM signal to Enable pin
  // Read button - Debounce
  if (digitalRead(button) == true) {
    pressed = !pressed;
  }
  while (digitalRead(button) == true);
  delay(20);
  // If button is pressed - change rotation direction
  if (pressed == true  & rotDirection == 0) {
    digitalWrite(in2, LOW);
    rotDirection = 1;
    delay(20);
  }
  // If button is pressed - change rotation direction
  if (pressed == false & rotDirection == 1) {
    digitalWrite(in2, HIGH);
    rotDirection = 0;
    delay(20);
  }
}
