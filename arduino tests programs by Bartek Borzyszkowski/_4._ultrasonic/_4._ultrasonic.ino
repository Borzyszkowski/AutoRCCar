//Robotics in India by Bartlomiej Borzyszkowski, Karunya Institute of Technology and Sciences, IAESTE internship 2018

#include <time.h>

// Adding constant PINs:
const int wheel1_forward = 2;     // digital 2
const int wheel1_reverse = 3;     // digital 3
const int wheel1_enable1 = 4;     // digital 4
const int wheel2_enable2 = 5;     // digital 5
const int wheel2_forward = 6;     // digital 6
const int wheel2_reverse = 7;     // digital 7

const int echoPin = 8; //digital 8
const int trigPin = 9; //digital 9


// Adding variables
long duration;
int distance;

//initializing 
void setup()
{
  pinMode(wheel1_forward, OUTPUT);
  pinMode(wheel1_reverse, OUTPUT);
  pinMode(wheel1_enable1, OUTPUT);
  pinMode(wheel2_forward, OUTPUT);
  pinMode(wheel2_reverse, OUTPUT);
  pinMode(wheel2_enable2, OUTPUT);
  
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);  // Sets the echoPin as an Input
  Serial.begin(9600);       // Starts the serial communication
}

//main steering
void loop()
{
movement();
}

//movement combination
void movement()
  {
  ultrasonic();
  /*
  delay (2000);
  straight();
  delay (2500);
  wait();
  delay (2000);
  right();
  delay (600);
  wait();
  */
  }

//going straight forward
void straight()
  {
  digitalWrite(wheel1_forward, HIGH);
  digitalWrite(wheel2_forward, HIGH);
  digitalWrite(wheel1_reverse, LOW);
  digitalWrite(wheel2_reverse, LOW);
  digitalWrite(wheel1_enable1, HIGH);
  digitalWrite(wheel2_enable2, HIGH);
  return;
  }

//going back
void back()
  {
  digitalWrite(wheel1_forward, LOW);
  digitalWrite(wheel2_forward, LOW);
  digitalWrite(wheel1_reverse, HIGH);
  digitalWrite(wheel2_reverse, HIGH);
  digitalWrite(wheel1_enable1, HIGH);
  digitalWrite(wheel2_enable2, HIGH);
  return;
  }

//waiting for next instruction
void wait()
  {
  digitalWrite(wheel1_forward, LOW);
  digitalWrite(wheel2_forward, LOW);
  digitalWrite(wheel1_reverse, LOW);
  digitalWrite(wheel2_reverse, LOW);
  digitalWrite(wheel1_enable1, HIGH);
  digitalWrite(wheel2_enable2, HIGH);
  return;
  }

//turning left
void left()
  {
  digitalWrite(wheel1_forward, HIGH);
  digitalWrite(wheel2_forward, LOW);
  digitalWrite(wheel1_reverse, LOW);
  digitalWrite(wheel2_reverse, HIGH);
  digitalWrite(wheel1_enable1, HIGH);
  digitalWrite(wheel2_enable2, HIGH);
  return;
  }

//turning right
void right()
  {
  digitalWrite(wheel1_forward, LOW);
  digitalWrite(wheel2_forward, HIGH);
  digitalWrite(wheel1_reverse, HIGH);
  digitalWrite(wheel2_reverse, LOW);
  digitalWrite(wheel1_enable1, HIGH);
  digitalWrite(wheel2_enable2, HIGH);
  return;
  }

//turning right
void straight_right()
  {
  digitalWrite(wheel1_forward, HIGH);
  digitalWrite(wheel2_forward, HIGH);
  digitalWrite(wheel1_reverse, LOW);
  digitalWrite(wheel2_reverse, LOW);
  analogWrite(wheel1_enable1, 157); //188,4 to make a 100cm circle (+10 cm for a wheel) -> 2PI*60=376,8
  analogWrite(wheel2_enable2, 188.4);   //157 to make a 100cm circle -> 2PI*50=314
  return;
  }

void ultrasonic() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance
  distance= duration*0.034/2;
  
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  
  if (distance>20)
  straight();  
  else{
  wait();
  delay (2000);
  right();
  delay (500);
  wait();
  delay (4000);}
}


