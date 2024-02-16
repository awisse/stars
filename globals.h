// Wall, Target, Box, Box on Target
#pragma once
#include "defines.h"
/* typedef enum Piece Piece; */
typedef enum {
  Short_A,
  Long_A,
  Short_B,
  Long_B,
  /* VeryLong_B, */
  Left,
  Right,
  Up,
  Down
} Event;

enum Direction {
  down,
  left,
  right,
  up
};

enum StarState {
  hidden,
  dimmed,
  halfdimmed,
  full
};
constexpr uint16_t max_stars = MAX_STARS;
// vim:ft=cpp
