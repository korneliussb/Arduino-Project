#define BLYNK_PRINT Serial
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

#include <SoftwareSerial.h>
SoftwareSerial EspSerial(2, 3); // RX, TX

ESP8266 wifi(&EspSerial);

// Auth Token dari Blynk
char auth[] = "c478d5b00d8941e48272e8ee31efdba1";

#define Mas1 8
#define Mas2 9
#define Mas3 10
#define Mas4 11

void Maju()
{
  digitalWrite(Mas1,HIGH);
  digitalWrite(Mas2,LOW);
  digitalWrite(Mas3,HIGH);
  digitalWrite(Mas4,LOW);
}

void Mundur()
{
  digitalWrite(Mas1,LOW);
  digitalWrite(Mas2,HIGH);
  digitalWrite(Mas3,LOW);
  digitalWrite(Mas4,HIGH);
}

void Kanan()
{
  digitalWrite(Mas1,HIGH);
  digitalWrite(Mas2,LOW);
  digitalWrite(Mas3,LOW);
  digitalWrite(Mas4,LOW);
}

void Kiri()
{
  digitalWrite(Mas1,LOW);
  digitalWrite(Mas2,LOW);
  digitalWrite(Mas3,HIGH);
  digitalWrite(Mas4,LOW);
}

void Berhenti()
{
  digitalWrite(Mas1,LOW);
  digitalWrite(Mas2,LOW);
  digitalWrite(Mas3,LOW);
  digitalWrite(Mas4,LOW);
}

void setup()
{
  // Atur Baudrate
  Serial.begin(9600);
  delay(10);
  // Atur Baudrate ESP
  EspSerial.begin(9600);
  delay(10);

  Blynk.begin(auth, wifi, "4G to 5G", "deknight97");  // wifi username and password, pin out 8266, TX ke pin 2 arduino, VCC, GND, GP_IO1 ke, selain reset,RX ke pin 3 ard, TX ke pin 2 ard, CHPD dan VCC ke 3.3 board pin merah breadboard
  pinMode(Mas1, OUTPUT);
  pinMode(Mas2, OUTPUT);
  pinMode(Mas3, OUTPUT);
  pinMode(Mas4, OUTPUT);
}

BLYNK_WRITE(V1) 
{
  int x = param[0].asInt();
  int y = param[1].asInt();
  
  /*  Serial.print("X = ");
  Serial.print(x);
  Serial.print("; Y = ");
  Serial.println(y); */
  if(y>220)
  Maju();
  else if(y<35)
  Mundur();
  else if(x>220)
  Kanan();
  else if(x<35)
  Kiri();
  else
  Berhenti();
}

void loop()
{
  Blynk.run();
}
