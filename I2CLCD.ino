#include <Wire.h>
#include <hd44780.h>                       
#include <hd44780ioClass/hd44780_I2Cexp.h>
hd44780_I2Cexp lcd; 

const int LCD_COLS = 16;
const int LCD_ROWS = 2;
int LEDOPEN = 2;
int LEDCLOSE = 3;

#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = {
  {'A', 'B', 'C', 'D'},
  {'E', 'F', 'G', 'H'},
  {'I', 'J', 'K', 'L'},
  {'M', 'N', 'O', '0'}
};
byte rowPins[ROWS] = {7, 6, 5, 4};
byte colPins[COLS] = {8, 9, 10, 11};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

String password = "ABCD"; 
String inputPassword = "";

void setup() {
  pinMode(LEDOPEN, OUTPUT);
  pinMode(LEDCLOSE, OUTPUT);
  lcd.begin(LCD_COLS, LCD_ROWS);
  lcd.print("Door is Closed");
}

void loop() {
  char customKey = customKeypad.getKey();
  
  if (customKey) {
    if (customKey == '0') {
      if (inputPassword == password) {
        lcd.clear();
        lcd.print("Door is Open!");
        digitalWrite(LEDOPEN, HIGH);
        delay(5000);
        digitalWrite(LEDOPEN, LOW);
        lcd.clear();
        lcd.print("Door is Closed!");
      } else {
        lcd.clear();
        lcd.print("Wrong Password");
        digitalWrite(LEDCLOSE, HIGH);
        delay(1000);
        digitalWrite(LEDCLOSE, LOW);
        lcd.clear();
        lcd.print("Door is Closed!");
      }
      inputPassword = "";
    } else {
      inputPassword += customKey;
      lcd.setCursor(0, 1);
      lcd.print(inputPassword);
    }
  }
}
