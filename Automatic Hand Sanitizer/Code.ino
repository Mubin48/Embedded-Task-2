#include<Servo.h>
const int servo = 9;
const int trigPin = 2;
const int echoPin = 3;
 long duration;
 long distance;
 Servo myservo;

 int pos = 0 ;

 void setup()
 {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(servo);
  myservo.write(0);
  Serial.begin(9600);
  }

  void loop()
  {
    digitalWrite(trigPin,LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delay(10);
    digitalWrite(trigPin,LOW);

    duration = pulseIn(echoPin, HIGH);

    distance = duration*0.034/2;
    Serial.print("Distance:");
    Serial.print(distance);

    if(distance<10){
    myservo.write(45);
    delay(100);
    myservo.write(90);
    delay(100);
    myservo.write(135);
    delay(100);
    myservo.write(180);
    delay(1000);
    myservo.write(0);
    delay(3000);
    }
    }
    