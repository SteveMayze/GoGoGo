

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
int lstbyPin = 5; // PD5
int linp1 = 13;
int linp2 = 12;
int lwheel = 2; // INT0
unsigned long lTickLimit = 0;



int rpwmPin = 10; // PWM ~10
int rstbyPin = 4; // PD4
int rinp1 = 6;
int rinp2 = 7;
int rwheel = 3; // INT1
unsigned long rTickLimit = 0;

bool leftRunning = false;
bool rightRunning=false;

int potPin = 2;
int speed = 60;

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

void forward( int speed, int ticks ){
    msg = "";
    msg = msg + "FORWARD ... speed=" + speed + ", ticks=" + ticks;
    Serial.println(msg);
    leftFwd(speed, ticks);
    rightFwd(speed, ticks);
    PORTD |= B00110000;
}

void reverse(int speed, int ticks) {
  msg = "";
  msg = msg + "BACK ... speed=" + speed + ", ticks=" + ticks;
  Serial.println(msg);
  leftRev(speed, ticks);
  rightRev(speed, ticks);
  PORTD |= B00110000;

}

void rightFwd(int speed, int ticks) {
    rTickLimit = ticks;
    rightTick = 0;
    msg = "";
    msg = msg + "RIGHT Forward ... speed=" + speed + ", ticks=" + ticks;
    Serial.println(msg);
    digitalWrite(rinp1, LOW);
    digitalWrite(rinp2, HIGH);
    digitalWrite(rstbyPin, HIGH);
    analogWrite(rpwmPin, speed);
    // digitalWrite(rstbyPin, HIGH);
    rightRunning = true;
    stopRight = false;
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


void allStop() {
  PORTD &= B11001111;
  Serial.println("ALL STOP!");
  // leftStop();
  // rightStop();
  lTickLimit = 0;
  leftTick = 1;
  leftRunning = false;
  rTickLimit = 0;
  rightTick = 1;
  rightRunning = false;
}

void leftStop() {
  Serial.println("LEFT STOP!");
  digitalWrite(linp1, LOW);
  digitalWrite(linp2, LOW);
  digitalWrite(lstbyPin, HIGH);
  lTickLimit = 0;
  leftTick = 1;
  leftRunning = false;
}

void rightStop() {
  Serial.println("RIGHT STOP!");
  digitalWrite(rinp1, LOW);
  digitalWrite(rinp2, LOW);
  digitalWrite(rstbyPin, HIGH);
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
              digitalWrite(rstbyPin, HIGH);
              break;
            default:
              leftStop();
              rightFwd(speed, param);
              digitalWrite(rstbyPin, HIGH);
              break;
           }
           break;
        case 'l':
           switch(cmd[1]) {
            case 'b':
               rightStop();
               leftRev(speed, param);
               digitalWrite(lstbyPin, HIGH);
               break;
            default:
               rightStop();
               leftFwd(speed, param);
               digitalWrite(lstbyPin, HIGH);
              break;
           }
           break;
        case 's':
           speed = param;
           Serial.println(msg);
           switch(cmd[1]) {
            case 'l':
              analogWrite(lpwmPin, speed);
              msg = msg + "LEFT Speed " + param + " units";
               break;
            case 'r':
              analogWrite(rpwmPin, speed);
              msg = msg + "RIGHT Speed " + param + " units";
               break;
            default:
              analogWrite(lpwmPin, speed);
              analogWrite(rpwmPin, speed);
              msg = msg + "Speed " + param + " units";
            break;              
           }
           Serial.println(msg);
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
                   " rightRunning=" + rightRunning + ", rightTick=" + rightTick + " rTickLimit=" + rTickLimit;
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



