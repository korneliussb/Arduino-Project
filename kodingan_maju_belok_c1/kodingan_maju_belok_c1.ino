/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Graphical representation is available using serial plotter (Tools > Serial Plotter menu)
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.
*/
#include <AFMotor.h>

AF_DCMotor kanandepan(4);
AF_DCMotor kananbelakang(1);
AF_DCMotor kiribelakang(2);
AF_DCMotor kiridepan(3);

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}
void ON(){
kanandepan.setSpeed(100);
  kanandepan.run(RELEASE);
  kiridepan.setSpeed(100);
  kiridepan.run(RELEASE);
  kananbelakang.setSpeed(100);
  kananbelakang.run(RELEASE);
  kiribelakang.setSpeed(100); 
  kiribelakang.run(RELEASE);
}
void maju (){
     kananbelakang.run(FORWARD);
  kananbelakang.setSpeed(100);
  kanandepan.run(FORWARD);
  kanandepan.setSpeed(100); 
  kiribelakang.run(FORWARD);
  kiribelakang.setSpeed(100);
  kiridepan.run(FORWARD);
  kiridepan.setSpeed(100);
  delay(1000);
}
void kiri(){
     kananbelakang.run(FORWARD);
  kananbelakang.setSpeed(100);
  kanandepan.run(FORWARD);
  kanandepan.setSpeed(100); 
  kiribelakang.run(BACKWARD);
  kiribelakang.setSpeed(100);
  kiridepan.run(BACKWARD);
  kiridepan.setSpeed(100);
  delay(1000);
}
void kanan(){
     kananbelakang.run(BACKWARD);
  kananbelakang.setSpeed(100);
  kanandepan.run(BACKWARD);
  kanandepan.setSpeed(100); 
  kiribelakang.run(FORWARD);
  kiribelakang.setSpeed(100);
  kiridepan.run(FORWARD);
  kiridepan.setSpeed(100);
  delay(1000);
}
// the loop routine runs over and over again forever:
void loop() {
maju();
kanan();
kiri();
 
}
