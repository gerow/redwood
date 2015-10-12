#include "redwood/com.h"

#include "redwood/util.h"

/* Offsets */
#define DATA 0
#define INTERRUPTS 1
/* This is a word size and needs DLAB set to use. */
#define DIVISOR 0
#define FIFO 2
#define LINE_CONTROL 3
#define MODEM_CONTROL 4
#define LINE_STATUS 5
#define MODEM_STATUS 6
#define SCRATCH 7

static int transmit_ready(uint16_t port) {
  return port_inb(port + LINE_STATUS) & 0x20;
}

int com_init() {
  port_outb(COM1 + INTERRUPTS, 0); /* Disable interrupts. */
  port_outb(COM1 + LINE_CONTROL, 0x80); /* Turn on DLAB. */
  port_outw(COM1 + DIVISOR, 1); /* Set to 115200 baud. */
  port_outb(COM1 + LINE_CONTROL, 0x03); /* 8 bits no parity one stop bit. */
  port_outb(COM1 + FIFO, 0xc7); /* Turn on fifo (by some magic). */
  port_outb(COM1 + MODEM_CONTROL, 0x0b);

  return 0;
}

int com_putc(uint16_t port, char c) {
  while (!transmit_ready(port));
  port_outb(port, c);

  return 0;
}

void com_print(uint16_t port, const char *s) {
  while (*s != '\0') {
    com_putc(port, *s);
    s++;
  }
}
