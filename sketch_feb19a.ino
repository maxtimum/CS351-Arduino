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
int swapCounter = 0;
boolean ServeSwap = false;
int ServeCounter = 1;
boolean SideSwap = false;
//has someone won the game yet
boolean win = false;
int P1Set = 0;
int P2Set = 0;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("P1  S:0||0:S  P2");
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
  //if players are on their original starting postions
  if(SideSwap == false){
    button1 = digitalRead(incP1);
    button2 = digitalRead(decP1);
    button3 = digitalRead(incP2);
    button4 = digitalRead(decP2);
  }

  //if players are swapped from their original starting positions
  if(SideSwap == true){
    button1 = digitalRead(incP2); // originally button 3
    button2 = digitalRead(decP2); // originally button 4
    button3 = digitalRead(incP1); // originally button 1
    button4 = digitalRead(decP1); //originally button 2
  }
  
  //reset Serve Counter when new set begins or when score is 10-10 or greater
  if(totalScore == 20 || totalScore == 0){
    ServeCounter = 1;
  }

  
  if(win == false){
    if(ServeSwap == false){
      delay(200);
      digitalWrite(ledP1, HIGH);
      digitalWrite(ledP2, LOW);
    } else if(ServeSwap == true){
      delay(200);
      digitalWrite(ledP2, HIGH);
      digitalWrite(ledP1, LOW);
    }
  }
  
  if(button1 == HIGH){
    P1Score++;
    ServeCounter++;
    delay(200);
    if (SideSwap == false){
    lcd.setCursor(0,1);
    lcd.print(P1Score);
    } else {
      lcd.setCursor(14,1);
      lcd.print(P1Score);
    }
  }

    if(button3 == HIGH){
    P2Score++;
    ServeCounter++;
    delay(200);
    if (SideSwap == false){
    lcd.setCursor(14,1);
    lcd.print(P2Score);
    } else {
      lcd.setCursor(0,1);
      lcd.print(P2Score);
    }
  }

    if(button2 == HIGH){
      if(P1Score > 0){
        P1Score--;
        ServeCounter--;
      }
      delay(200);
      if (SideSwap == false){
      lcd.setCursor(0,1);
      lcd.print(P1Score);
      } else {
        lcd.setCursor(14,1);
        lcd.print(P1Score);
      }
    }

    if(button4 == HIGH){
      if(P2Score > 0){
        P2Score--;
        ServeCounter--;
      }
      delay(200);
      if (SideSwap == false){
      lcd.setCursor(14,1);
      lcd.print(P2Score);
      } else {
        lcd.setCursor(0,1);
        lcd.print(P2Score);
      }
    }

  totalScore = P1Score + P2Score;

    if(P1Score >= 11 && (P1Score - P2Score) >= 2){
      P1Set++;
      P1Score = 0;
      P2Score = 0;
      totalScore = 0;
      if(SideSwap == false){
        SideSwap = true; 
        lcd.setCursor(0,0);
        lcd.print("P2");
        lcd.setCursor(14,0);
        lcd.print("P1");
        lcd.setCursor(6,0);
        lcd.print(P2Set);
        lcd.setCursor(9,0);
        lcd.print(P1Set);
      } else if (SideSwap == true){
        SideSwap = false;
         lcd.setCursor(0,0);
        lcd.print("P1");
        lcd.setCursor(14,0);
        lcd.print("P2");
        lcd.setCursor(6,0);
        lcd.print(P1Set);
        lcd.setCursor(9,0);
        lcd.print(P2Set);
      }
      lcd.setCursor(0,1);
      lcd.print("0      ||     0 ");
      /*
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("PLAYER 1 WINS");
      delay(500);
      digitalWrite(ledP1,HIGH);
      delay(500);
      digitalWrite(ledP1,LOW);
      */
  } else if(P2Score >=11 && (P2Score - P1Score) >= 2){
    P2Set++;
    P1Score = 0;
    P2Score = 0;
    totalScore = 0;
    if(SideSwap == false){
        SideSwap = true;
        lcd.setCursor(0,0);
        lcd.print("P2");
        lcd.setCursor(14,0);
        lcd.print("P1");
        lcd.setCursor(6,0);
        lcd.print(P2Set);
        lcd.setCursor(9,0);
        lcd.print(P1Set); 
      } else if (SideSwap == true){
        SideSwap = false;
         lcd.setCursor(0,0);
        lcd.print("P1");
        lcd.setCursor(14,0);
        lcd.print("P2");
        lcd.setCursor(6,0);
        lcd.print(P1Set);
        lcd.setCursor(9,0);
        lcd.print(P2Set);
      }
    
    lcd.setCursor(0,1);
    lcd.print("0      ||     0 ");
    
    /*
            lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("PLAYER 2 WINS");
      delay(500);
      digitalWrite(ledP2,HIGH);
      delay(500);
      digitalWrite(ledP2,LOW);
      */
  }

  //when P1 wins
  if(P1Set == 3){
      win = true;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("PLAYER 1 WINS!!!");
      if(SideSwap == true){
        digitalWrite(ledP2,LOW); 
        delay(500);
        digitalWrite(ledP1,HIGH);
        delay(500);
        digitalWrite(ledP1,LOW);
      } else if (SideSwap == false){
        digitalWrite(ledP1, LOW);
        delay(500);
        digitalWrite(ledP2,HIGH);
        delay(500);
        digitalWrite(ledP2,LOW);
      }
  }else if (P2Set == 3){
      win = true;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("PLAYER 2 WINS!!!");
      if(SideSwap == true){
        digitalWrite(ledP1, LOW);
        delay(500);
        digitalWrite(ledP2,HIGH);
        delay(500);
        digitalWrite(ledP2,LOW);
      } else if (SideSwap == false){
        digitalWrite(ledP2,LOW); 
        delay(500);
        digitalWrite(ledP1,HIGH);
        delay(500);
        digitalWrite(ledP1,LOW);
      }
  }
  //server & receiver position change upon decrement of score changes go below
  
  //if score is not 10-10
  if(totalScore < 20){
    if(ServeCounter == 3 && ServeSwap == false){
      ServeSwap = true;
    } else if(ServeCounter == 5 && ServeSwap == true){
      ServeSwap = false;
      ServeCounter = 1;
    }
    //if score is 10-10 or greater and someone hasn't won yet
  } else if (totalScore >= 20){
    if(ServeCounter == 2 && ServeSwap == true){
      ServeSwap = false;
      ServeCounter = 1;
    } else if (ServeCounter == 2 && ServeSwap == false){
      ServeSwap = true;
      ServeCounter = 1;
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
