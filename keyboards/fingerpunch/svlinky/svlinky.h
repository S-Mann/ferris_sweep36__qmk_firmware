#pragma once
#include "quantum.h"

#define LAYOUT_svlinky( \
  K01, K02, K03, K04, K05, K06, K07, K08, K09, K10, \
  K11, K12, K13, K14, K15, K16, K17, K18, K19, K20, \
  K21, K22, K23, K24, K25, K26, K27, K28, K29, K30, \
  K31, K32, K33, K34, K35, K36, K37, K38, K39, K40, \
  K41, K42, K43, K44, K45, K46, K47, K48, K49, K50, \
  K51, K52, K53, K54, K55, K56, K57, K58, K59, K60, \
  K61, K62, K63, K64, K65, K66, K67, K68, K69, K70, \
  K71, K72, K73, K74, K75, K76, K77, K78, K79, K80 \
  ) \
  { \
    { K01, K02, K03, K04, K05, K06, K07, K08, K09, K10 }, \
    { K11, K12, K13, K14, K15, K16, K17, K18, K19, K20 }, \
    { K21, K22, K23, K24, K25, K26, K27, K28, K29, K30 }, \
    { K31, K32, K33, K34, K35, K36, K37, K38, K39, K40 }, \
    { K41, K42, K43, K44, K45, K46, K47, K48, K49, K50 }, \
    { K51, K52, K53, K54, K55, K56, K57, K58, K59, K60 }, \
    { K61, K62, K63, K64, K65, K66, K67, K68, K69, K70 }, \
    { K71, K72, K73, K74, K75, K76, K77, K78, K79, K80 } \
  }

// for FP_WEACT_ST7735 only
typedef struct kb_runtime_config {
    unsigned          lcd_power : 1;
} kb_runtime_config;

extern kb_runtime_config kb_state;

void housekeeping_task_sync(void);

// General fingerpunch firmware include
#include "keyboards/fingerpunch/src/fp.h"
