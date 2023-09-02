#include <MikonkuUltrasonicSensor.h>

MikonkuUltrasonicSensor ultrasonic(5, 4); // Pin Trigger ke D5, Pin Echo ke D4

void setup() {
  Serial.begin(9600);
  ultrasonic.begin();
}

void loop() {
  int distance = ultrasonic.getDistance();
  float distanceInCm = ultrasonic.toCm(distance);
  float distanceInMm = ultrasonic.toMm(distanceInCm);

  Serial.print("Jarak: ");
  Serial.print(distanceInCm);
  Serial.print(" cm atau ");
  Serial.print(distanceInMm);
  Serial.println(" mm");

  delay(1000);
}
