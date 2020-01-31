#include <Servo.h>
const int trigPin = 11;
const int echoPin = 12;
long duration;
int cm;
Servo myServoFR;
Servo myServoFL;
Servo myServoBR;
Servo myServoBL;

int servoFrontRight = 10;
int servoFrontLeft = 9;
int servoBackRight = 8;
int servoBackLeft = 7;


void setup()
{
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
	Serial.begin(9600);
	myServoFR.attach(servoFrontRight);
	myServoFL.attach(servoFrontLeft);
	myServoBR.attach(servoBackRight);
	myServoBL.attach(servoBackLeft);
}

void loop()
{
	cm = sensor();
	if (cm < 15)
	{
		TurnCarRight();
	}
	else
	{
		MoveCarForeward();
	}
}

int sensor()
{
	int distance = 0;
	digitalWrite(trigPin, LOW);
	delay(2);
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	// Goes from HIGH (on) to LOW (off) with a delay of 2 milliseconds
	duration = pulseIn(echoPin, HIGH);
	if (duration == 0)
	{
		digitalWrite(echoPin, LOW);
		delay(1);
		pinMode(echoPin, INPUT);
	}
	distance = (duration/2) * 0.034/2;
	Serial.print(cm);
	Serial.println("cm");
	delay(50);
	return distance;
}

void MoveCarForeward()
{
	myServoFR.write(180);
	myServoFL.write(180);
}

void TurnCarRight()
{
	myServoBR.write(180);
	myServoFL.write(180);
}
