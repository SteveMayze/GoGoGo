

#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#define sbi(sfr, bit) (_SFR_BYTE(sfr) != _BV(bit))

volatile unsigned long leftTick = 0;
volatile unsigned long rightTick = 0;
volatile bool stopLeft = false;
volatile bool stopRight = false;


String cmdStr;
String msg = "@ ";
char cmd[5];

int lpwmPin = 9; // PWM ~9
int lstbyPin = 11;
int linp1 = 13;
int linp2 = 12;
int lwheel = 2; // INT0
unsigned long lTickLimit = 0;



int rpwmPin = 10; // PWM ~10
int rstbyPin = 4;
int rinp1 = 5;
int rinp2 = 6;
int rwheel = 3; // INT1
unsigned long rTickLimit = 0;

bool leftRunning = false;
bool rightRunning=false;

int potPin = 2;
int speed = 0;

void isr_leftTick();
void isr_rightTick();

void setup() {
   Serial.begin(9600);

   pinMode(lwheel, INPUT);
   digitalWrite(lwheel, HIGH);
  
   pinMode(rwheel, INPUT);
   digitalWrite(rwheel, HIGH);

  pinMode(lstbyPin, OUTPUT);
  pinMode(linp1, OUTPUT);
  pinMode(linp2, OUTPUT);
  pinMode(lpwmPin, OUTPUT);

  // Right
  pinMode(rstbyPin, OUTPUT);
  pinMode(rinp1, OUTPUT);
  pinMode(rinp2, OUTPUT);
  pinMode(rpwmPin, OUTPUT);

  pinMode(lwheel, OUTPUT);
  pinMode(rwheel, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(lwheel), isr_leftTick, RISING);
  attachInterrupt(digitalPinToInterrupt(rwheel), isr_rightTick, RISING);
  leftRunning = false;
  rightRunning  = false;
}


void reverse(int speed, int ticks) {
  msg = "";
  msg = msg + "BACK ... speed=" + speed + ", ticks=" + ticks;
  Serial.println(msg);
  leftRev(speed, ticks);
  rightRev(speed, ticks);

}

void rightRev(int speed, int ticks) {
    rTickLimit = ticks;
    rightTick = 0;
    msg = "";
    msg = msg + "LEFT Back ... speed=" + speed + ", ticks=" + ticks;
  Serial.println(msg);
  digitalWrite(rinp1, HIGH);
  digitalWrite(rinp2, LOW);
  digitalWrite(rstbyPin, HIGH);
  analogWrite(rpwmPin, speed);
  rightRunning = true;
  stopRight = false;

}

void leftRev(int speed, int ticks){
    lTickLimit = ticks;
    leftTick = 0;
    msg = "";
    msg = msg + "RIGHT Back ... speed=" + speed + ", ticks=" + ticks;
  Serial.println(msg);
  digitalWrite(linp1, HIGH);
  digitalWrite(linp2, LOW);
  digitalWrite(lstbyPin, HIGH);
  analogWrite(lpwmPin, speed);
  leftRunning = true;
  stopLeft=false;
  
}

void forward( int speed, int ticks ){
    msg = "";
    msg = msg + "FORWARD ... speed=" + speed + ", ticks=" + ticks;
    Serial.println(msg);
    leftFwd(speed, ticks);
    rightFwd(speed, ticks);
}

void rightFwd(int speed, int ticks) {
    rTickLimit = ticks;
    rightTick = 0;
    msg = "";
    msg = msg + "RIGHT Forward ... speed=" + speed + ", ticks=" + ticks;
    Serial.println(msg);
    digitalWrite(rinp1, LOW);
    digitalWrite(rinp2, HIGH);
    analogWrite(rpwmPin, speed);
    digitalWrite(rstbyPin, HIGH);
    rightRunning = true;
    stopRight = false;
}

void leftFwd(int speed, int ticks){
    lTickLimit = ticks;
    leftTick = 0;
    msg = "";
    msg = msg + "LEFT Forward ... speed=" + speed + ", ticks=" + ticks;
    Serial.println(msg);
    digitalWrite(linp1, LOW);
    digitalWrite(linp2, HIGH);
    digitalWrite(lstbyPin, HIGH);
    analogWrite(lpwmPin, speed);
    leftRunning = true;
    stopLeft = false;
}

void allStop() {
  Serial.println("ALL STOP!");
  leftStop();
  rightStop();
}

void leftStop() {
  Serial.println("LEFT STOP!");
  //digitalWrite(linp1, LOW);
  //digitalWrite(linp2, LOW);
  digitalWrite(lstbyPin, LOW);
  lTickLimit = 0;
  leftTick = 1;
  leftRunning = false;
}

void rightStop() {
  Serial.println("RIGHT STOP!");
  //digitalWrite(rinp1, LOW);
  //digitalWrite(rinp2, LOW);
  digitalWrite(rstbyPin, LOW);
  rTickLimit = 0;
  rightTick = 1;
  rightRunning = false;
}


void loop() {
    int newCmd = false;
    int param = 0;
    if(Serial.available() > 0)
    {
        cmdStr = Serial.readStringUntil(' ');
        param = Serial.parseInt();
        cmdStr.toCharArray(cmd, 5);
        newCmd = true;
    }
    if(newCmd) {
      msg = "";
      switch(cmd[0]){
        case 'f':
           forward(speed, param);
           break;
        case 'b':
           reverse(speed, param);
           break;
        case 'r':
           switch(cmd[1]) {
            case 'b':
              leftStop();
              rightRev(speed, param);
              break;
            default:
              leftStop();
              rightFwd(speed, param);
              break;
           }
           break;
        case 'l':
           switch(cmd[1]) {
            case 'b':
               rightStop();
               leftRev(speed, param);
               break;
            default:
               rightStop();
               leftFwd(speed, param);
              break;
           }
           break;
        case 's':
           speed = param;
           msg = msg + "Speed " + param + " units";
           Serial.println(msg);
           analogWrite(lpwmPin, speed);
           analogWrite(rpwmPin, speed);
           break;
        case 'q':
           msg = msg + "DUMP\n=======================" + 
                       "\nSpeed " + speed + 
                       "\nleftTick=" + leftTick + 
                       "\nrightTick=" + rightTick + 
                       "\nlTickLimit=" + lTickLimit + 
                       "\nrTickLimit=" + rTickLimit + 
                       "\nleftRunning=" + leftRunning +
                       "\nrightRunning=" + rightRunning;
           Serial.println(msg);
           break;
        case 'h':
           switch(cmd[1]) {
            case 'l':
               rightStop();
               break;
            case 'r':
               leftStop();
               break;
            default:
               msg = msg + "HALT!";
               allStop();
            break;              
           }
           break;
        default:
           msg = msg +  "Command " + cmdStr + " is not yet implemented";
           break;
      }
      newCmd = false;
    }  

    if ( leftRunning || rightRunning ) {
       msg = "";
       msg = msg + "RUNNING leftRunning=" + leftRunning + ", leftTick=" + leftTick + " lTickLimit=" + lTickLimit + 
                   "\n        rightRunning=" + rightRunning + ", rightTick=" + rightTick + " rTickLimit=" + rTickLimit;
       Serial.println(msg);
       if(stopRight && rightRunning ) {
         rightStop();
      }
       if ( stopLeft && leftRunning ) {
         leftStop();
       }
    }
}


void isr_leftTick() {
  ++leftTick;
  stopLeft = leftTick > lTickLimit;
}

void isr_rightTick() {
  ++rightTick;
  stopRight = rightTick > rTickLimit;
}



