int blue = 3;
int green = 6;
int yellow = 9;
int red = 12;
int firststar= 4;
int secondstar= 7;
int thirdstar= 10;

void setup() {
pinMode(blue, OUTPUT);
pinMode(green, OUTPUT);
pinMode(yellow, OUTPUT);
pinMode(red, OUTPUT);
pinMode(firststar, OUTPUT);
pinMode(secondstar, OUTPUT);
pinMode(thirdstar, OUTPUT);
}

void loop() {
  digitalWrite(firststar,HIGH);
  //1st sequence turning on inner to outer
  for(int i=0; i<=4; i++){

  digitalWrite(blue,HIGH);
  delay(100);
  digitalWrite(blue,LOW);
  digitalWrite(green,HIGH);
  delay(100);
  digitalWrite(green,LOW);
  digitalWrite(yellow,HIGH);
  delay(100);
  digitalWrite(yellow,LOW);
  digitalWrite(red,HIGH);
  delay(100);
  digitalWrite(red,LOW);
  }
  digitalWrite(firststar,LOW);

  //2nd sequence  turning on outer to inner
  digitalWrite(secondstar,HIGH);
for(int x=0; x<=4; x++){
 
  digitalWrite(red,HIGH);
  delay(100);
  digitalWrite(red,LOW);
  digitalWrite(yellow,HIGH);
  delay(100);
  digitalWrite(yellow,LOW);
  digitalWrite(green,HIGH);
  delay(100);
  digitalWrite(green,LOW);
  digitalWrite(blue,HIGH);
  delay(100);
  digitalWrite(blue,LOW);
   
  }
digitalWrite(secondstar,LOW);


//3rd sequence  BLINKING
digitalWrite(firststar,HIGH);
digitalWrite(secondstar,HIGH);
for(int y=0; y<=4; y++){
 
  digitalWrite(green,HIGH);
  delay(50);
   digitalWrite(green,LOW);
  digitalWrite(yellow,HIGH);
  delay(50);
    digitalWrite(yellow,LOW);
  digitalWrite(red,HIGH);
  delay(50);
  digitalWrite(red,LOW);
  digitalWrite(blue,HIGH);
  delay(50);
  digitalWrite(blue,LOW);
 
  }
digitalWrite(firststar,LOW);
digitalWrite(secondstar,LOW);


  //4th sequence DUal alternating
  digitalWrite(thirdstar,HIGH);
for(int j=0; j<=4; j++){

  digitalWrite(blue,HIGH);
  digitalWrite(yellow,HIGH);
  delay(200);
  digitalWrite(blue,LOW);
  digitalWrite(yellow,LOW);
  digitalWrite(green,HIGH);
  digitalWrite(red,HIGH);
  delay(200);
  digitalWrite(green,LOW);
  digitalWrite(red,LOW);

  }
  digitalWrite(thirdstar,LOW);


digitalWrite(thirdstar,HIGH);
digitalWrite(firststar,HIGH);
  //5th sequence dual sequence  
  for(int h=0; h<=4; h++){
 
  digitalWrite(blue,HIGH);
  digitalWrite(yellow,HIGH);
  delay(100);
  digitalWrite(blue,LOW);
   digitalWrite(yellow,LOW);
  digitalWrite(green,HIGH);
  digitalWrite(red,HIGH);
  delay(100);
  digitalWrite(green,LOW);
  digitalWrite(red,LOW);

  }
digitalWrite(thirdstar,LOW);
digitalWrite(firststar,LOW);



digitalWrite(thirdstar,HIGH);
digitalWrite(secondstar,HIGH);
  //6th sequence turning off inner to outer
  for(int h=0; h<=4; h++){
 
  digitalWrite(blue,HIGH);
  digitalWrite(green,HIGH);
  digitalWrite(yellow,HIGH);
  digitalWrite(red,HIGH);
  delay(100);
  digitalWrite(blue,LOW);
  delay(100);
  digitalWrite(blue,HIGH);
  digitalWrite(green,LOW);
  delay(100);
  digitalWrite(green,HIGH);
  digitalWrite(yellow,LOW);
  delay(100);
  digitalWrite(yellow,HIGH);
  digitalWrite(red,LOW);
  delay(100);
  digitalWrite(red,HIGH);
  }
digitalWrite(thirdstar,LOW);
digitalWrite(secondstar,LOW);
}
