#pragma once

// =========================
// MOTOR
// =========================

#define PIN_L1 11
#define PIN_L2 10

#define PIN_R1 5
#define PIN_R2 6



// =========================
// LINE SENSOR
// =========================

#define PIN_LINE_L A2
#define PIN_LINE_R A7

#define LINE_L_TH 500
#define LINE_R_TH 500



// =========================
// XSHUT
// =========================

#define PIN_XSHUT_SL 13
#define PIN_XSHUT_FL 12
#define PIN_XSHUT_FC 4
#define PIN_XSHUT_FR 2
#define PIN_XSHUT_SR 3



// =========================
// TOF ADDRESS
// =========================

#define ADDR_SL 0x30
#define ADDR_FL 0x31
#define ADDR_FC 0x32
#define ADDR_FR 0x33
#define ADDR_SR 0x34



// =========================
// DISTANCE
// =========================

#define RAM_DIST      200
#define TRACK_DIST    450
#define SIDE_DIST     350



// =========================
// SPEED
// =========================

#define RAM_SPEED      255

#define TRACK_FAST     255
#define TRACK_SLOW     140

#define SEARCH_SPEED   180

#define ESCAPE_BACK    255
#define ESCAPE_TURN    180



// =========================
// TIME
// =========================

#define ESCAPE_BACK_MS 180
#define ESCAPE_TURN_MS 220

#define LOCK_TIME      300

#define SEARCH_TIME    600



// =========================
// SENSOR
// =========================

#define TOF_TIMEOUT    20

#define NO_TARGET      999
