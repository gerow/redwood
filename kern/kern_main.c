#include <stddef.h>
#include <stdint.h>

#include "gnu/multiboot.h"
#include "redwood/term.h"
#include "redwood/util.h"

void kern_main(multiboot_info_t *boot_info) {
  term_clear();
  term_color(TERM_GREEN, TERM_BLACK);
  term_print("Hello, world!\n");
  term_print("Does it work if I do this?\n");
  char buf[128];
  snprintf(buf, sizeof(buf), "low memory size: %dk\n", boot_info->mem_lower);
  term_print(buf);
  snprintf(buf, sizeof(buf), "high memory size: %dk\n", boot_info->mem_upper);
  term_print(buf);
  snprintf(buf, sizeof(buf), "UINT32 hex is 0x%x\n", 0xdeadbeef);
  term_print(buf);
  /*
  for (int i = 0; i < 31; i++) {
    char buf[128];
    snprintf(buf, sizeof(buf), "Iteration %d\n", i);
    term_print(buf);
  }
  */
}
