# Intermediate Arduino 

## LED_Blink_Revisited

### Description 

In LED Blink Revisited we made a LED fade in and out instead of just turning on and off.  We had to learn to use Analog Write instead of Digital Write to get the LED to fade.  We also had to have a serial monitor correspond with the LED.  

### Wiring
![wiring diagram](http://wiki.chssigma.com/images/e/e8/Fritzing_LED_fade.PNG)
Credit: Imogen A. [CHS Sigma Wiki](http://wiki.chssigma.com/index.php?title=Imogen%27s_Engineering_2_Notebook#Wiring_.26_Pictures)

### Lessons Learned

The biggest struggle completing this assignment was not remembering anything from last year.  After looking at some of my old code and the CHS Wiki page I was able to complete the assignment. 

* How to Use Analog Write* https://www.arduino.cc/reference/en/language/functions/analog-io/analogwrite/and 
* For Loops** https://www.arduino.cc/reference/en/language/structure/control-structure/for/

## Hello LCD***

### Description 

In Hello LCD we learned how to use a LCD Screen. We had to use an LCD Screen and an arduino to print "Hello World" and print the number of seconds the code was active.

### Wiring
![wiring diagram](http://wiki.chssigma.com/images/e/e0/Lcdcap1.PNG)
Credit: Paul B. [CHS Sigma Wiki](http://wiki.chssigma.com/index.php?title=Paul%27s_Engineering_2_Notebook#Wiring_and_Pictures)

### Lessons Learned

I spent so much time cutting 16 even wires to connect the LCD to the breadbord.  Please never overcomplicate things when you could just do a much simpiler task.  

* The Basics of the LCD Screen* https://en.wikipedia.org/wiki/Liquid-crystal_display
* The Liquid Crystal Library** https://www.arduino.cc/en/Reference/LiquidCrystal

### Notes 

* THIS CODE IS DONE BY THE MAGNIFICENT HARRIET NOVAK (follow her at hnovak 94 https://github.com/hnovak94)

## LCD_Backpack 

### Description 

In LCD Backpack we had the LCD Print the number of times the button was pushed. Another extra task was to have a switch pressed to reset the code back to zero (In wiring diagram not my code).  In this assignment we learned how to code wth a button, and add in the LCD backpack and the libraries that entail.
 
### Wiring
![wiring diagram](http://wiki.chssigma.com/images/5/5d/Capswitch%601.PNG)
Credit: Paul B. [CHS Sigma Wiki](http://wiki.chssigma.com/index.php?title=Paul%27s_Engineering_2_Notebook#Wiring_and_Pictures)

### Lessons Learned 

I had trouble with my button and the fact that it continued to go up in number until I pressed it again. To fix this I used this line of code (if(buttonState == HIGH && previousbuttonState == LOW)) to make sure it didn't continuously increase.
* How to use the LCD Backpack* Instead of connecting all 16 pins https://www.adafruit.com/product/292
* How to use If Loops** https://www.arduino.cc/reference/en/language/structure/control-structure/if/
