#include <stddef.h>
#include <stdint.h>

#include "gnu/multiboot.h"
#include "redwood/com.h"
#include "redwood/mm.h"
#include "redwood/term.h"
#include "redwood/util.h"

void kern_main(multiboot_info_t *boot_info) {
  term_clear();
  term_color(TERM_GREEN, TERM_BLACK);
  term_print("Booting\n");
  term_print("Initializing memory manager\n");
  if (mm_init(boot_info)) {
    term_print("Failed to initialize memory manager\n");
    return;
  }

  com_init();
  com_print(COM1, "Hello COM1!\n");
  return;
}
