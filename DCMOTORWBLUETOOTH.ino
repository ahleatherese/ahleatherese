const int relayForward = 2; 
const int relayReverse = 3; 

char receivedData;

void setup() {
  pinMode(relayForward, OUTPUT);
  pinMode(relayReverse, OUTPUT);

  digitalWrite(relayForward, LOW);
  digitalWrite(relayReverse, LOW);
  Serial.begin(9600); 
}

void loop() {
  if (Serial.available()) {
    receivedData = Serial.read(); 
    switch (receivedData) {
      case 'F': // Forward
        MForward();
        break;
      case 'R': // Reverse
        MReverse();
        break;
      case 'S': // Stop
        SMotor();
        break;
      default:
        break;
    }
  }
}

void MForward() {
  digitalWrite(relayForward, HIGH);
  digitalWrite(relayReverse, LOW);
}

void MReverse() {
  digitalWrite(relayForward, LOW);
  digitalWrite(relayReverse, HIGH);
}

void SMotor() {
  digitalWrite(relayForward, LOW);
  digitalWrite(relayReverse, LOW);
}