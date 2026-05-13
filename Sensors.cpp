#include "Sensors.h"
#include "Config.h"

#include <Wire.h>
#include <VL53L0X.h>



namespace {

  VL53L0X tofSL;
  VL53L0X tofFL;
  VL53L0X tofFC;
  VL53L0X tofFR;
  VL53L0X tofSR;



  void startToF(VL53L0X &sensor,
                int xshutPin,
                int address) {

    digitalWrite(xshutPin, HIGH);

    delay(10);

    sensor.setTimeout(TOF_TIMEOUT);

    if (!sensor.init()) {

      while (1);
    }

    sensor.setAddress(address);

    sensor.startContinuous();
  }
}



void Sensors::begin() {

  Wire.begin();



  pinMode(PIN_XSHUT_SL, OUTPUT);
  pinMode(PIN_XSHUT_FL, OUTPUT);
  pinMode(PIN_XSHUT_FC, OUTPUT);
  pinMode(PIN_XSHUT_FR, OUTPUT);
  pinMode(PIN_XSHUT_SR, OUTPUT);



  digitalWrite(PIN_XSHUT_SL, LOW);
  digitalWrite(PIN_XSHUT_FL, LOW);
  digitalWrite(PIN_XSHUT_FC, LOW);
  digitalWrite(PIN_XSHUT_FR, LOW);
  digitalWrite(PIN_XSHUT_SR, LOW);

  delay(10);



  startToF(tofSL,
           PIN_XSHUT_SL,
           ADDR_SL);

  startToF(tofFL,
           PIN_XSHUT_FL,
           ADDR_FL);

  startToF(tofFC,
           PIN_XSHUT_FC,
           ADDR_FC);

  startToF(tofFR,
           PIN_XSHUT_FR,
           ADDR_FR);

  startToF(tofSR,
           PIN_XSHUT_SR,
           ADDR_SR);



  pinMode(PIN_IR_L, INPUT);
  pinMode(PIN_IR_R, INPUT);
}



Dist Sensors::readDist() {

  Dist d;



  d.sl =
    tofSL.readRangeContinuousMillimeters();

  d.fl =
    tofFL.readRangeContinuousMillimeters();

  d.fc =
    tofFC.readRangeContinuousMillimeters();

  d.fr =
    tofFR.readRangeContinuousMillimeters();

  d.sr =
    tofSR.readRangeContinuousMillimeters();



  if (tofSL.timeoutOccurred()) d.sl = NO_TARGET;

  if (tofFL.timeoutOccurred()) d.fl = NO_TARGET;

  if (tofFC.timeoutOccurred()) d.fc = NO_TARGET;

  if (tofFR.timeoutOccurred()) d.fr = NO_TARGET;

  if (tofSR.timeoutOccurred()) d.sr = NO_TARGET;



  return d;
}



Line Sensors::readLine() {

  Line l;

  l.left =
    digitalRead(PIN_IR_L) == LOW;

  l.right =
    digitalRead(PIN_IR_R) == LOW;

  return l;
}
