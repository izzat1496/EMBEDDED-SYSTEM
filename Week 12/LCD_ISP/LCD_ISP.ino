#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:

  lcd.init();

  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("EMBEDDED SYSTEM ");
  lcd.setCursor(2,1);
  lcd.print("SEM 1 (20/21)");

}

void loop() {
  // put your main code here, to run repeatedly:

}
