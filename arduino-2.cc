// arduino 2

#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

char str[10] = "Full";
int pirPin = 10; 

// assume no motion detected
int pirState = LOW; 
int val = 0;
int counter = 3;
int currentState = 0;
int previousState = 0;

void setup() {
 Serial.begin(9600);
 // declare sensor as input
 pinMode(pirPin, INPUT); 
 lcd.begin(16, 2);
 lcd.print("MAX seats: " + String(counter));
 lcd.setCursor(0,1);
 lcd.print("Available: " + String(counter));
}

void loop(){
 // read PIR sensor input value
 val = digitalRead(pirPin); 
 if (val == HIGH) { 
  if (pirState == LOW) {
   currentState = 1;
   pirState = HIGH;
   delay(500);
  }
} else {
 if (pirState == HIGH) {
  currentState = 0;
  pirState = LOW;
 }
}
if(currentState != previousState){
 if(currentState == 1) {
   if (counter == 1) {
     lcd.clear();
     lcd.print("Full");
     Serial.write(str,5);
   } else {
      counter = counter - 1;
      lcd.setCursor(0,1);
      lcd.print("Available: ");
      lcd.print(counter);
      lcd.print("    ");
   }
  delay(1000);
  }
 }
   delay(1000);
}