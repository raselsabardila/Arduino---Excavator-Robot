#include <Servo.h>

#define PIN_SERVO_BOTTOM 3
#define PIN_SERVO_RIGHT 4
#define PIN_SERVO_LEFT 5
#define PIN_JOYSTIK_BOTTOM_X A1
#define PIN_JOYSTIK_RIGHT_Y A0
#define PIN_JOYSTIK_LEFT_Y A2

Servo servoBottom;
Servo servoRight;
Servo servoLeft;

int valueBottom = 80;
int valueRight = 0;
int valueLeft = 30;

void setup() {
  Serial.begin(9600);
  
  pinMode(PIN_JOYSTIK_BOTTOM_X, INPUT);
  pinMode(PIN_JOYSTIK_RIGHT_Y, INPUT);
  pinMode(PIN_JOYSTIK_LEFT_Y, INPUT);

  servoBottom.attach(PIN_SERVO_BOTTOM);
  servoRight.attach(PIN_SERVO_RIGHT);
  servoLeft.attach(PIN_SERVO_LEFT);

  servoLeft.write(valueLeft);
  servoRight.write(valueRight);
  servoBottom.write(valueBottom);
  delay(1000);
}

void loop() {;
  int bottomX = analogRead(PIN_JOYSTIK_BOTTOM_X);
  int rightY = analogRead(PIN_JOYSTIK_RIGHT_Y);
  int leftY = analogRead(PIN_JOYSTIK_LEFT_Y);

  if(rightY <= 400 && rightY >= 0) {
    if(valueRight < 70) {
      valueRight += 10;
      servoRight.write(valueRight);
      delay(30);
    }
  } else if(rightY >= 530 && rightY <= 1023) {
    if(valueRight >= 5) {
      valueRight -= 10;
      servoRight.write(valueRight);
      delay(30);
    }

    if(valueRight == 0) {
      servoRight.write(valueRight);
    }
  }

  if(leftY <= 400 && leftY >= 0) {
    if(valueLeft < 150) {
      valueLeft += 10;
      servoLeft.write(valueLeft);
      delay(30);
    }
  } else if(leftY >= 530 && leftY <= 1023) {
    if(valueLeft >= 30) {
      valueLeft -= 10;
      servoLeft.write(valueLeft);
      delay(30);
    }

    if(valueLeft == 0) {
      servoLeft.write(valueLeft);
    }
  }

  if(bottomX <= 400 && bottomX >= 0) {
    if(valueBottom < 150) {
      valueBottom += 5;
      servoBottom.write(valueBottom);
      delay(25);
    }
  } else if(bottomX >= 630 && bottomX <= 1023) {
    if(valueBottom >= 10) {
      valueBottom -= 5; 
      servoBottom.write(valueBottom);
      delay(25);
    }
  }
  Serial.println(leftY);
}
