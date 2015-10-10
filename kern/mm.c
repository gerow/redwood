#include "redwood/mm.h"

#include <stdint.h>

#include "redwood/term.h"

int mm_init(multiboot_info_t *boot_info) {
  if (!(boot_info->flags & MULTIBOOT_INFO_MEMORY)) {
    term_print("Boot info memory entries invalid, bailing out\n");
    return -1;
  }
  term_printf("Upper memory %dk\n", boot_info->mem_upper);
  term_printf("Lower memory %dk\n", boot_info->mem_upper);

  if (!(boot_info->flags & MULTIBOOT_INFO_MEM_MAP)) {
    term_print("Boot info mem map invalid, bailing out\n");
    return -1;
  }
  multiboot_uint32_t mmap_addr = boot_info->mmap_addr;
  multiboot_uint32_t mmap_end = mmap_addr + boot_info->mmap_length;
  while (mmap_addr < mmap_end) {
    multiboot_memory_map_t *mmap_entry = (void *)mmap_addr;
    uint32_t start = mmap_entry->addr;
    uint32_t len = mmap_entry->len;
    term_printf("Section 0x%x to 0x%x\n", start, start + len);
    term_printf("Entry size %d\n", mmap_entry->size);

    mmap_addr += mmap_entry->size;
  }

  return 0;
}
