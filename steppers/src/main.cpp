#include <Arduino.h>

// definition of pins
#define STEP_1 7
#define STEP_2 8

#define target_s 1
#define r 0.02
#define K 200

int target = (int) ((target_s*K)/(2*M_PI*r));// Кол-во шагов для достижения нужныого пути 
int count = 0; // Для повтора пути


// t = target / 2 => acceleration & deceleration
int t = (int) (target / 2);

long long n = 50;

void acceleration()
{
  digitalWrite(STEP_1, HIGH);
  digitalWrite(STEP_2, HIGH);
  delay(n);
  digitalWrite(STEP_1, LOW);
  digitalWrite(STEP_2, LOW);
  delay(n);
  n -= 1;
}

void deceleration()
{
  digitalWrite(STEP_1, HIGH);
  digitalWrite(STEP_2, HIGH);
  delay(n);
  digitalWrite(STEP_1, LOW);
  digitalWrite(STEP_2, LOW);
  delay(n);
  n += 1;
}

void constant_speed()
{
  digitalWrite(STEP_1, HIGH);
  digitalWrite(STEP_2, HIGH);
  delay(1);
  digitalWrite(STEP_1, LOW);
  digitalWrite(STEP_2, LOW);
  delay(1);
}

void setup() {
  pinMode(STEP_1, OUTPUT);
  pinMode(STEP_2, OUTPUT);

  // or t = n / 1 => acceleration & horizontal line & deceleration
  if (target > 100) t = 50;
}

void loop() {
  if (count < target)
  {
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
}