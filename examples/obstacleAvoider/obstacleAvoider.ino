#include <MikonkuBot.h>
#include <MikonkuUltrasonicSensor.h>

const int ENA_PIN = 11;
const int IN1_PIN = 10;
const int IN2_PIN = 9;
const int IN3_PIN = 8;
const int IN4_PIN = 7;
const int ENB_PIN = 6;

// Inisialisasi objek robot dan sensor ultrasonik
MikonkuBot myBot(ENA_PIN, IN1_PIN, IN2_PIN, IN3_PIN, IN4_PIN, ENB_PIN);
MikonkuUltrasonicSensor ultrasonic(5, 4); // Pin Trigger ke D5, Pin Echo ke D4

const int obstacleThreshold = 30; // Jarak batasan untuk menghindari rintangan (misalnya, 10 cm)

void setup() {
  myBot.begin(); // Memulai kontrol motor
  myBot.setSpeed(100, 100); // Atur kecepatan motor kiri dan kanan (misalnya, 100)
  Serial.begin(9600);
  ultrasonic.begin();
}

void loop() {
  // Baca jarak ke depan
  int distance = ultrasonic.getDistance();
  
  if (distance >= obstacleThreshold) {
    // Tidak ada penghalang di depan, maju
    myBot.goForward(1000); // Maju selama 1 detik
  } else {
    // Ada penghalang di depan, cek sisi kiri dan kanan
    int leftDistance;
    int rightDistance;

    // Putar ke kiri
    myBot.goTurnLeft(1000); // Putar ke kiri selama 1 detik
    leftDistance = ultrasonic.getDistance();

    // Putar ke kanan
    myBot.goTurnRight(2000); // Putar ke kanan selama 2 detik (putaran 180 derajat)
    rightDistance = ultrasonic.getDistance();

    // Kembali ke posisi awal
    myBot.goTurnLeft(1000); // Putar ke kiri selama 1 detik

    if (leftDistance > rightDistance) {
      // Lebih aman ke kiri, putar ke kiri
      myBot.goTurnLeft(1000); // Putar ke kiri selama 1 detik
    } else {
      // Lebih aman ke kanan atau sama-sama aman, putar ke kanan
      myBot.goTurnRight(1000); // Putar ke kanan selama 1 detik
    }
  }
}
