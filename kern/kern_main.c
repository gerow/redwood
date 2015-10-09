#include <stddef.h>
#include <stdint.h>

#include "redwood/term.h"
#include "redwood/util.h"

void kern_main() {
  term_clear();
  term_color(TERM_GREEN, TERM_BLACK);
  term_print("Hello, world!\n");
  term_print("Does it work if I do this?\n");
  for (int i = 0; i < 31; i++) {
    char buf[128];
    snprintf(buf, sizeof(buf), "Iteration %d\n", i);
    term_print(buf);
  }
}
