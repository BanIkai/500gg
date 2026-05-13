#include "Strategy.h"
#include "Motors.h"
#include "Config.h"



namespace {

  int lastTarget = 0;



  unsigned long targetTimer = 0;



  bool searchDir = 0;

  unsigned long searchTimer = 0;



  int escapeState = 0;

  bool escapeLeft = false;

  unsigned long escapeTimer = 0;
}



void AI::reset() {

  lastTarget = 0;

  targetTimer = 0;

  searchDir = 0;

  searchTimer = 0;

  escapeState = 0;

  escapeLeft = false;

  escapeTimer = 0;
}



void AI::run(Dist dist,
             Line line) {

  // =========================
  // ESCAPE
  // =========================

  if (escapeState == 1) {

    Motors::move(-ESCAPE_BACK,
                 -ESCAPE_BACK);

    if (millis() - escapeTimer >= ESCAPE_BACK_MS) {

      escapeTimer = millis();

      escapeState = 2;
    }

    return;
  }



  if (escapeState == 2) {

    if (escapeLeft) {

      Motors::move(ESCAPE_TURN,
                   -ESCAPE_BACK);
    }

    else {

      Motors::move(-ESCAPE_BACK,
                    ESCAPE_TURN);
    }

    if (millis() - escapeTimer >= ESCAPE_TURN_MS) {

      escapeState = 0;
    }

    return;
  }



  // =========================
  // START ESCAPE
  // =========================

  if (line.left || line.right) {

    escapeState = 1;

    escapeTimer = millis();

    escapeLeft = line.left;

    return;
  }



  // =========================
  // RAM
  // =========================

  if (dist.front < RAM_DIST) {

    Motors::move(RAM_SPEED,
                 RAM_SPEED);

    lastTarget = 0;

    targetTimer = millis();

    return;
  }



  // =========================
  // TRACK LEFT
  // =========================

  if (dist.left < TRACK_DIST) {

    Motors::move(TRACK_SLOW,
                 TRACK_FAST);

    lastTarget = -1;

    targetTimer = millis();

    return;
  }



  // =========================
  // TRACK RIGHT
  // =========================

  if (dist.right < TRACK_DIST) {

    Motors::move(TRACK_FAST,
                 TRACK_SLOW);

    lastTarget = 1;

    targetTimer = millis();

    return;
  }



  // =========================
  // TARGET LOCK
  // =========================

  if (millis() - targetTimer <= LOCK_TIME) {

    if (lastTarget == -1) {

      Motors::move(-SEARCH_SPEED,
                    SEARCH_SPEED);

      return;
    }

    if (lastTarget == 1) {

      Motors::move(SEARCH_SPEED,
                   -SEARCH_SPEED);

      return;
    }
  }



  // =========================
  // SEARCH
  // =========================

  if (millis() - searchTimer >= SEARCH_TIME) {

    searchDir = !searchDir;

    searchTimer = millis();
  }



  if (searchDir == 0) {

    Motors::move(-SEARCH_SPEED,
                  SEARCH_SPEED);
  }

  else {

    Motors::move(SEARCH_SPEED,
                 -SEARCH_SPEED);
  }
}
