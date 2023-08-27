#include "MikonkuBot.h"
#include <Arduino.h>

MikonkuBot::MikonkuBot(int ENA, int IN1, int IN2, int IN3, int IN4, int ENB)
    : ENA_pin(ENA), IN1_pin(IN1), IN2_pin(IN2), IN3_pin(IN3), IN4_pin(IN4), ENB_pin(ENB) {
}

void MikonkuBot::begin() {
    pinMode(ENA_pin, OUTPUT);
    pinMode(IN1_pin, OUTPUT);
    pinMode(IN2_pin, OUTPUT);
    pinMode(IN3_pin, OUTPUT);
    pinMode(IN4_pin, OUTPUT);
    pinMode(ENB_pin, OUTPUT);
}

void MikonkuBot::setSpeed(int LEFT, int RIGHT) {
    analogWrite(ENA_pin, LEFT);
    analogWrite(ENB_pin, RIGHT);
}

void MikonkuBot::goForward(int delayTime) {
    digitalWrite(IN1_pin, LOW);
    digitalWrite(IN2_pin, HIGH);
    digitalWrite(IN3_pin, LOW);
    digitalWrite(IN4_pin, HIGH);
    delay(delayTime);
}

void MikonkuBot::goBackward(int delayTime) {
    digitalWrite(IN1_pin, HIGH);
    digitalWrite(IN2_pin, LOW);
    digitalWrite(IN3_pin, HIGH);
    digitalWrite(IN4_pin, LOW);
    delay(delayTime);
}

void MikonkuBot::goTurnLeft(int delayTime) {
    digitalWrite(IN1_pin, LOW);
    digitalWrite(IN2_pin, HIGH);
    digitalWrite(IN3_pin, HIGH);
    digitalWrite(IN4_pin, LOW);
    delay(delayTime);
}

void MikonkuBot::goTurnRight(int delayTime) {
    digitalWrite(IN1_pin, HIGH);
    digitalWrite(IN2_pin, LOW);
    digitalWrite(IN3_pin, LOW);
    digitalWrite(IN4_pin, HIGH);
    delay(delayTime);
}

void MikonkuBot::stop(unsigned int delayTime) {
    digitalWrite(IN1_pin, LOW);
    digitalWrite(IN2_pin, LOW);
    digitalWrite(IN3_pin, LOW);
    digitalWrite(IN4_pin, LOW);

    if (delayTime != 0) {
        delay(delayTime);
    }
}

void MikonkuBot::setPinENA(int pin) {
    ENA_pin = pin;
}

void MikonkuBot::setPinIN1(int pin) {
    IN1_pin = pin;
}

void MikonkuBot::setPinIN2(int pin) {
    IN2_pin = pin;
}

void MikonkuBot::setPinIN3(int pin) {
    IN3_pin = pin;
}

void MikonkuBot::setPinIN4(int pin) {
    IN4_pin = pin;
}

void MikonkuBot::setPinENB(int pin) {
    ENB_pin = pin;
}

void MikonkuBot::light(int pin, bool state) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, state);
}