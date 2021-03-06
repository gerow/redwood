#ifndef REDWOOD_KERN_LIBC_H_
#define REDWOOD_KERN_LIBC_H_

#include <stdarg.h>
#include <stddef.h>

void *memmove(void *dst, const void *src, size_t n);
void *memcpy(void *dst, const void *src, size_t n);
void *memset(void *b, int c, size_t len);

size_t strlen(const char *s);

int vsnprintf(char *str, size_t size, const char *format, va_list ap);
int snprintf(char *str, size_t size, const char *format, ...)
  __attribute__ ((format (printf, 3, 4)));

#endif /* REDWOOD_KERN_LIBC_H_ */
