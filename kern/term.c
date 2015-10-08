#include "redwood/term.h"

#include <stdint.h>

#include "redwood/util.h"

static const int COLS = 80;
static const int ROWS = 25;

static uint16_t *buf = (uint16_t *)0xb8000;
int row = 0;
int col = 0;
/* White foreground, black background. */
uint8_t color = TERM_WHITE | TERM_BLACK << 4;

static void scroll_line() {
  memmove(buf, buf + COLS, ((ROWS - 1) * COLS) * sizeof(*buf));
  col = 0;
  row--;
  memset(buf + (COLS * ROWS - 1), 0, COLS * sizeof(*buf));
}

static void write_char(char c) {
  if (col >= COLS) {
    col = 0;
    row++;
  }
  if (row >= ROWS) {
    scroll_line();
  }

  if (c == '\n') {
    col = 0;
    row++;
  } else {
    buf[row * COLS + col] = c | color << 8;
    col++;
  }
}

void term_color(int fg, int bg) {
  color = fg | bg << 4;
}

void term_print(char *buf) {
  while (*buf != '\0') {
    write_char(*buf);
    buf++;
  }
}

void term_clear() {
  memset(buf, 0, COLS * ROWS);
  row = 0;
  col = 0;
  color = TERM_WHITE | TERM_BLACK << 4;
}
