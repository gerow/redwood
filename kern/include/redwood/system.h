#ifndef REDWOOD_KERN_SYSTEM_H_
#define REDWOOD_KERN_SYSTEM_H_

#include <stdint.h>

uint8_t port_inb(uint16_t addr);
uint16_t port_inw(uint16_t addr);
void port_outb(uint16_t addr, uint8_t val);
void port_outw(uint16_t addr, uint16_t val);

#endif /* REDWOOD_KERN_SYSTEM_H_ */
