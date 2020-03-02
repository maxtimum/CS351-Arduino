#include <LiquidCrystal.h>
int incP1 = 7;
int incP2 = 6;
//pin 6 & 7

int P1Score = 0;
int P2Score = 0;
int totalScore = 0;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("P1     ||     P2");
lcd.setCursor(0,1);
  lcd.print("0      ||     0");
  pinMode(incP1,INPUT);
}

void loop() {
  int  = digitalRead(incP1);
}
