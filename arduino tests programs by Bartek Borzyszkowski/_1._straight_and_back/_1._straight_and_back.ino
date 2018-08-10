//Robotics in India by Bartlomiej Borzyszkowski, Karunya Institute of Technology and Sciences, IAESTE internship 2018

#include <time.h>

// Adding constant PINs:
const int wheel1_forward = 2;     // digital 2
const int wheel1_reverse = 3;     // digital 3
const int wheel1_enable1 = 4;     // digital 4
const int wheel2_enable2 = 5;     // digital 5
const int wheel2_forward = 6;     // digital 6
const int wheel2_reverse = 7;     // digital 7

//initializing 
void setup()
{
  pinMode(wheel1_forward, OUTPUT);
  pinMode(wheel1_reverse, OUTPUT);
  pinMode(wheel1_enable1, OUTPUT);
  pinMode(wheel2_forward, OUTPUT);
  pinMode(wheel2_reverse, OUTPUT);
  pinMode(wheel2_enable2, OUTPUT);
}

//main steering
void loop()
{
movement();
}

//moovement combination
void movement()
  {
  delay (2000);
  straight();
  delay (4000);
  wait();
  delay (2000);
  back();
  delay (4000);
  wait();
  }

//going straight forward
void straight()
  {
  digitalWrite(wheel1_enable1, HIGH);
  digitalWrite(wheel2_enable2, HIGH);
  digitalWrite(wheel1_forward, HIGH);
  digitalWrite(wheel2_forward, HIGH);
  digitalWrite(wheel1_reverse, LOW);
  digitalWrite(wheel2_reverse, LOW);
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





