#include <stddef.h>
#include <stdint.h>

#include "redwood/term.h"

void kern_main() {
  term_color(TERM_GREEN, TERM_BLACK);
  term_print("Hello, world!");
}
