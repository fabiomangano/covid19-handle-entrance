// Arduino 1

#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int val;
int tempPin = 1;
char str[10];

void setup() {
  Serial.begin(9600);
  // initialize lcd screen
  lcd.begin(16, 2);
}

void loop() { 
  // set the cursor to column 0, line 1
  lcd.setCursor(0, 0);
  
  // convert temp value to celsius
  val = analogRead(tempPin);
  float mv = ( val/1024.0)*5000; 
  float cel = mv/10;
  
  if(str[0] != 'F') {
    lcd.print("Temp: ");
    lcd.print(cel);
    lcd.print(" C  ");
    
     // if temp >= 37 throw an alert
  	if (cel < 37) {
     lcd.setCursor(0, 1);
   	 lcd.print("Ok           ");
  	} 
  
  	else {
     lcd.setCursor(0, 1);
     lcd.print("Covid Alert !");
  	}
  }
    
  Serial.readBytes(str,4);
  
  if(str[0] == 'F') {  
    lcd.clear();
    lcd.print(str);
    Serial.end();
  }
  
  delay(1000);
}
 