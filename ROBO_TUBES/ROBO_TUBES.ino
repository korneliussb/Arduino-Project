// #include <tcrt5k.h>

//#define BUZZ 7
#define O1 2
#define O2 3
#define IRa A0
#define IRd 8
#define IRb A1
#define IRe 9

void setup() {
  // put your setup code here, to run once:
  //pinMode(BUZZ, OUTPUT);
  pinMode(O1, OUTPUT);
  pinMode(O2, OUTPUT);
  pinMode(IRa, INPUT);
  pinMode(IRd, INPUT);
  pinMode(IRb, INPUT);
  pinMode(IRe, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  delayMicroseconds(500);
  int d = digitalRead(A0);
  int e = digitalRead(A1);

  Serial.print("IRa: ");
  Serial.println(d);
  Serial.print("IRd: ");
  Serial.println(e);
  
  if(d==0 && e==0){
   // digitalWrite(BUZZ,LOW );
    digitalWrite(O1, LOW);
    digitalWrite(O2, LOW);
    
//    tone(7, 1200);
    }
   if (d==1 || e==1){
    tone(7, 1200);
    //digitalWrite(BUZZ,HIGH );
    digitalWrite(O1,HIGH);
    digitalWrite(O2,HIGH);
    }
   if (d==1 && e==1){
    tone(7, 1200);
    //digitalWrite(BUZZ,HIGH );
    digitalWrite(O1,HIGH);
    digitalWrite(O2,HIGH);
    }

}
