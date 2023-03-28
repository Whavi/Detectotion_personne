#include <Wire.h>
#include "Ultrasonic.h"

Ultrasonic ultrasonic1(8);
Ultrasonic ultrasonic2(10);
int count = 0;
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  long RangeInCentimeters1;
  RangeInCentimeters1 = ultrasonic1.MeasureInCentimeters();

  long RangeInCentimeters2;
  RangeInCentimeters2 = ultrasonic2.MeasureInCentimeters();



  if ((RangeInCentimeters1 < 100 && RangeInCentimeters1 > 200)  && (RangeInCentimeters2 > 100 && RangeInCentimeters2 < 200)) {
    count = count++; // si le capteur 1 réagit en premier ajouter +1 personne
  }

  Serial.print("Distance entrée :");
  Serial.print(RangeInCentimeters1);

  if ((RangeInCentimeters1 > 100 && RangeInCentimeters1 < 200) && (RangeInCentimeters2 < 100 && RangeInCentimeters2 > 200)) {
    count = count--; // si le capteur 2 réagit en premier ajouter -1 personne
  }

  Serial.print("Distance sortie :");
  Serial.print(RangeInCentimeters2);
}
