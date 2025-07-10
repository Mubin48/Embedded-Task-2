#include<IRremote.h>

int IR_Recv=12;
int bluepin=2;
int orangePin=3;
int greenPin=4;

IRrecv irrecv(IR_Recv);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
}

void loop()
{
  if(irrecv.decode(&results))
  {
    long int decCode=results.value;
    Serial.println(results.value);
    switch(results.value)
    {
      case 4044077843:
      	digitalWrite(2,HIGH);
      	break;
      case 3824495964:
      	digitalWrite(2,LOW);
      	break;
      case 16599223:
      	digitalWrite(3,HIGH);
      	break;
      case 16591063:
      	digitalWrite(3,LOW);
      	break;
      case 16623703:
      	digitalWrite(4,HIGH);
      	break;
      case 16607383:
      	digitalWrite(4,LOW);
      	break;
    }
    irrecv.resume();
  }
  delay(10);
}