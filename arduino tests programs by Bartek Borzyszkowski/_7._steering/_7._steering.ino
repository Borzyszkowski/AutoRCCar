#include <time.h>

#define m11 2
#define m12 3
#define m21 6
#define m22 7

const int wheel1_enable1 = 4;     // digital 4
const int wheel2_enable2 = 5;     // digital 5

const int echoPin = 8; //digital 8
const int trigPin = 9; //digital 9

// Adding variables
long duration;
int distance;

void setup()
{
  pinMode(m11, OUTPUT);
  pinMode(m12, OUTPUT);
  pinMode(m21, OUTPUT);
  pinMode(m22, OUTPUT);
  pinMode(wheel1_enable1, OUTPUT);
  pinMode(wheel2_enable2, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);  // Sets the echoPin as an Input
  Serial.begin(9600);
}

void control (int distance)
{
  Serial.print("Distance: ");
  Serial.println(distance);
  Serial.print(' ');
  char In=Serial.read();
  Serial.print("Contol: ");
  Serial.print(In);
  Serial.print(' ');

   if (distance <15)
    {
      digitalWrite(m11, LOW);
      digitalWrite(m12, LOW);
      digitalWrite(m21, LOW);
      digitalWrite(m22, LOW);
    }

    else if (In=='f' || In=='F' || In==1 || In=='1')   // Forward
    {   
      digitalWrite(m11, HIGH);
      digitalWrite(m21, HIGH);
      digitalWrite(m12, LOW);
      digitalWrite(m22, LOW);
      digitalWrite(wheel1_enable1, HIGH);
      digitalWrite(wheel2_enable2, HIGH);
    }
  
    else if(In=='b' || In=='B' || In==2 || In=='2')    //backward
    {
      digitalWrite(m11, LOW);
      digitalWrite(m12, HIGH);
      digitalWrite(m21, LOW);
      digitalWrite(m22, HIGH);
      digitalWrite(wheel1_enable1, HIGH);
      digitalWrite(wheel2_enable2, HIGH);
    }

    else if(In=='l' || In=='L'|| In==3 || In=='3')     // Left
    {
      digitalWrite(m11, HIGH);
      digitalWrite(m12, LOW);
      digitalWrite(m21, LOW);
      digitalWrite(m22, LOW);
      digitalWrite(wheel1_enable1, HIGH);
      digitalWrite(wheel2_enable2, HIGH);
    }
    
     else if(In=='r' || In=='R'|| In==4 || In=='4')     // Right
    {
      digitalWrite(m11, LOW);
      digitalWrite(m12, LOW);
      digitalWrite(m21, HIGH);
      digitalWrite(m22, LOW);
      digitalWrite(wheel1_enable1, HIGH);
      digitalWrite(wheel2_enable2, HIGH);
    }
        
     else if(In=='s' || In=='S' || In==5 || In=='5')    // stop
    {
      digitalWrite(m11, LOW);
      digitalWrite(m12, LOW);
      digitalWrite(m21, LOW);
      digitalWrite(m22, LOW);
      digitalWrite(wheel1_enable1, LOW);
      digitalWrite(wheel2_enable2, LOW);
    }
}

void ultrasonic (){
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
    
    // Prinfts the distance on the Serial Monitor
    //Serial.print("Distance: ");
    //Serial.println(distance);

    control(distance);
  }
  


void loop()
{
  ultrasonic();
}

