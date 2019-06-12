int enM = 9; //inisialisasi port pada Arduino 
int m1 = 3; //inisialisasi port pada Arduino 
int m2 = 4; //inisialisasi port pada Arduino 
int getIn; //membuat variabel getIn 
 
void setup(){  
  pinMode(enM,OUTPUT); //pin enable sebagai output 
  pinMode(m1,OUTPUT); //pin m1 sebagai output 
  pinMode(m2,OUTPUT); //pin m2 sebagai output 
  Serial.begin(9600); //mengatur baudrate sebesar 9600 
  digitalWrite(enM,HIGH); //mengaktifkan pin enable 
} 

void loop(){ 
  getIn = Serial.read(); //variabel getIn membaca nilai input 
  //jika ditekan huruf 'f' maka motor akan berputar 
  if (getIn == 'f'){
    analogWrite(enM,255);   
    digitalWrite(m1,HIGH);  
    digitalWrite(m2,LOW); 
  } 
  //jika ditekan huruf 's' maka motor akan berhenti 
  if (getIn == 's'){ 
    analogWrite(enM,0);  
    digitalWrite(m1,LOW); 
    digitalWrite(m2,LOW);
  }
}
