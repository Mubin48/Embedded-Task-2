// C++ code
//
int temp=A0;
float temp_celsius;
float analog_reading;
float voltage;
float temp_far;
void setup()
{
  pinMode(temp, INPUT);
  Serial.begin(9600);
}

void loop()
{
analog_reading=analogRead(A0);
  Serial.print("Analog reading:");
  Serial.println(analog_reading);
  voltage=analog_reading*5/1024;
  Serial.print("Voltage reading:");
  Serial.println(voltage);
  temp_celsius=(voltage-.5)*100;
  Serial.print("Celsius reading: ");
    Serial.print(temp_celsius);
  Serial.println("C ");
  
  temp_far=(temp_celsius*9/5)+32;
  Serial.print("Farenhait reading:");
  Serial.print(temp_far);
  Serial.println("F/n");
  delay(3000);
  
}