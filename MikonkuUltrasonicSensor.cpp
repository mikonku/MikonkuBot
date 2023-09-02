#include "MikonkuUltrasonicSensor.h"

MikonkuUltrasonicSensor::MikonkuUltrasonicSensor(int triggerPin, int echoPin) {
  this->triggerPin = triggerPin;
  this->echoPin = echoPin;
}

void MikonkuUltrasonicSensor::begin() {
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

int MikonkuUltrasonicSensor::getDistance() {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration / 29.1; // Faktor konversi dari mikrodetik ke sentimeter
  return distance;
}

float MikonkuUltrasonicSensor::toCm(int distanceInMm) {
  return distanceInMm / 10.0; // Konversi milimeter ke sentimeter
}

float MikonkuUltrasonicSensor::toMm(int distanceInCm) {
  return distanceInCm * 10.0; // Konversi sentimeter ke milimeter
}
