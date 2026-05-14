#include "Strategy.h"
  // =========================

  if (dist.fc < RAM_DIST) {

    Motors::move(ATTACK_SPEED,
                 ATTACK_SPEED);

    lastTarget = 0;

    targetTimer = millis();

    return;
  }


  // =========================
  // 5. เจอด้านซ้าย
  // =========================

  if (dist.fl < TRACK_DIST ||
      dist.sl < SIDE_DIST) {

    Motors::move(TRACK_SLOW,
                 TRACK_FAST);

    lastTarget = -1;

    targetTimer = millis();

    return;
  }


  // =========================
  // 6. เจอด้านขวา
  // =========================

  if (dist.fr < TRACK_DIST ||
      dist.sr < SIDE_DIST) {

    Motors::move(TRACK_FAST,
                 TRACK_SLOW);

    lastTarget = 1;

    targetTimer = millis();

    return;
  }


  // =========================
  // 7. ล็อกเป้าชั่วคราว
  // =========================

  if (millis() - targetTimer <= LOCK_TIME) {

    // เป้าล่าสุดอยู่ซ้าย
    if (lastTarget == -1) {

      Motors::move(-SEARCH_SPEED,
                    SEARCH_FAST);

      return;
    }


    // เป้าล่าสุดอยู่ขวา
    if (lastTarget == 1) {

      Motors::move(SEARCH_FAST,
                  -SEARCH_SPEED);

      return;
    }
  }


  // =========================
  // 8. หมุนหาศัตรู
  // =========================

  if (millis() - searchTimer >= SEARCH_SWAP_MS) {

    searchDir = !searchDir;

    searchTimer = millis();
  }


  // หมุนซ้าย
  if (!searchDir) {

    Motors::move(-SEARCH_SPEED,
                  SEARCH_SPEED);
  }

  // หมุนขวา
  else {

    Motors::move(SEARCH_SPEED,
                 -SEARCH_SPEED);
  }
}
