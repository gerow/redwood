#include <stddef.h>
#include <stdint.h>

#include "redwood/term.h"

void kern_main() {
  term_clear();
  term_color(TERM_GREEN, TERM_BLACK);
  term_print("Hello, world!\n");
  term_print("Does it work if I do this?\n");
  char *c = "a";
  for (int i = 0; i < 31; i++) {
    term_print(c);
    term_print("\n");
    c[0]++;
  }
}
