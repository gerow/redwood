#include "redwood/util.h"

#include <stdint.h>

void *memmove(void *dst, void *src, size_t n) {
  uint8_t *u8_dst = dst;
  uint8_t *u8_src = src;
  for (size_t i = 0; i < n; i++) {
    *u8_dst = *u8_src;
    u8_dst++;
    u8_src++;
  }

  return dst;
}

void *memcpy(void *dst, void *src, size_t n) {
  return memmove(dst, src, n);
}

void *memset(void *b, int c, size_t len) {
  uint8_t *u8_b = b;
  for (size_t i = 0; i < len; i++) {
    *u8_b = c;
    u8_b++;
  }

  return b;
}
