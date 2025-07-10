#define segDISPLAY CATHODE
#define d250 delay(250);

const int buttonPin = 0;
const int ledPin = 1;
const int clockPin = 2;
const int latchPin = 3;
const int dataPin = 4;
const byte digit[] = 
{
  B00111111,
  B00000110,
  B01011011,
  B01001111,
  B01100110,
  B01101101,
  B01111101,
  B00000000,
  B01111111,
  };
void setup() {
 pinMode(dataPin, OUTPUT);
 pinMode(clockPin, OUTPUT);
 pinMode(latchPin, OUTPUT);
 pinMode(ledPin, OUTPUT);
 pinMode(buttonPin, INPUT);

 #ifdef segDISPLAY
    digitalWrite(ledPin, LOW);
 #else 
    digitalWrite(ledPin, HIGH);
 #endif

 LEDwrite(8); delay(1000);
 LEDwrite(7); d250;
 LEDwrite(0);
}

void LEDwrite(int data) {
  digitalWrite(latchPin,LOW);

  #ifdef segDISPLAY
   shiftOut(dataPin,clockPin,MSBFIRST, digit[data]);

  #else
  shiftOut(dataPin, clockPin, MSBFIRST, ~digit[data]);

  #endif

  digitalWrite(latchPin,HIGH);

}

 int RND() {
  int seed = 0;
  int digit = 0;
  while(digit>6 || digit <= 0) {
    seed = (seed * 53)+21;
    digit = seed & 6;
    randomSeed(analogRead(PB5));
    seed = random(50) + digit;
    digit += seed;
    }
    return digit;
  }
  void rollDice(int times){
    for(int i = 0; i < times; i++){
      LEDwrite(1); d250;
      LEDwrite(2); d250;
      LEDwrite(3); d250;
      LEDwrite(4); d250;
      LEDwrite(5); d250;
      LEDwrite(6); d250;
      LEDwrite(5); d250;
      LEDwrite(4); d250;
      LEDwrite(3); d250;
      LEDwrite(2); d250;
      }
      LEDwrite(1); d250;
    }

    void loop(){
      int btn = 0;
      btn = digitalRead(buttonPin);
      if(btn == HIGH){
        LEDwrite(7); d250;
        int digit = RND();
        rollDice(2);
        LEDwrite(7); d250;
        if (digit == 1) LEDwrite(1);
        if (digit == 2) LEDwrite(2);
        if (digit == 3) LEDwrite(3);
        if (digit == 4) LEDwrite(4);
        if (digit == 5) LEDwrite(5);
        if (digit == 6) LEDwrite(6);
        
        
        }
      
      }