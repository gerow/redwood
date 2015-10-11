#include "redwood/mm.h"

#include <stdint.h>

#include "redwood/term.h"

int mm_init(multiboot_info_t *boot_info) {
  if (!(boot_info->flags & MULTIBOOT_INFO_MEMORY)) {
    term_print("Boot info memory entries invalid, bailing out\n");
    return -1;
  }
  term_printf("Upper memory %dk\n", boot_info->mem_upper);
  term_printf("Lower memory %dk\n", boot_info->mem_lower);

  if (!(boot_info->flags & MULTIBOOT_INFO_MEM_MAP)) {
    term_print("Boot info mem map invalid, bailing out\n");
    return -1;
  }
  multiboot_memory_map_t *mmap = (void *)boot_info->mmap_addr;
  term_print("Memory map:\n");
  while ((multiboot_uint32_t)mmap < boot_info->mmap_addr + boot_info->mmap_length) {
    const char *type =
      mmap->type == MULTIBOOT_MEMORY_AVAILABLE ? "Available" : "Reserved ";
    /* 
     * These are technically 64-bit values, so we need to convert them before passing 
     * them to printf
     */
    uint32_t start = mmap->addr;
    uint32_t len = mmap->len;
    term_printf("  %s [0x%lx - 0x%lx]\n", type, start, start + len);
    mmap = (void *)((uintptr_t)mmap + mmap->size + 4);
  }

  return 0;
}
