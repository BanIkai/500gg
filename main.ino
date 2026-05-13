#include "Motors.h"
#include "Sensors.h"
#include "Strategy.h"

void setup() {

  Motors::begin();

  Sensors::begin();

  AI::reset();
}

void loop() {

  Dist dist =
    Sensors::readDist();

  Line line =
    Sensors::readLine();

  AI::run(dist, line);
}
