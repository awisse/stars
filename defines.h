#pragma once

// Platform dependant definitions
#ifndef ARDUINO
#include <stdint.h>
#include <string.h>
#define PROGMEM
#define PSTR
#define pgm_read_byte(x) *(x)
#define pgm_read_word(x) (*((uint16_t*)x))
#define pgm_read_ptr(x) (*((uintptr_t*)x))
#define strlen_P(x) strlen(x)
#else
#include <avr/pgmspace.h>
//#define pgm_read_ptr pgm_read_word
#endif

#define DEV_DEB

// Conversions
#define U8 (uint8_t*)
#define U16 (uint16_t)
#define I16 (int16_t)

// Game Parameters
#define FRAME_RATE 30
#define FRAME_STEP U16(FRAME_RATE / 10)
#define MAX_STARS 64
#define STAR_DELAY 500

// Mathematical constants

// Functions
#define XPOS(x) ((x >> 3) & 0x7F)
#define YPOS(x) ((x >> 10) & 0x3F)

// Message Dimensions (Middle of the screen)
#define MSG_X 40
#define MSG_Y 24
#define MSG_W 48
#define MSG_H 16

// Screen Dimensions
#define DISPLAY_WIDTH 128
#define DISPLAY_HEIGHT 64

#define COLOUR_BLACK 0
#define COLOUR_WHITE 1
#define INVERT 2

// Buttons
#define INPUT_LEFT 32u
#define INPUT_RIGHT 64u
#define INPUT_UP 128u
#define INPUT_DOWN 16u
#define INPUT_A 8u
#define INPUT_B 4u

// Time
#define LONG_PRESS 2000
// vim:ft=cpp
