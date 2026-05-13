#include "Motors.h"
#include "Config.h"

#include <Arduino.h>



namespace {

  void leftMotor(int speed) {

    speed = constrain(speed, -255, 255);

    if (speed > 0) {

      analogWrite(PIN_L1, speed);
      digitalWrite(PIN_L2, LOW);
    }

    else if (speed < 0) {

      digitalWrite(PIN_L1, LOW);
      analogWrite(PIN_L2, -speed);
    }

    else {

      digitalWrite(PIN_L1, LOW);
      digitalWrite(PIN_L2, LOW);
    }
  }



  void rightMotor(int speed) {

    speed = constrain(speed, -255, 255);

    if (speed > 0) {

      analogWrite(PIN_R1, speed);
      digitalWrite(PIN_R2, LOW);
    }

    else if (speed < 0) {

      digitalWrite(PIN_R1, LOW);
      analogWrite(PIN_R2, -speed);
    }

    else {

      digitalWrite(PIN_R1, LOW);
      digitalWrite(PIN_R2, LOW);
    }
  }
}



void Motors::begin() {

  pinMode(PIN_L1, OUTPUT);
  pinMode(PIN_L2, OUTPUT);

  pinMode(PIN_R1, OUTPUT);
  pinMode(PIN_R2, OUTPUT);
}



void Motors::move(int left,
                  int right) {

  leftMotor(left);

  rightMotor(right);
}



void Motors::stop() {

  move(0, 0);
}
