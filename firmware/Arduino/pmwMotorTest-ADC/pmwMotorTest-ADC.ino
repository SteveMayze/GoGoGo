int lpwmPin = 11;
int lstbyPin = 0;
int linp1 = 1;
int linp2 = 2;



int rpwmPin = 10;
int rstbyPin = 3;
int rinp1 = 5;
int rinp2 = 4;

int potPin = 2;
int speed = 0;


void setup() {
  // put your setup code here, to run once:
  // Left
  pinMode(lstbyPin, OUTPUT);
  pinMode(linp1, OUTPUT);
  pinMode(linp2, OUTPUT);
  pinMode(lpwmPin, OUTPUT);

// Right
  pinMode(rstbyPin, OUTPUT);
  pinMode(rinp1, OUTPUT);
  pinMode(rinp2, OUTPUT);
  pinMode(rpwmPin, OUTPUT);
}


void fullForward(int speed) {

  // Left
  digitalWrite(lstbyPin, HIGH);
  digitalWrite(lpwmPin, HIGH);
  digitalWrite(linp1, HIGH);
  digitalWrite(linp2, LOW);

  // Right
  digitalWrite(rstbyPin, HIGH);
  digitalWrite(rpwmPin, HIGH);
  digitalWrite(rinp1, HIGH);
  digitalWrite(rinp2, LOW);

  analogWrite(lpwmPin, speed);
  analogWrite(rpwmPin, speed);

}


void fullRev( int speed ){
    digitalWrite(linp1, LOW);
    digitalWrite(linp2, HIGH);
    
    digitalWrite(rinp1, LOW);
    digitalWrite(rinp2, HIGH);

    digitalWrite(lstbyPin, HIGH);
    digitalWrite(rstbyPin, HIGH);
    
    analogWrite(lpwmPin, speed);
    analogWrite(rpwmPin, speed);

}

void allStop() {
  digitalWrite(linp1, LOW);
  digitalWrite(linp2, LOW);
  digitalWrite(rinp1, LOW);
  digitalWrite(rinp2, LOW);
  analogWrite(lpwmPin, 255);
  analogWrite(rpwmPin, 255);
  
}


void loop() {
  // put your main code here, to run repeatedly:
  speed = analogRead( potPin ) * 0.25;
  fullForward(speed);
  delay(1);
  
}
