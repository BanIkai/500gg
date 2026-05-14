#include "Strategy.h"
#include "Motors.h"
#include "Config.h"

namespace {

  // จำทิศล่าสุด
  int lastTarget = 0;

  // เวลาที่เจอศัตรูล่าสุด
  unsigned long targetTimer = 0;


  // ทิศการค้นหา
  bool searchDir = 0;

  // เวลาสลับทิศ
  unsigned long searchTimer = 0;


  // สถานะหนีเส้น
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
}


void AI::run(Dist dist,
             Line line) {

  // =========================
  // 1. หนีเส้นก่อนเสมอ
  // =========================

  if (line.left || line.right) {

    escapeState = 1;

    escapeLeft = line.left;

    escapeTimer = millis();
  }


  // =========================
  // 2. ถอยหลัง
  // =========================

  if (escapeState == 1) {

    Motors::move(-ESCAPE_BACK,
                 -ESCAPE_BACK);

    if (millis() - escapeTimer >= ESCAPE_BACK_MS) {

      escapeState = 2;

      escapeTimer = millis();
    }

    return;
  }


  // =========================
  // 3. หมุนกลับเข้ากลางสนาม
  // =========================

  if (escapeState == 2) {

    // ถ้าเจอเส้นซ้าย
    // ให้หมุนขวา

    if (escapeLeft) {

      Motors::move(ESCAPE_TURN,
                  -ESCAPE_TURN);
    }

    // ถ้าเจอเส้นขวา
    // ให้หมุนซ้าย

    else {

      Motors::move(-ESCAPE_TURN,
                    ESCAPE_TURN);
}
