/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Graphical representation is available using serial plotter (Tools > Serial Plotter menu)
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.
*/
#include <AFMotor.h>
#include <Servo.h>
Servo Claw;
int pos=0;
AF_DCMotor kanandepan(3);
AF_DCMotor kananbelakang(4);
AF_DCMotor kiribelakang(1);
AF_DCMotor kiridepan(2);

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
     // attaches the servo on pin 10 to the servo object
}
void ON(){
kanandepan.setSpeed(500);
  kanandepan.run(RELEASE);

  kiridepan.setSpeed(500);
  kiridepan.run(RELEASE);

  kananbelakang.setSpeed(500);
  kananbelakang.run(RELEASE);

  kiribelakang.setSpeed(500); 
  kiribelakang.run(RELEASE);
}

void Grab() {
  Claw.attach(10);
  for (pos = 120; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    Claw.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  
  for (pos = 180; pos >= 120; pos -= 1) { // goes from 180 degrees to 0 degrees
    Claw.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  delay (1500);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  int sensorValue1 = analogRead(A1);
  int sensorValue2 = analogRead(A2);
  int sensorValue3 = analogRead(A3);
  int sensorValue4 = analogRead(A4);
  int sensorValue5 = analogRead(A5);
ON();
 
 if (sensorValue2 && sensorValue3 < 800){
   kananbelakang.run(FORWARD);
  kananbelakang.setSpeed(500);
  kanandepan.run(FORWARD);
  kanandepan.setSpeed(500);
  kiribelakang.run(FORWARD);
  kiribelakang.setSpeed(500);
  kiridepan.run(FORWARD);
  kiridepan.setSpeed(500);
 }
 if (sensorValue && sensorValue5 > 1000) {
  Grab();
  delay(10);        // delay in between reads for stability
 }
 }/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Graphical representation is available using serial plotter (Tools > Serial Plotter menu)
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.
*/
#include <AFMotor.h>
#include <Servo.h>
Servo Claw;
int pos=0;
AF_DCMotor kanandepan(3);
AF_DCMotor kananbelakang(4);
AF_DCMotor kiribelakang(1);
AF_DCMotor kiridepan(2);

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
     // attaches the servo on pin 10 to the servo object
}
void ON(){
kanandepan.setSpeed(500);
  kanandepan.run(RELEASE);

  kiridepan.setSpeed(500);
  kiridepan.run(RELEASE);

  kananbelakang.setSpeed(500);
  kananbelakang.run(RELEASE);

  kiribelakang.setSpeed(500); 
  kiribelakang.run(RELEASE);
}

void Grab() {
  Claw.attach(10);
  for (pos = 120; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    Claw.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  
  for (pos = 180; pos >= 120; pos -= 1) { // goes from 180 degrees to 0 degrees
    Claw.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  delay (1500);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  int sensorValue1 = analogRead(A1);
  int sensorValue2 = analogRead(A2);
  int sensorValue3 = analogRead(A3);
  int sensorValue4 = analogRead(A4);
  int sensorValue5 = analogRead(A5);
ON();
 
 if (sensorValue2 && sensorValue3 < 800){
   kananbelakang.run(FORWARD);
  kananbelakang.setSpeed(500);
  kanandepan.run(FORWARD);
  kanandepan.setSpeed(500);
  kiribelakang.run(FORWARD);
  kiribelakang.setSpeed(500);
  kiridepan.run(FORWARD);
  kiridepan.setSpeed(500);
 }
 if (sensorValue && sensorValue5 > 1000) {
  Grab();
  delay(10);        // delay in between reads for stability
 }
 }
