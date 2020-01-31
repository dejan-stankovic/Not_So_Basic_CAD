#include <NewPing.h>
 
#define TRIGGER_PIN 12
#define ECHO_PIN 11
#define MAX_DISTANCE 200

#include <servo.h>
long duration; 
int distance;
 
NewPing myHC-SR04(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
 
void setup() {
 Serial.begin(9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
}
 
void loop() {
     Serial.println(myHC-SR04.ping_cm());
     delay(50); 
digitalWrite (trigPin, LOW);
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIN(echoPin, HIGH);
distance = duration*0.034/2; 

Serial.print("distance");
Serial.println(distance);
}
