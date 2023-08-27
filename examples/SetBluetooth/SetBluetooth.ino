#include <SoftwareSerial.h>
SoftwareSerial bluetooth(2, 3); 
char data;
void setup()
{
  Serial.begin(9600);
  Serial.println("Enter AT commands:");
  bluetooth.begin(38400);
}

void loop()
{
  // JIKA ADA PESAN DARI MODUL BLUETOOTH
  if (bluetooth.available()){
    // MAKA PESAN TERSEBUT AKAN DITAMPILKAN PADA SERIAL MONITOR
    Serial.print(bluetooth.readString());
  }
  // JIKA ADA COMMAND DARI USER
  if (Serial.available()){
    // MAKA COMMAND AKAN DIKIRIMKAN KE BLUETOOTH
    data = Serial.read();
    bluetooth.write(data);
  }
}