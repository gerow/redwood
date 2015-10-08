#ifndef REDWOOD_KERN_UTIL_H_

#include <stddef.h>

void *memmove(void *dst, const void *src, size_t n);
void *memcpy(void *dst, const void *src, size_t n);
void *memset(void *b, int c, size_t len);

#endif /* REDWOOD_KERN_UTIL_H_ */
