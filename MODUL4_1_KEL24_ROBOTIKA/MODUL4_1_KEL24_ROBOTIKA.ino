//#include <tcrt5k.h>
#define E1 9
#define O1 3
#define O2 4
#define IRa A0
#define IRd 8
void setup() {
 pinMode(E1, OUTPUT);
 pinMode(O1, OUTPUT);
 pinMode(O2, OUTPUT);
 pinMode(IRa, INPUT);
 pinMode(IRd, INPUT);
 Serial.begin(9600);
}
void loop() {
  delayMicroseconds(500);
  int b = analogRead(A0);
  int c = digitalRead(8);
  Serial.print("IRa: ");
  Serial.println(b);
  Serial.print("IRd: ");
  Serial.println(c);
  
  if (b <= 950){
    digitalWrite(E1, HIGH);
    digitalWrite(O1, LOW);
    digitalWrite(O2, HIGH);
  }
  else if (b >= 100){
    digitalWrite(E1, HIGH);
    digitalWrite(O1, HIGH);
    digitalWrite(O2, LOW);
  }
//else if (IRd == 1){
// digitalWrite(E1, HIGH);
// digitalWrite(O1, HIGH);
// digitalWrite(O2, LOW);
//}
//if (IRd == 0){
// digitalWrite(E1, HIGH);
// digitalWrite(O1, HIGH);
// digitalWrite(O2, LOW);
//}
  else{
    digitalWrite(E1, LOW);
    digitalWrite(O1, LOW);
    digitalWrite(O2, LOW);
  }
}
