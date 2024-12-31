  #include <Wire.h>
  #include <hd44780.h>                       
  #include <hd44780ioClass/hd44780_I2Cexp.h>
  hd44780_I2Cexp lcd; 

  const int trigPin = 3; 
  const int echoPin = 2; 
  int duration;
  int distance;
  const int DGREEN = 12;
  const int DYELLOW = 6;
  const int DRED = 3;
  int RED = 9;
  int YELLOW = 11;
  int GREEN = 10;

  void setup() {
    pinMode(RED, OUTPUT);  pinMode(REDTWO, OUTPUT);
    pinMode(GREEN, OUTPUT);   pinMode(GREENTWO, OUTPUT);
    pinMode(YELLOW, OUTPUT);
    pinMode(trigPin,OUTPUT); 
    pinMode(echoPin, INPUT); 
    lcd.begin(16, 2);
    lcd.print("Parking Distance: ");
    Serial.begin(9600);
    delay(100);
  }
  //A
  void loop() {
    digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH);
      distance = duration * 0.0344 / 2;
            //GREEN
          if (DGREEN>=distance )
          {
            digitalWrite(GREEN,HIGH);    
          }
            else
          {
            digitalWrite(GREEN,LOW);
          }
            //YELLOW
          if (DYELLOW>= distance)
          {
            digitalWrite(GREEN,LOW);
            digitalWrite(YELLOW,HIGH);
          }
            else
          {
            digitalWrite(YELLOW,LOW);
          }
            //RED
          if (DRED>= distance)
          {
            digitalWrite(RED,HIGH);
            digitalWrite(YELLOW,LOW);
            delay(2000);
          }
          else
          {
            digitalWrite(RED,LOW);
          }

    delay(100);
    lcd.clear();
    lcd.print("Parking Distance: ");
    lcd.setCursor(0,1);
    lcd.print(String(distance) + " cm");
    delay(100);

  
    Serial.println(distance);
  }
