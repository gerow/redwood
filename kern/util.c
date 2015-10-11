#include "redwood/util.h"

#include <stdint.h>

/* 
 * This includes enough room for a full 32 bit intger, a negative sign, and a
 * null character
 */
#define INT32_DEC_BUF_SIZE 12
#define UINT32_HEX_BUF_SIZE 9

void *memmove(void *dst, const void *src, size_t n) {
  uint8_t *u8_dst = dst;
  const uint8_t *u8_src = src;
  for (size_t i = 0; i < n; i++) {
    *u8_dst = *u8_src;
    u8_dst++;
    u8_src++;
  }

  return dst;
}

void *memcpy(void *dst, const void *src, size_t n) {
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

size_t strlen(const char *s) {
  size_t len = 0;
  while (*s != '\0') {
    len++;
    s++;
  }
  return len;
}

static char dec_ascii(int num) {
  if (num < 0 || num > 9) {
    return '?';
  }

  return '0' + num;
}

static int print_int32_dec(char str[INT32_DEC_BUF_SIZE], int32_t val) {
  int i = 0;
  int hit_nonzero = 0;
  if (val < 0) {
    str[i++] = '-';
    val = -val;
  }

  int32_t power = 1000000000;
  while (power != 0) {
    int num = val / power;
    if (num != 0) {
      hit_nonzero = 1;
    }
    if (hit_nonzero) {
      str[i++] = dec_ascii(num);
    }
    val = val - (num) * power;
    power /= 10;
  }
  str[i] = '\0';

  return i;
}

static char hex_ascii(int num) {
  if (num < 0 || num > 0xf) {
    return '?';
  }

  if (num >= 0xa) {
    return 'a' + (num - 0xa);
  }
  return '0' + num;
}

static int print_uint32_hex(char str[UINT32_HEX_BUF_SIZE], uint32_t val) {
  for (int i = 0; i < (int) sizeof(val) * 2; i++) {
    str[UINT32_HEX_BUF_SIZE - 2 - i] = hex_ascii(val & 0xf);
    val >>= 4;
  }
  str[UINT32_HEX_BUF_SIZE - 1] = '\0';

  return UINT32_HEX_BUF_SIZE;
}

void buf_append(char **buf, size_t *size, const char *str, size_t *size_needed) {
  size_t l = strlen(str);
  *size_needed += l;
  size_t to_copy = MIN(*size, l);
  memcpy(*buf, str, to_copy);
  *buf += to_copy;
  *size -= to_copy;
}

void buf_appendc(char **buf, size_t *size, char c, size_t *size_needed) {
  char str[] = {c, '\0'};
  buf_append(buf, size, str, size_needed);
}

int vsnprintf(char *str, size_t size, const char *format, va_list ap) {
  char *buf = str;
  size_t buf_size = size;
  size_t size_needed = 0;
  while (*format != '\0') {
    if (*format == '%') {
      format++;
      if (*format == '\0') {
        break;
      }
      if (*format == 'l') {
        /* Just be like... everything is long yo */
        format++;
      }
      switch (*format) {
        case 's': {
          const char *s = va_arg(ap, const char *);
          buf_append(&buf, &buf_size, s, &size_needed);
          break;
        }
        case 'd': {
          int d = va_arg(ap, int);
          char num[INT32_DEC_BUF_SIZE] = {0};
          print_int32_dec(num, d);
          buf_append(&buf, &buf_size, num, &size_needed);
          break;
        }
        case 'x': {
          uint32_t x = va_arg(ap, uint32_t);
          char num[UINT32_HEX_BUF_SIZE] = {0};
          print_uint32_hex(num, x);
          buf_append(&buf, &buf_size, num, &size_needed);
          break;
        }
        default: {
          buf_appendc(&buf, &buf_size, '?', &size_needed);
          break;
        }
      }
    } else {
      buf_appendc(&buf, &buf_size, *format, &size_needed);
    }
    format++;
  }

  if (buf_size != 0) {
    *buf = '\0';
  } else {
    str[size - 1] = '\0';
  }

  return size_needed;
}

int snprintf(char *str, size_t size, const char *format, ...) {
  va_list ap;
  va_start(ap, format);
  int rv = vsnprintf(str, size, format, ap);
  va_end(ap);
  return rv;
}

uint8_t inb(uint16_t addr) {
  uint8_t out = 0;

  asm volatile ("inb %1, %0\r\n"
                : "=r" (out)
                : "dN" (addr));

  return out;
}

uint16_t inw(uint16_t addr) {
  uint16_t out = 0;

  asm volatile ("inw %1, %0\r\n"
                : "=r" (out)
                : "dN" (addr));

  return out;
}

void outb(uint16_t addr, uint8_t val) {
  asm volatile ("outb %0, %1\r\n"
                : /* No output */
                : "r" (val), "dN" (addr));
}

void outw(uint16_t addr, uint16_t val) {
  asm volatile ("outw %0, %1\r\n"
                : /* No output */
                : "r" (val), "dN" (addr));
}

