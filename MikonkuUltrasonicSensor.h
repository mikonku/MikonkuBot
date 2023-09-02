#ifndef MikonkuUltrasonicSensor_h
#define MikonkuUltrasonicSensor_h

#include <Arduino.h>

class MikonkuUltrasonicSensor {
public:
  MikonkuUltrasonicSensor(int triggerPin = 5, int echoPin = 4); // Default pin Trigger ke D5, Echo ke D4
  void begin();
  int getDistance();
  float toCm(int distanceInMm);
  float toMm(int distanceInCm);

private:
  int triggerPin;
  int echoPin;
};

#endif
