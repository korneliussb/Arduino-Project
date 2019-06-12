int enB = 10;
int in3 = 9;
int in4 = 8;
void setup()
{
  // set all the motor control pins to outputs
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}
void demoOne()
{
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 200);
  delay(2000);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 
  delay(2000);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
void demoTwo()
{
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 
  for (int i = 0; i < 256; i++)
  {
    analogWrite(enB, i);
    delay(20);
  } 
  for (int i = 255; i >= 0; --i)
  {
    analogWrite(enB, i);
    delay(20);
  } 
  // now turn off motors
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);  
}
void loop()
{
  demoOne();
  delay(10);
  demoTwo();
  delay(10);
}
