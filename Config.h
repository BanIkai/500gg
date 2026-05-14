#pragma once
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
// DISTANCE (mm)
// =========================

#define RAM_DIST       180
#define TRACK_DIST     350
#define SIDE_DIST      250


// =========================
// SPEED
// =========================

#define MAX_SPEED      255

#define ATTACK_SPEED   255
#define TRACK_FAST     220
#define TRACK_SLOW     130

#define SEARCH_SPEED   170
#define SEARCH_FAST    220

#define ESCAPE_BACK    255
#define ESCAPE_TURN    200


// =========================
// TIME
// =========================

#define ESCAPE_BACK_MS 180
#define ESCAPE_TURN_MS 220

#define LOCK_TIME      350

#define SEARCH_SWAP_MS 700


// =========================
// SENSOR
// =========================

#define TOF_TIMEOUT    20

#define NO_TARGET      999
