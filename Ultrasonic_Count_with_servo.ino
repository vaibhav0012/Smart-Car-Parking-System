#include <Servo.h>

Servo myservo;  // create servo object to control a servo
Servo myservoo;
int potpin = 0;  // analog pin used to connect the potentiometer
int val; 
int trigPin = 11;    // Trigger ENTRY
int echoPin = 12;    // Echo  ENTRY
int trig=7;// Trigger EXIT
int echo=6;// Echo  EXIT
long duration, cm, cm1,inches;
int count=0;
int count1;
int pos=0;
 
void setup() {
  //Serial Port beginlmnnnnnnnnnnnnnno9
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object ENTRY
  myservoo.attach(10);// attaches the servo on pin 9 to the servo object ENTRY
}
 
void loop() {
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // Convert the time into a distance
  cm = (duration/2) / 29.1; 
  // Divide by 29.1 or multiply by 0.0343
  //inches = (duration/2) / 74;   // Divide by 74 or multiply by 0.0135
  
  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echo, INPUT);
  duration = pulseIn(echo, HIGH);
 
  // Convert the time into a distance
  cm1 = (duration/2) / 29.1; 
  
  if(cm<150)
  {count1=count;
    count++;
  //Serial.print(inches);
  //Serial.print("in, ");
  //Serial.print(cm);
  //Serial.print("cm");
  
  if(count<10)
  {
    if(count!=count1)
    {
      Serial.print("Welcome ");
      Serial.print(10-count);
      Serial.println(" places left");
      for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
    }
  }
  if(count==10)
  {
    //Serial.println(count);
    Serial.println("No space left");
  }
  if(count==11)
  {
    exit(0);
    
  }
  delay(500);
}
if(cm1<cm)
{
if(cm1<5)
  {count1=count;
    count--;
  //Serial.print(inches);
  //Serial.print("in, ");
  //Serial.print(cm);
  //Serial.print("cm");
  
  if(count<10&&count>0)
  {
    if(count!=count1)
    {
      Serial.print("");
      Serial.print(10-count);
      Serial.println(" places left");
      for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservoo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservoo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
    }
  }
  if(count==0)
  {
    //Serial.println(count);
    Serial.println("Empty");
  }
  
  delay(500);
}
}
}
