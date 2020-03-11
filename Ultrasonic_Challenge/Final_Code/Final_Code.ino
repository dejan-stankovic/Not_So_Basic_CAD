#include <Servo.h> // include the Servo Library
const int trigPin = 11; // Where I plug my Ultrasonic Sensors TrigPin
const int echoPin = 12; // Where I plug my Ultrasonic Sensors EchoPin
long duration; //
int cm; // Lets me use cm as a variable
Servo myServoFR; // Setting up Servos
Servo myServoFL;
Servo myServoBR;
Servo myServoBL;
int distance = 0;
int D1 = 0; // Variables for Mean Code
int D2 = 0;
int D3 = 0;
int D4 = 0;
int D5 = 0;
int D6 = 0;
int servoFrontRight = 10; // Servopins
int servoFrontLeft = 9;
int servoBackRight = 8;
int servoBackLeft = 7;
void setup()
{
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
	Serial.begin(9600); // Sets up COM 5 Serial Monitor
	myServoFR.attach(servoFrontRight); // Adding in Servos
	myServoFL.attach(servoFrontLeft);
	myServoBR.attach(servoBackRight);
	myServoBL.attach(servoBackLeft);
}

void loop()
{
	cm = sensor(); // The Sensor reads in cm
	Serial.print(cm); // Prints the CM
	Serial.println("cm");
	delay(50);
	if (D6 > 15)
	// if the distance is greater than 15 cm
	{
		myServoFR.write(0); // go forward
		myServoBR.write(0);
		myServoBL.write(180);
		myServoFL.write(180);
	}
	else
	{
		// if NOT greater than 15 cm
		myServoFR.write(180); // Rotates the car
		myServoBL.write(180);
		myServoBR.write(180);
		myServoFL.write(180);
	}
	D5 = D4; // Moves the previous D4 number to D5
	D4 = D3; // Moves the previous D3 number to D4
	D3 = D2; // Moves the previous D2 number to D3
	D2 = D1; // Moves the previous D1 number to D2
	D1 = distance; // Makes D1 Equal to the new distance
	D6 = (D1 + D2 + D3 + D4 + D5) / 5; // Math for a Mean, we now use the mean for the code
	Serial.print(D6);
	Serial.println("D6");
	delay(2);
}

int sensor()
{
	// Sensor code so that it checks the distance
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
	distance = (duration/2) * 0.034/2; // A lot of Fancy Math
	return distance;
}
