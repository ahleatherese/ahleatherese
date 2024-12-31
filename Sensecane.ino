int WATERSENSOR = A0;   // Water level sensor connected to analog pin A0
int TRIGPIN = 6;        // Ultrasonic sensor TRIG pin
int ECHOPIN = 5;       // Ultrasonic sensor ECHO pin
int BUZZER = 12;        // Buzzer connected to digital pin 11
int VIBRATIONMOTOR = 11; // Vibration motor connected to digital pin 12

long duration;
int distance;
int vibrationDuration = 5000;  // Vibration motor active time (5 seconds)

void setup() {
  pinMode(WATERSENSOR, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(VIBRATIONMOTOR, OUTPUT);

  Serial.begin(9600);  // Initialize serial communication for debugging
}

void loop() {

  // Water detection
  int waterLevel = analogRead(WATERSENSOR);
  Serial.print("Water Level: "); 
  Serial.println(waterLevel); // Display water level in Serial Monitor
  
  if (waterLevel > 40) {
    // Turn on the vibration motor when water is detected
    digitalWrite(VIBRATIONMOTOR, HIGH);
    delay(vibrationDuration); // Keep the vibration motor on for 5 seconds
    digitalWrite(VIBRATIONMOTOR, LOW);  // Turn off vibration motor after 5 seconds
  }
  

  // Ultrasonic sensor
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);
  
  duration = pulseIn(ECHOPIN, HIGH);
  distance = duration * 0.034 / 2;  // Calculate the distance in cm

  if (distance <= 60) {  // Check if an object is close (within 30 cm)
    digitalWrite(BUZZER, HIGH);
    delay(10);
    digitalWrite(BUZZER, LOW);
  } else {
    digitalWrite(BUZZER, LOW);  // Turn off buzzer if object is far away
  }

  // Display distance in Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(200); // Small delay to allow for sensor readings
}

