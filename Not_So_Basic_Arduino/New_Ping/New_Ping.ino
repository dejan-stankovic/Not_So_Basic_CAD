#include <NewPing.h>
#define TRIGGER_PIN 12
#define ECHO_PIN 11
#define MAX_DISTANCE 200
NewPing myHCSR04(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
int ledPin = 9;
int dash;
int x;
// Used this as a variable
#include <Servo.h>
// Pins are different with ultrasound. They are changed to constant integers, as opposed to normal integers.
const int trigPin = 11;
const int echoPin = 12;
long duration;
int cm; 
// Defines cm as the measure of distance
Servo myServo;
int servoPin = 10;
int sensor();

void setup()
{
	Serial.begin(9600);
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
	myServo.attach(servoPin);
}

void loop()
{
	Serial.println(myHCSR04.ping_cm());
	delay(50);
	cm = sensor();
	if (cm < 5)
	{
		LEDBlinkRevisited();
		moveServoFast();
	}
	else
		if (cm > 10)
		{
			LEDOff();
			moveServo();
		}
	else
	{
		stopServo();
	}
}

void LEDBlinkRevisited()
{
	for (int fadeValue = 0; fadeValue <= 255; fadeValue += 5)
	{
		analogWrite(ledPin, fadeValue);
		for (dash = 0; dash < fadeValue/10; dash++)
		{
			Serial.print("-");
		}
		Serial.println("");
		delay(30);
	}
	for (int fadeValue = 255; fadeValue >= 0; fadeValue -= 5)
	{
		analogWrite(ledPin, fadeValue);
		for (dash = 0; dash < fadeValue/10; dash++)
		{
			Serial.print("-");
		}
		Serial.println("");
	}
}

void LEDOff()
{
	digitalWrite(9, LOW);
}
int sensor(){
	int distance = 0;
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	delay(2);
	digitalWrite(trigPin, LOW);
	// Goes from HIGH (on) to LOW (off) with a delay of 2 milliseconds
	duration = pulseIn(echoPin);
	distance = (duration/2) * 0.034/2;
	// Does some fancy math so you don't have to.
	Serial.print(distance);
	Serial.println("cm");
	// Tells the serial monitor to print the amount of centimeteres the object is away from it.
	delay(50);
	return distance;
}

void moveServo(){
	myServo.write(130);
	// Gets the servo to move when the distance is 10 cm or greater
	// Turns off LED
}

void moveServoFast(){
	myServo.write(180); 
	// The servo moves even faster if the distance is 5 cm or less
}

void stopServo(){
	myServo.write(90);
	// Stops the servo when the distance is between 5 and 10 cm 
}
 