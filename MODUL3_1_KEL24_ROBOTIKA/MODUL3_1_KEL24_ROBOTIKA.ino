int enM = 9; //inisialisasi port pada Arduino, enable port 9 
int m1 = 3; //inisialisasi port pada Arduino, input 1 
int m2 = 4; //inisialisasi port pada Arduino, input 2
 
void setup(){  
  pinMode(enM,OUTPUT); //pin enable sebagai output 
  pinMode(m1,OUTPUT); //pin m1 sebagai output 
  pinMode(m2,OUTPUT); //pin m2 sebagai output 
  digitalWrite(enM,HIGH); //mengaktifkan pin enable 
} 
 
//motor akan berputar berlawanan arah jarum jam 
void loop(){  
  digitalWrite(m1,LOW);  
  digitalWrite(m2,HIGH); 
  delay(2000);

}
