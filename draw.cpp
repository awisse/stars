#include "defines.h"
#include "draw.h"
#include "platform.h"
#include "utils.h"

void DrawStars(uint16_t stars[max_stars]) {
  uint8_t i, x, y;
  uint16_t star;

  for (i=0; i<max_stars; i++) {
    star=stars[i];
    x = XPOS(star);
    y = YPOS(star);
    switch (star & 3) {
      case hidden:
        Platform::DrawFilledRect(x, y, 3, 3, COLOUR_BLACK);
        break;
      case dimmed:
        Platform::DrawFilledRect(x, y, 3, 3, COLOUR_BLACK);
        Platform::PutPixel(x + 1, y + 1);
        break;
      case halfdimmed:
        Platform::DrawLine(x + 1, y, x + 1, y + 2);
        Platform::DrawLine(x, y + 1, x + 2, y + 1);
        Platform::PutPixel(x + 1, y + 1, COLOUR_BLACK);
        break;
      case full:
        Platform::DrawLine(x + 1, y, x + 1, y + 2);
        Platform::DrawLine(x, y + 1, x + 2, y + 1);
    }
  }
}

//
// vim:fdm=syntax
