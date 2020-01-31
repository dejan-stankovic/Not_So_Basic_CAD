#include <Servo.h>
const int trigPin = 11;
const int echoPin = 12;
long duration;
int cm;
int servoBackRight = 8;
Servo myServoBR;
long randNumber;
boolean toggle = true;
void setup()
{
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
	Serial.begin(9600);
	myServoBR.attach(servoBackRight);
}

void loop()
{
	cm = sensor();
	Serial.print(cm);
	Serial.println("cm");
	delay(50);
	if (cm < 15 & toggle == true)
	{
		randNumber = random(91, 180);
		Serial.println(randNumber);
		myServoBR.write(randNumber);
		Serial.println("randNumber");
		toggle = !toggle;
		Serial.println("Toggle");
		delay(1000);
	}
	else if (cm < 15 & toggle == false)
	{
		randNumber = random(0, 89);
		Serial.println(randNumber);
		myServoBR.write(randNumber);
		Serial.println("randNumber");
		toggle = !toggle;
		Serial.println("Toggle");
		delay(1000);
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
	return distance;
}
