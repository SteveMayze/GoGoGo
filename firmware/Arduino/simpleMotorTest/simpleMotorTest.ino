
int lpwmPin = 11;
int lstbyPin = 0;
int linp1 = 1;
int linp2 = 2;



int rpwmPin = 10;
int rstbyPin = 3;
int rinp1 = 5;
int rinp2 = 4;

void setup() {
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


void fullForward() {

  // Left
  digitalWrite(lpwmPin, HIGH);
  digitalWrite(linp1, HIGH);
  digitalWrite(linp2, LOW);

  // Right
  digitalWrite(rpwmPin, HIGH);
  digitalWrite(rinp1, HIGH);
  digitalWrite(rinp2, LOW);

  // Enable together...
  digitalWrite(lstbyPin, HIGH);
  digitalWrite(rstbyPin, HIGH);
}


void fullRev(){
    digitalWrite(linp1, LOW);
    digitalWrite(linp2, HIGH);
    digitalWrite(rinp1, LOW);
    digitalWrite(rinp2, HIGH);

    digitalWrite(lstbyPin, HIGH);
    digitalWrite(rstbyPin, HIGH);

}

void allStop() {
  digitalWrite(linp1, LOW);
  digitalWrite(linp2, LOW);
  digitalWrite(rinp1, LOW);
  digitalWrite(rinp2, LOW);
  
}
void loop() {
  // put your main code here, to run repeatedly:

  // Full speed in one direction.
  fullForward();
  delay(2000);

  // All stop!
  allStop();
  delay(4000);

  // Full speed in the other direction.
  fullRev();
  delay(2000);

  // All Stop
  allStop();
  delay(4000);

  
}
