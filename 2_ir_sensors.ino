#include <AFMotor.h>

const int left = 22;
const int right = 24;
const int mcenter = 26;

// Define motor shield pins
AF_DCMotor motor1(1);   // Motor 1
AF_DCMotor motor2(2);   // Motor 2
AF_DCMotor motor3(3);   // Motor 3
AF_DCMotor motor4(4);   // Motor 4

const int motorSpeed = 80;

void setup() {
  pinMode(left, INPUT);
  pinMode(right, INPUT);
  pinMode(mcenter, INPUT);

  Serial.begin(9600);

  motor1.setSpeed(motorSpeed);
  motor2.setSpeed(motorSpeed);
  motor3.setSpeed(motorSpeed);
  motor4.setSpeed(motorSpeed);

  delay(5000);
}
void loop(){
  int sleft = digitalRead(left);
  int sright = digitalRead(right);
  int center = digitalRead(mcenter);

  if ((!sleft && !sright) || (!center && !sleft && !sright)){
    moveForward();
  } else if (sleft && sright){
    motor1.run(RELEASE);
    motor2.run(RELEASE);  
    motor3.run(RELEASE);
    motor4.run(RELEASE);
  } else if (!sleft && sright){
    turnLeft();
  } else if (sleft && !sright){
    delay(50);
    turnRight();
  } else if (sleft && !center && right){
    moveForward();
  } else if (sleft && !sright && !center){
    turnLeft();
  } else if (!sleft && sright && !center){
    turnRight();
  }
}

void moveForward() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);  
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
void turnRight() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
void turnLeft() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

