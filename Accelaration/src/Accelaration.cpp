#include <Arduino.h>

// definition of pins
#define STEP_1 7
#define STEP_2 8

// time between steps without 2000
long long n = 90000000000;

void setup()
{
  // set pins to output
  pinMode(STEP_1, OUTPUT);
  pinMode(STEP_2, OUTPUT);
}

void loop()
{
  // rising step
  digitalWrite(STEP_1, HIGH);
  digitalWrite(STEP_2, HIGH);
  // minimum pulse duration, STEP high
  delayMicroseconds(2000);

  // dropping step
  digitalWrite(STEP_1, LOW);
  digitalWrite(STEP_2, LOW);
  delayMicroseconds(n);

  // for decreasing accelaration
  n-=4000 ;
}