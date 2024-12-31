const int clawu = 2; 
const int clawd = 3; 
const int necku = 4; 
const int neckd = 5; 
const int armu = 6; 
const int armd = 7; 
const int bodyu = 8; 
const int bodyd = 9; 


char receivedData;

void setup() {
  pinMode(clawu, OUTPUT);
  pinMode(clawd, OUTPUT);
  pinMode(necku, OUTPUT);
  pinMode(neckd, OUTPUT);
  pinMode(armu, OUTPUT);
  pinMode(armd, OUTPUT);
  pinMode(bodyu, OUTPUT);
  pinMode(bodyd, OUTPUT);


  pinMode(clawu, HIGH);
  pinMode(clawd, HIGH);
  pinMode(necku, HIGH);
  pinMode(neckd, HIGH);
  pinMode(armu, HIGH);
  pinMode(armd, HIGH);
  pinMode(bodyu, HIGH);
  pinMode(bodyd, HIGH);

  Serial.begin(9600); 
}

void loop() {
  if (Serial.available()) {
    receivedData = Serial.read(); 
    switch (receivedData) {
      case 'C': // CLAW UP
        ClawUp();
        break;
      case 'D': // CLAW DOWN
        ClawDown();
        break;
      case 'N': // NECK UP
        NeckUp();
        break;
      case 'M': // NECK DOWN
        NeckDown();
        break;
      case 'A': // ARM UP
        ArmUp();
        break;
      case 'B': // ARM UP
        ArmDown();
        break;
      case 'E': // BODY UP
        BodyUp();
        break;
      case 'F': // BODY UP
        BodyDown();
        break;
      case 'Z': // BODY UP
        Stop();
        break;
      default:
        break;
    }
  }
}

void ClawUp() {
  digitalWrite(clawu, LOW);
  digitalWrite(clawd, HIGH);
}

void ClawDown() {
  digitalWrite(clawd, LOW);
  digitalWrite(clawu, HIGH);
}

void NeckUp() {
  digitalWrite(necku, LOW);
  digitalWrite(neckd, HIGH);
}
void NeckDown() {
  digitalWrite(neckd, LOW);
  digitalWrite(necku, HIGH);
}
void ArmUp() {
  digitalWrite(armu, LOW);
  digitalWrite(armd, HIGH);
}
void ArmDown() {
  digitalWrite(armd, LOW);
  digitalWrite(armu, HIGH);
}

void BodyUp() {
  digitalWrite(bodyu, LOW);
  digitalWrite(bodyd, HIGH);
}
void BodyDown() {
  digitalWrite(bodyd, LOW);
  digitalWrite(bodyu, HIGH);
}
void Stop() {
  digitalWrite(clawu, HIGH);
  digitalWrite(clawd, HIGH);
  digitalWrite(necku, HIGH);
  digitalWrite(neckd, HIGH);
  digitalWrite(armu, HIGH);
  digitalWrite(armd, HIGH);
  digitalWrite(bodyu, HIGH);
  digitalWrite(bodyd, HIGH);
}
