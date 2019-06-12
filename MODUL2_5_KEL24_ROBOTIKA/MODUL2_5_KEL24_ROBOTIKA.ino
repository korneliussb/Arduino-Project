#include <Servo.h>
Servo servoMain;
void setup()
{
  servoMain.attach(12);
  pinMode(13, OUTPUT);
}
void loop()
{
  servoMain.write(30);
  digitalWrite(13, LOW);
  delay(1000);
  servoMain.write(90);
  digitalWrite(13, HIGH);
  delay(1000);
  servoMain.write(150);
  digitalWrite(13, LOW);
  delay(1000);
  servoMain.write(90);
  digitalWrite(13, HIGH);
  delay(1000);
}
