// C++ code
//
int sensorValue;
void setup()
{
  pinMode(A0, INPUT);
  pinMode(9,OUTPUT);
  Serial.begin(9600);
}

void loop()
{ 
  sensorValue=analogRead(A0);//Read photoresistor.The range of the input value of photoresistor is 0-1023.
 Serial.println(sensorValue);//Print input value.
  analogWrite(9,map(sensorValue,0,1023,0,255));//Convert analog input to PWM signal and change light intensity by measuring photoresistor's value.Analog signal's range is 0-1023 and PWM signal range is 0-255.
  delay(100);
}