#include <SoftwareSerial.h>
#include <MikonkuBot.h>


// MENENTUKAN INSTANCE UNTUK BLUETOOTH
SoftwareSerial bluetooth(2, 3);


// Define the pins for your MikonkuBot instance
const int ENA_PIN = 11;
const int IN1_PIN = 10;
const int IN2_PIN = 9;
const int IN3_PIN = 8;
const int IN4_PIN = 7;
const int ENB_PIN = 6;
const int LED_PIN = 13;

// VARIABLE UNTUK MENAMPUNG DATA DARI REMOTE CONTROL
char data;

// Create an instance of MikonkuBot
MikonkuBot myBot(ENA_PIN, IN1_PIN, IN2_PIN, IN3_PIN, IN4_PIN, ENB_PIN);


void setup() {
  bluetooth.begin(9600);
  Serial.begin(9600);
  Serial.println("Robot Started");

  // Initialize the MikonkuBot
  myBot.begin();
  myBot.setSpeed(200,200);
  
}

void loop() {

  // CEK APAKAH ADA SIGNAL YANG DIKIRIM OLEH TRANSMITTER/REMOTE
  if (bluetooth.available() > 0) {

    // JIKA ADA SIGNAL DARI TRANSMITTER/REMOTE BACA DATA YANG DIKIRIM
    data = bluetooth.read();

    // CETAK DATA YANG DITERIMA KE SERIAL MONITOR
    Serial.println(data);

    // KONTROL SETIAP DATA
    if (data == 'F') {
      myBot.light(LED_PIN,HIGH);
      myBot.goForward(50);
    } else if (data == 'B') {
      myBot.light(LED_PIN,HIGH);
      myBot.goBackward(50);
    } else if (data == 'R') {
      myBot.light(LED_PIN,HIGH);
      myBot.goTurnRight(50);
    } else if (data == 'L') {
      myBot.light(LED_PIN,HIGH);
      myBot.goTurnLeft(50);
    } else {
      myBot.light(LED_PIN,LOW);
      myBot.stop();
    }
  }

  // MEMBERI JEDA 50 milisekon UNTUK ARDUINO
  delay(50);
}