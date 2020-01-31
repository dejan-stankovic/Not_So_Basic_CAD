#include <Servo.h> // include the Servo Library
const int trigPin = 11; // Where I plug my Ultrasonic Sensors TrigPin
const int echoPin = 12; // Where I plug my Ultrasonic Sensors EchoPin
long duration; // 
int cm; // Lets me use cm as a variable
Servo myServoFR; // Setting up Servos
Servo myServoFL;
Servo myServoBR;
Servo myServoBL;

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
	
	if (cm > 15) // if the distance is greater than 15 cm
{
	myServoFR.write(180); // go forward
	myServoBR.write(180);
	myServoBL.write(180);
	myServoFL.write(180);

}
	else { // if NOT greater than 35 cm
		myServoFR.write(0); // Rotates the car
		myServoBL.write(180);
		myServoBR.write(0);
		myServoFL.write(180);
	}

}

int sensor() // Sensor code so that it checks the distance
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
	distance = (duration/2) * 0.034/2; // A lot of Fancy Math
	return distance;

}

