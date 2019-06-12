#define PIR_PIN 2

void setup() {
  // put your setup code here, to run once:
  
    Serial.begin(9600);
  pinMode(PIR_PIN, INPUT); // Atur pin 2 menjadi mode input
  delay(100); // Jeda sebentar

}

void loop() {
  // put your main code here, to run repeatedly:
//  while (d)
  if(digitalRead(PIR_PIN) == HIGH){
    Serial.println("TERDETEKSI");
    delay(100);
  }else{
    Serial.println("NGGAK ADA!");
    delay(100);
  }
}
