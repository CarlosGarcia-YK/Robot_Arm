#include <Servo.h> 
#include <SoftwareSerial.h>
Servo servo0;
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;//Declarando Servos
int servo0pos,servo1pos,servo2pos,servo3pos,servo4pos,x,t;//variables
int angle;
char letra ;
String inString = "";


SoftwareSerial BT(10,11);
String cadena=""; //Creamos un array de caracteres de 256 cposiciones
int i=0; //Tamaño actual del array

void setup ()
{
 Serial.begin(9600);
 BT.begin(9600);
 
  servo0.attach(2);
  servo1.attach(3); //Pines declarables
  servo2.attach(4);
  servo3.attach(5);
  servo4.attach(6);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  servo0.write(45);
}
void loop(){
  
  while(BT.available()>0){
   char dato=BT.read();
   cadena+=dato;
   
    if (isDigit(dato)) {
      // convert the incoming byte to a char and add it to the string:
      inString += dato;
      Serial.println(inString);
      
    
    }else if(dato!='\n' && isDigit(dato)==0 && int(dato)!=13){
      angle=inString.toInt();
        letra = (char) dato ;
      Serial.println(angle);
      Serial.println(letra);
    }else{
    if(letra=='M'){
      if(angle>=0){digitalWrite(8,HIGH);
      servo0.write(angle);
      digitalWrite(7,HIGH);
      digitalWrite(8,LOW);}
      else{ digitalWrite(8,LOW);
      servo0.write(angle);}
      }
    if(letra=='N'){
      servo1.write(angle);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);}
    if(letra=='O'){
      if(angle>=0){digitalWrite(8,HIGH);
      digitalWrite(7,LOW);
      digitalWrite(8,HIGH);}}
      servo2.write(angle);
    if(letra=='P'){
      
      servo3.write(angle);
      }
    if(letra=='Q'){
      }
      inString = "" ;
   
   }
 }
}
