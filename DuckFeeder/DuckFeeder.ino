#include <SoftwareSerial.h>

int led =13;
char state=0;
int motor1= 9;
int motor2= 10;


void setup() {
  pinMode(led,OUTPUT);
  pinMode(motor1,OUTPUT);
  pinMode(motor2, OUTPUT);
  digitalWrite(led, LOW);
  Serial.begin(9600); 

}

void forward()
{
  digitalWrite(motor1,HIGH);
  digitalWrite(motor2,LOW);
  delay(1000);
}
void stopMotor()
{
  digitalWrite(motor1,LOW);
  digitalWrite(motor2,LOW); 
  delay(1000);
}

void loop() {

  if(Serial.available() > 0)
  {
  
    digitalWrite(led,HIGH);
    state = Serial.read();
    Serial.println(state);

   if(state == '1')
    {
        forward();
        stopMotor();
    }

   else if(state == '0')
    {

      stopMotor();

    }
    
    else
      
      stopMotor();

   }
  
   else 
   stopMotor();

   state = '0';
}
