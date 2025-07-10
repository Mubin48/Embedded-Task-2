#include<LiquidCrystal.h>
LiquidCrystal lcd(0,1,2,3,4,5);

void setup() {
  lcd.begin(16,2);
  lcd.print("this is me");
  lcd.setCursor(0,1);
  lcd.print("hello");
}

void loop() {
  lcd.setCursor(14,1);
  lcd.print(millis()/1000);
  delay(100);
}