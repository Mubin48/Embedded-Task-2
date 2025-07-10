#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

long first = 0;
long second = 0;
double total = 0;

char customKey;
const byte row = 4;
const byte col = 4;

char keys[row][col] = {
  {'1', '2', '3', '+'},
  {'4', '5', '6', '-'},
  {'7', '8', '9', '*'},
  {'C', '0', '=', '/'}
};

byte rowPins[row] = {7, 6, 5, 4};
byte colPins[col] = {3, 2, 1, 0};

Keypad customKeypad = Keypad(makeKeymap(keys), rowPins, colPins, row, col);

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Calculator");
  lcd.setCursor(0, 1);
  lcd.print("Enter numbers");
  delay(4000);
  lcd.clear();
  lcd.setCursor(0, 0);
}

void loop() {
  customKey = customKeypad.getKey();

  switch (customKey) {
    case '0' ... '9':
      lcd.setCursor(0, 0);
      first = first * 10 + (customKey - '0');
      lcd.print(first);
      break;
      
    case '+':
      first = (total != 0 ? total : first);
      lcd.print("+");
      second = SecondNumber();
      total = first + second;
      lcd.setCursor(0, 1);
      lcd.print(total);
      first = 0;
      second = 0;
      break;

    case '-':
      first = (total != 0 ? total : first);
      lcd.print("-");
      second = SecondNumber();
      total = first - second;
      lcd.setCursor(0, 1);
      lcd.print(total);
      first = 0;
      second = 0;
      break;

    case '*':
      first = (total != 0 ? total : first);
      lcd.print("*");
      second = SecondNumber();
      total = first * second;
      lcd.setCursor(0, 1);
      lcd.print(total);
      first = 0;
      second = 0;
      break;

    case '/':
      first = (total != 0 ? total : first);
      lcd.print("/");
      second = SecondNumber();
      if (second != 0) {
        total = (double)first / second;
        lcd.setCursor(0, 1);
        lcd.print(total);
      } else {
        lcd.setCursor(0, 1);
        lcd.print("Error: Div by 0");
      }
      first = 0;
      second = 0;
      break;

    case 'C':
      total = 0;
      lcd.clear();
      break;
  }
}

long SecondNumber() {
  long second = 0;
  while (1) {
    customKey = customKeypad.getKey();
    if (customKey >= '0' && customKey <= '9') {
      second = second * 10 + (customKey - '0');
      lcd.setCursor(7, 0);
      lcd.print(second);
    }
    if (customKey == '=') break;
  }
  return second;
}