#include <SoftwareSerial.h>
#include <MQ2.h>

SoftwareSerial sim800(3, 2);

int buzzerPin = 9;
int flamePin = 5;
float smokeThreshold = 1.5;

int mq2Pin = A1;
MQ2 mq2(mq2Pin);
float smoke;
bool hasfire, hassmoke;

void setup() {
  Serial.begin(9600);  //begin serial com with arduino ide
  sim800.begin(9600);  //begin serial com with arduino and sim80l
  Serial.println("Initializing... ");
  delay(1000);

  sim800.println("AT");  //test if the sim800l is responding
  updateSerial();
  sim800.println("AT+CMGF=1");  //setting sms mode to text
  updateSerial();

  pinMode(buzzerPin, OUTPUT);
  pinMode(flamePin, INPUT);

  hasfire = false;
  hassmoke = false;

  mq2.begin();  //initializing mq2 sensor
}

void loop() {
  //read value from the sensors
  int flameValue = digitalRead(flamePin);
  smoke = mq2.readSmoke();

  //print the smoke reading to the serial monitor
  Serial.print("Smoke reading:");
  Serial.print(smoke, 2);  //print 2 decimals
  Serial.println(" ppm");

  if (flameValue == LOW) {
    digitalWrite(buzzerPin, HIGH);
    hasfire = true;
    sendSMS("Fire detected!");
  }  //end of flamevalue if

  else if (smoke > smokeThreshold) {
    digitalWrite(buzzerPin, HIGH);
    hassmoke = true;
    sendSMS("Smoke detected!");
  }  //end of smoke else if

  else {
    digitalWrite(buzzerPin, LOW);
    hasfire = false;
    hassmoke = false;
  }  //end of else buzzer off

  if (hassmoke || hasfire) {
    delay(10000);
  }  //end of hassmoke or hassfire

  else { delay(2500); }  //end of else
}


void sendSMS(String message) {
  sim800.println("AT+CMGS=\"+639215740858\"");  //command send sms to number
  updateSerial();
  sim800.print(message);  //message content
  updateSerial();
  sim800.write(26);  //end sms command with ctrl z
  updateSerial();
}  //end of void sendsms


void updateSerial() {
  delay(500);
  while (Serial.available()) {
    sim800.write(Serial.read());
  }  //end of while serial available

  while (sim800.available()) {
    Serial.write(sim800.read());
  }  //end of while sim800 available

}  //end of update serial
