/*
Adafruit Arduino - Lesson 14. Sweep
*/

#include <Servo.h> 

int servoPin = 9;
 
Servo servo;  
 
int angle = 0;   // servo position in degrees 
 
void setup() 
{ 
  servo.attach(10); 
} 
 
 
void loop() 
{ 
  // scan from 0 to 180 degrees
  for(angle = 180; angle > 90; angle--)  
  {       
    delay(150);                           
    servo.write(angle);               
    delay(15);                
  } 
  delay (1000);
  // now scan back from 180 to 0 degrees
  for(angle = 90; angle < 180; angle++)    
  {                                
    servo.write(angle);           
    delay(15);  
    servo.write (90);
    delay(15);     
  } 
} 
//servipon10
//untuk servo capit
