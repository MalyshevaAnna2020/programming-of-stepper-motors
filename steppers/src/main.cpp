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


// t = target / 2 => acceleration & deceleration
int t = (int) (target / 2);

long long n = 300000;

void acceleration()
{
  digitalWrite(STEP_1, HIGH);
  digitalWrite(STEP_2, HIGH);
  delayMicroseconds(2000);
  digitalWrite(STEP_1, LOW);
  digitalWrite(STEP_2, LOW);
  delay(n);
  n -= 2000;
}

void deceleration()
{
  digitalWrite(STEP_1, HIGH);
  digitalWrite(STEP_2, HIGH);
  delayMicroseconds(2000);
  digitalWrite(STEP_1, LOW);
  digitalWrite(STEP_2, LOW);
  delay(n);
  n += 2000;
}

void constant_speed()
{
  digitalWrite(STEP_1, HIGH);
  digitalWrite(STEP_2, HIGH);
  delayMicroseconds(2000);
  digitalWrite(STEP_1, LOW);
  digitalWrite(STEP_2, LOW);
  delayMicroseconds(2000);
}

void setup() {
  pinMode(STEP_1, OUTPUT);
  pinMode(STEP_2, OUTPUT);

  // or t = n / 2 000 => acceleration & horizontal line & deceleration
  if (target > 100) t = 50;
}

void loop() {
  if (count < t)
  {
    acceleration();
  }
  else 
  {
    if (count > target - t) deceleration();
    else constant_speed();
  }

  count++;
}