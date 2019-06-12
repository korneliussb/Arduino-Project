#define PIR_PIN 2

void setup() {
  // put your setup code here, to run once:
  
    Serial.begin(9600);
  
  pinMode(PIR_PIN, INPUT); // Atur pin 2 menjadi mode input
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  delay(100); // Jeda sebentar

}

void loop() {
  // put your main code here, to run repeatedly:
//  while (d)
  if(digitalRead(PIR_PIN) == HIGH){
    Serial.println("TERDETEKSI");
    digitalWrite(12, HIGH); //berlawanan jarum jam
    digitalWrite(13, LOW);
    delay(100);
  }else{
    Serial.println("NGGAK ADA!");
    digitalWrite(12, LOW); //berputar searah jarum jam
    digitalWrite(13, HIGH);
    delay(100);
  }
}
