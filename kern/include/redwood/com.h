#ifndef REDWOOD_KERN_COM_H_
#define REDWOOD_KERN_COM_H_

#include <stdint.h>

#define COM1 0x3f8
#define COM2 0x2f8
#define COM3 0x3e8
#define COM4 0x2e8

int com_init();
int com_putc(uint16_t port, char c);
void com_print(uint16_t port, const char *s);

#endif /* REDWOOD_KERN_COM_H_ */
