#ifndef REDWOOD_KERN_UTIL_H_

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

#define MIN(A, B) ((A) < (B) ? (A) : (B))
#define MAX(A, B) ((A) > (B) ? (A) : (B))

void *memmove(void *dst, const void *src, size_t n);
void *memcpy(void *dst, const void *src, size_t n);
void *memset(void *b, int c, size_t len);

size_t strlen(const char *s);

int vsnprintf(char *str, size_t size, const char *format, va_list ap);
int snprintf(char *str, size_t size, const char *format, ...)
  __attribute__ ((format (printf, 3, 4)));

uint8_t port_inb(uint16_t addr);
uint16_t port_inw(uint16_t addr);
void port_outb(uint16_t addr, uint8_t val);
void port_outw(uint16_t addr, uint16_t val);

#endif /* REDWOOD_KERN_UTIL_H_ */
