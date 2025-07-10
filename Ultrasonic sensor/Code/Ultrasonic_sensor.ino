int trig=10;
int echo=9;
long time;
long distance;
void setup() {
 pinMode(trig,OUTPUT);
 pinMode(echo,INPUT);
 Serial.begin(9600);

}

void loop() {
  digitalWrite(trig,LOW);
  delay(2);
  digitalWrite(trig,HIGH);
  delay(10);
  digitalWrite(trig,LOW);
  time=pulseIn(9,HIGH);
  distance=time*0.034/2;
  Serial.print("Distance:");
  Serial.println(distance);
}
