float gasSensor; //Analog pins do not need to be declared with their pin number.
float temp;
float vout;
float vout1;
int led=13;
int piezo=8;
void setup() {
   pinMode(A0,INPUT);
   pinMode(A1,INPUT);
   pinMode(led,OUTPUT);
   pinMode(piezo,OUTPUT);
   Serial.begin(9600);
}

void loop() {
  // Read temperature sensor
  vout=analogRead(A1); 
  vout1=(vout*5000)/1023; //Convert to millivolts
  temp=(vout1-500)*10; //Convert to Celsius
  //Read gas sensor
  gasSensor=analogRead(A0);
  //Fire detection condition
  if
  (temp>=80)
  {
    digitalWrite(led,HIGH);}
    else
    {
      digitalWrite(led,LOW);}
      if
      (gasSensor>=100)
      digitalWrite(piezo,HIGH);
      else
      {
        digitalWrite(piezo,LOW);
        }
        
        //Print sensor's value
        Serial.print("Temp:");
        Serial.print(temp);
        Serial.print("C");
        Serial.print("Gas Sensor:");
        Serial.println(gasSensor);
        delay(1000);
}
