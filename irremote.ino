#include <IRremote.hpp>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

const int IR_RECEIVE_PIN = 7;
const int servoPin = 8;
const int ledPin = 9;

Servo myservo;
LiquidCrystal_I2C lcd(0x27, 16, 2);

int angle = 0;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  myservo.attach(servoPin);
  pinMode(ledPin, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.print("Door Closed");
  lcd.setCursor(0, 1);
  lcd.print("Angle: 0");
  myservo.write(angle);
}

void loop() {
  if (IrReceiver.decode()) {
    unsigned long receivedCode = IrReceiver.decodedIRData.decodedRawData;
    Serial.println(receivedCode, HEX);

    if (receivedCode == 0xF30CFF00) {
      myservo.write(90); // Open door
      lcd.clear();
      lcd.print("Door Opened");
      lcd.setCursor(0, 1);
      lcd.print("Angle: 90");
      digitalWrite(ledPin, HIGH);
    } else if (receivedCode == 0xE916FF00) {
      myservo.write(0); // Close door
      lcd.clear();
      lcd.print("Door Closed");
      lcd.setCursor(0, 1);
      lcd.print("Angle: 0");
      digitalWrite(ledPin, LOW);
    }

    IrReceiver.resume();
  }
}
