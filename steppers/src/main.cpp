#include <Arduino.h>

// definition of pins
#define STEP_1 7
#define STEP_2 8

#define target_s 1
#define r 0.02
#define K 200

int target = (int) ((target_s*K)/(2*M_PI*r));// Кол-во шагов для достижения нужныого пути 
int present = 0; // Текущий шаг
int count = 0; // Для повтора пути
int mode = 0; // 0 - наверх, 1 - вниз

long long n = 90000000;

void acceleration()
{
  digitalWrite(STEP_1, HIGH);
  digitalWrite(STEP_2, HIGH);
  delay(80000);
  digitalWrite(STEP_1, LOW);
  digitalWrite(STEP_2, LOW);
  delayMicroseconds(n);
  n -= 80000;
}

void deceleration()
{
  digitalWrite(STEP_1, HIGH);
  digitalWrite(STEP_2, HIGH);
  delayMicroseconds(80000);
  digitalWrite(STEP_1, LOW);
  digitalWrite(STEP_2, LOW);
  delayMicroseconds(n);
  n += 80000;
}

void constant_speed()
{
  digitalWrite(STEP_1, HIGH);
  digitalWrite(STEP_2, HIGH);
  delayMicroseconds(80000);
  digitalWrite(STEP_1, LOW);
  digitalWrite(STEP_2, LOW);
  delayMicroseconds(80000);
}

void setup() {
  pinMode(STEP_1, OUTPUT);
  pinMode(STEP_2, OUTPUT);
}

void loop() {
  // 
  int t = target;
  if (target > 2250) t = 1125;

  for (int i = 0; i < t; i++) acceleration();

  int const_time = target - 2*t;
  for (int i = 0; i < const_time; i++) constant_speed();

  for (int i = 0; i < t; i++) deceleration();
}