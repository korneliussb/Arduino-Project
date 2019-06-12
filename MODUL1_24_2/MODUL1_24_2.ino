int button = 2;
int nilaibutton;
int count;

int led=4;

void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  nilaibutton = digitalRead(button);

  if(nilaibutton == 1){
  count++;
  delay(300);
  digitalWrite(led, HIGH);
  }
  if(count==2){
  digitalWrite(led, LOW);
  count=0;
  }
}
