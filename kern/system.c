#include "redwood/system.h"

uint8_t port_inb(uint16_t addr) {
  uint8_t out = 0;

  asm volatile ("inb %1, %0\r\n"
                : "=r" (out)
                : "dN" (addr));

  return out;
}

uint16_t port_inw(uint16_t addr) {
  uint16_t out = 0;

  asm volatile ("inw %1, %0\r\n"
                : "=r" (out)
                : "dN" (addr));

  return out;
}

void port_outb(uint16_t addr, uint8_t val) {
  asm volatile ("outb %0, %1\r\n"
                : /* No output */
                : "r" (val), "dN" (addr));
}

void port_outw(uint16_t addr, uint16_t val) {
  asm volatile ("outw %0, %1\r\n"
                : /* No output */
                : "r" (val), "dN" (addr));
}
