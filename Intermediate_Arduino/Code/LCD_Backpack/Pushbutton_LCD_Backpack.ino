// LCD Backpack
// Dylan Stukenberg
// Incredibly Import line of Code (if(buttonState == HIGH && previousbuttonState == LOW))
// If Loops https://www.arduino.cc/reference/en/language/structure/control-structure/if/
// LCD Backpack https://www.adafruit.com/product/292
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display.
// If 0x27 doesn't work, try 0x3F.
int buttonPin = 12;
int buttonState = 0;
int counter = 0;
int previousbuttonState = 0;
void setup()
{
	lcd.init();
	lcd.backlight();
	lcd.print("Button Presses"); // Prints the word Button Presses
	Serial.begin(9600);
}

void loop()
{
	buttonState = digitalRead(buttonPin); // Reads if button is being pushed
	lcd.setCursor(0, 1); // Sets the cursor (Colum 1 Line 0)
	if (buttonState == HIGH && previousbuttonState == LOW)
	{
		// so it counts correctly
		counter += 1; // Counter Goes up by one
		lcd.print(counter); // Prints the Number of the counter onto the LCD
	}
	previousbuttonState = buttonState;
	Serial.print("");
	Serial.println(counter); // prints the number of the counter onto the Serial Monitor
}
