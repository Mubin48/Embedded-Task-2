#include <Keypad.h>

//keypad configuration(4*4)

const byte ROWS=4;
const byte COLS=4;

char numPad[ROWS][COLS]={
 {'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};


byte rowPins[ROWS]={9,8,7,6};
byte colPins[COLS]={5,4,3,2};

//Pins definition
const int greenLed=11;
const int redLed=10;
const int piezo=12;

Keypad cKeypad = Keypad(makeKeymap(numPad),rowPins,colPins,ROWS,COLS);//Converts input keys[] array into a format the library understands
//Pssword & input management
String password="6556";
String vstup="";
void setup()
{
  pinMode(redLed, OUTPUT);
    pinMode(greenLed, OUTPUT);
    pinMode(piezo, OUTPUT);
  digitalWrite(redLed,HIGH);//It ensures the red led turn on when the arduino start or reset.It works before the firs loop cycle begins. 
  Serial.begin(9600);
  Serial.print("Enter Passcode: ");
}

void loop()
{
  char cKey = cKeypad.getKey();
  if(cKey)
  {
  if(vstup.length()<4)
  {
    Serial.print("*");
    vstup += cKey;
  }
  }
  if(vstup.length()==4)
  {
    delay(1500);
 if(password==vstup)
 {
   Serial.println("\nEnter");
   digitalWrite(redLed,LOW);
   digitalWrite(greenLed,HIGH);
   tone(piezo,500);
   delay(100);
   noTone(piezo);
 }
    else
    {
    Serial.print("\nWrong Passcode");
    digitalWrite(redLed,HIGH);
      digitalWrite(greenLed,LOW);
      tone(piezo,1000);
      delay(800);
      noTone(piezo);
    }
    delay(1500);
    vstup="";
    Serial.println("Enter Passcode: ");
    digitalWrite(redLed,HIGH);
    digitalWrite(greenLed,LOW);
  }
}