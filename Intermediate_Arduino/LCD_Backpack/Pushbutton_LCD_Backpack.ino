#include <Wire.h>
#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display.  
// If 0x27 doesn't work, try 0x3F.
int buttonPin = 12; 
int buttonState = 0; 
int counter = 0; 
int previousbuttonState = 0; 

void setup() {
lcd.init();
lcd.backlight();
lcd.print("Button Presses");
Serial.begin(9600);

}



void loop() {
buttonState = digitalRead(buttonPin);
lcd.setCursor(0, 1);

if(buttonState == HIGH && previousbuttonState == LOW){

	counter +=1;
	lcd.print(counter);
}
previousbuttonState = buttonState;

Serial.print("");
Serial.println(counter);

}