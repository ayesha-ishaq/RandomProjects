#include <SoftwareSerial.h>

int push=9;
char state=0;

void setup() {
  pinMode(push,INPUT);  
  Serial.begin(9600);

 }

void loop() {
  
  if (Serial.available()>0)                                                             
  {
    if(digitalRead(push))
    {
        state='1'; 
        Serial.write(state);
        delay(2500);
        
    }
    else
    {
      state='0';
      Serial.write(state);
    }
    state='0';
  }

}
