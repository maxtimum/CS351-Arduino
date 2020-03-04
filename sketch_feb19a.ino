#include <LiquidCrystal.h>
int incP1 = 10;
int incP2 = 8;
int decP1 = 6;
int decP2 = 9;
int ledP1 = 1;
int ledP2 = 13;
int button1 = 0;
int button2 = 0;
int button3 = 0;
int button4 = 0;
//pin 6 & 7

int P1Score = 0;
int P2Score = 0;
int totalScore = 0;
//whose turn is it: 0 for P1, 1 for P2
int swapCounter = 0;
int P1ServeCounter = 0;
int P2ServeCounter = 2;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("P1     ||     P2");
lcd.setCursor(0,1);
  lcd.print("0      ||     0");
  pinMode(incP1,INPUT);
  pinMode(incP2,INPUT);
  pinMode(decP1,INPUT);
  pinMode(decP2,INPUT);
  pinMode(ledP1,OUTPUT);
  pinMode(ledP2,OUTPUT);
  //  pinMode(incP1,INPUT_PULLUP);
}

void loop() {
  button1 = digitalRead(incP1);
  button2 = digitalRead(decP1);
  button3 = digitalRead(incP2);
  button4 = digitalRead(decP2);
  
  if(P1ServeCounter == 0 && P1ServeCounter < 2 && swapCounter == 0){
    P1ServeCounter++;
    delay(200);
    lcd.setCursor(0,3);
    lcd.print("*");
  }
  
  if(P2ServeCounter == 0 P2ServeCounter < 2 && swapCounter == 1){
    P2ServeCounter++;
    delay(200);
    lcd.setCursor(0,14);
    lcd.print("*");
  }
  
  if(button1 == HIGH){
    P1Score++;
    delay(200);
    lcd.setCursor(1,1);
    lcd.print(P1Score);
  }

    if(button3 == HIGH){
    P2Score++;
    delay(200);
    lcd.setCursor(14,1);
    lcd.print(P2Score);
  }

    if(button2 == HIGH){
      if(P1Score > 0){
        P1Score--;
      }
    delay(200);
    lcd.setCursor(1,1);
    lcd.print(P1Score);
  }

    if(button4 == HIGH){
      if(P2Score > 0){
        P2Score--;
      }
    delay(200);
    lcd.setCursor(14,1);
    lcd.print(P2Score);

    }


        totalScore = P1Score + P2Score;

    if(P1Score >= 11 && (P1Score - P2Score) >= 2){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("PLAYER 1 WINS");
      delay(500);
      digitalWrite(ledP1,HIGH);
      delay(500);
      digitalWrite(ledP1,LOW);
  } else if(P2Score >=11 && (P2Score - P1Score) >= 2){
            lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("PLAYER 2 WINS");
      delay(500);
      digitalWrite(ledP2,HIGH);
      delay(500);
      digitalWrite(ledP2,LOW);
  }
  
  if(totalScore < 20){
    if(P1ServeCounter == 2){
      swapCounter = 1;
      P1ServeCounter == 0;
    } else if(P2ServeCounter == 2){
      swapCounter = 0;
      P2ServeCounter == 0;
    } 
  } else if (totalScore >= 20){
    if(P1ServeCounter == 1){
      swapCounter = 1;
      P1ServeCounter == 0;
    } else if (P2ServeCounter == 1){
      swapCounter = 0;
      P2ServeCounter == 0;
    }
  }
  
/*
  if (swapCounter == 1){
    // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("P2     ||     P1");
  lcd.setCursor(0,1);
  } else if(swapCounter == 0){
      lcd.begin(16, 2);
  // Print a message to the LCD.
    lcd.print("P1     ||     P2");
    lcd.setCursor(0,1);
  }
  */
}


