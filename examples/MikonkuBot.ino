#include <MikonkuBot.h>

// Define the pins for your MikonkuBot instance
const int ENA_PIN = 11;
const int IN1_PIN = 10;
const int IN2_PIN = 9;
const int IN3_PIN = 8;
const int IN4_PIN = 7;
const int ENB_PIN = 6;

// Create an instance of MikonkuBot
MikonkuBot myBot(ENA_PIN, IN1_PIN, IN2_PIN, IN3_PIN, IN4_PIN, ENB_PIN);

void setup() {
  // Initialize the MikonkuBot
  myBot.begin();
}

void loop() {
  // Move forward
  myBot.goForward();
  delay(2000);

  // Stop
  myBot.stop();
  delay(1000);

  // Move backward
  myBot.goBackward();
  delay(2000);

  // Stop
  myBot.stop();
  delay(1000);

  // Turn left
  myBot.goTurnLeft();
  delay(1000);

  // Stop
  myBot.stop();
  delay(1000);

  // Turn right
  myBot.goTurnRight();
  delay(1000);

  // Stop
  myBot.stop();
  delay(1000);
}
