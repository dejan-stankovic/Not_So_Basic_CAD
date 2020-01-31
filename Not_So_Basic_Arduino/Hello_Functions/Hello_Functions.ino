#include<Servo.h>
//Pins are different with ultrasound. They are changed to constant integers, as opposed to normal integers.
const int trigPin = 11;
const int echoPin = 12;
long duration;
int cm;
Servo myServo;
int servoPin = 10;
int servoPin = 9;
int servoPin = 6;
int servoPin = 5;

//This assignment gets a 180 degree servo to turn when the distance on the ultrasound sensor is shorter than 10 cm.
void setup() {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT); 
Serial.begin(9600);
myServo.attach(servoPin);
}

void loop() {
cm = sensor();

if(cm < 5){
	moveServoFast();
}
else if(cm < 10){
	moveServo();
}
else{
	stopServo();
//This gets the servo to move to understand that if the distance is less than 10, then it will start moving, and if it is greater then 10, it will stop.
	}
}
//int sensor is a function that makes code specifically for the sensor.
int sensor(){
	int distance = 0;
 
		digitalWrite(trigPin, LOW);
		delay(2);
		digitalWrite(trigPin, HIGH);
		delayMicroseconds(10);
		digitalWrite(trigPin, LOW);
//Goes from HIGH (on) to LOW (off) with a delay of 2 milliseconds
duration = pulseIn(echoPin, HIGH);
if (duration == 0) {
	digitalWrite(echoPin, LOW);
	delay(1);
	pinMode(echoPin, INPUT);
}
	distance = (duration/2) *0.034/2;
//Does some fancy math so you don't have to.
	Serial.print(cm);
	Serial.println("cm");
//Tells the serial monitor to print the amount of centimeteres the object is away from it.
	delay(50);
	return distance;
 
}
 
void moveServo(){
	myServo.write(130);
//Gets the servo to move when the distance is 9 cm or lower
}

void moveServoFast(){
	myServo.write(180);
}
void stopServo(){
	myServo.write(90);
//Stops the servo when the distance is 10 or greater
}