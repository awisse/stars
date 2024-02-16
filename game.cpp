/*
Helper functions to unclutter main .ino file
 */
#include "game.h"
#include "draw.h"
#include "controller.h"
#include "globals.h"
#include "utils.h"
#include "platform.h"

// Global variables
bool modified; // True if screen needs to be redrawn
bool running;
/* uint16_t has the following information:
 * Bits 0-1: StarState: on, off, dimmend
 * Bit 2: Direction of animation
 * Bits 3-9: x-coordinate
 * Bits 10-15: y-coordinate
 */
uint16_t stars[max_stars];

void InitStars();
void ShowStars();
void StepStars();

uint16_t frame;

// Functions
void InitGame() {

  running = false;
  modified = true;
  frame = 0;

  uint16_t seed = Platform::GenerateRandomSeed() & 0xFFFF;
  SRand(seed);

  InitStars();
  Platform::Clear();
}

bool StepGame() {
  uint16_t step;

  HandleInput();

  // Don't refresh too often:
  step = (++frame) % FRAME_STEP;
  if (running && (step==0)) {
    StepStars();
  }

  if (modified) {
    modified = false;
    return true;
  }
  return false;
}

void InitStars() {
  uint8_t i=0, x, y;
  uint32_t r;


  while (i<max_stars) {
    r = Rand();
    x = XPOS(r);
    y = YPOS(r);
    // No stars inside the message rectangle
    if ((x > MSG_X - 3) && (x <= MSG_X + MSG_W) &&
        (y > MSG_Y - 3) && (y <= MSG_Y + MSG_H)) continue;
    stars[i] = r;
    i++;
  }
}

void ShowStars() {
  DrawStars(stars);
  Platform::DrawRect(MSG_X, MSG_Y, MSG_W, MSG_H);
  modified = true;
  running = true;
}

void ToggleAnimation() {
  running = !running;
}

void StepStars() {
  uint8_t i, state;
  uint16_t* star;
  int8_t sign;

  for (i=Rand() % 3; i<max_stars; i+=3) {
    star = stars+i;
    sign = ((*star >> 1) & 2) - 1;
    state = (*star & 3) + sign;
    // Set sign bit correctly for next round
    if ((state & 3) == 3) {
      *star &= 0XFFFB;
    } else if ((state & 3) == 0) {
      *star |= 4;
    }
    // Insert new state into star
    *star = (*star & 0xFFFC) | state;
  }
  DrawStars(stars);
  modified=true;
}

// vim:fdm=syntax:tabstop=2:softtabstop=2:shiftwidth=2:expandtab
