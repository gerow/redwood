#ifndef REDWOOD_KERN_TERM_H_
#define REDWOOD_KERN_TERM_H_

enum term_color {
  TERM_BLACK = 0,
  TERM_BLUE = 1,
  TERM_GREEN = 2,
  TERM_CYAN = 3,
  TERM_RED = 4,
  TERM_MAGENTA = 5,
  TERM_BROWN = 6,
  TERM_LIGHT_GREY = 7,
  TERM_DARK_GREY = 8,
  TERM_LIGHT_BLUE = 9,
  TERM_LIGHT_GREEN = 10,
  TERM_LIGHT_CYAN = 11,
  TERM_LIGHT_RED = 12,
  TERM_LIGHT_MAGENTA = 13,
  TERM_LIGHT_BROWN = 14,
  TERM_WHITE = 15,
};

void term_color(int fg, int bg);
void term_print(char *buf);

#endif /* REDWOOD_KERN_TERM_H_ */
