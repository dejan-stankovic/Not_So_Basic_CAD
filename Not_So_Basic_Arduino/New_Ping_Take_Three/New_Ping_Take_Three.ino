#include <NewPing.h>
 
#define TRIGGER_PIN  11 
#define ECHO_PIN     12 
#define MAX_DISTANCE 200
 
int led = 7;
long duration, cm, inches;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
 
void setup() {
 
  Serial.begin(9600); //starts the serial monitor
  pinMode(led, OUTPUT);
 
}
 
void loop() {
 
  delay(200);
 cm = sonar.ping_cm();
  Serial.print(cm); 
  Serial.println(" cm");
 
  if (cm <=15){ 
    digitalWrite(led,HIGH);
 
  }
  else digitalWrite(led,LOW); 
 
}