#include "redwood/term.h"

#include <stdint.h>

static const int COLS = 80;
static const int ROWS = 25;

static uint16_t *buf = (uint16_t *)0xb8000;
int row = 0;
int col = 0;
/* White foreground, black background. */
uint8_t color = TERM_WHITE | TERM_BLACK << 4;

void term_color(int fg, int bg) {
  color = fg | bg << 4;
}

static void write_char(char c) {
  buf[row * COLS + col] = c | color << 8;
  col++;
  if (col > COLS) {
    col = 0;
    row++;
  }
}

void term_print(char *buf) {
  while (*buf != '\0') {
    write_char(*buf);
    buf++;
  }
}
