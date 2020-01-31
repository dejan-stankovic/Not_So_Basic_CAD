int ledPin = 9;    // LED connected to digital pin 9
int dash;
int x;
void setup() {
	Serial.begin(9600);
}

void loop() {
  // fade in from min to max in increments of 5 points:
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fadeValue);
    for(dash=0; dash< fadeValue/10; dash++){
    	Serial.print("-");
    }
    Serial.println("");
    delay(30);
}

  // fade out from max to min in increments of 5 points:
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fadeValue);
    for(dash=0; dash< fadeValue/10; dash++){
		Serial.print("-");
	}
	Serial.println("");
	delay(30);

}
}	




