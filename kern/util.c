#include "redwood/util.h"

#include <stdint.h>

/* 
 * This includes enough room for a full 32 bit intger, a negative sign, and a
 * null character
 */
#define INT32_BUF_SIZE 12

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

static char num_ascii(int num) {
  if (num < 0 || num > 9) {
    return '?';
  }

  return '0' + num;
}

static int print_int32(char str[INT32_BUF_SIZE], int32_t val) {
  int i = 0;
  if (val < 0) {
    str[i++] = '-';
    val = -val;
  }

  int32_t power = 1000000000;
  while (power != 0) {
    int num = val / power;
    str[i++] = num_ascii(num);
    val = val - (num) * power;
    power /= 10;
  }
  str[i] = '\0';

  return i;
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
  char str[2] = {c, '\0'};
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
      switch (*format) {
        case 's': {
          const char *s = va_arg(ap, const char *);
          buf_append(&buf, &buf_size, s, &size_needed);
          break;
        }
        case 'd': {
          int d = va_arg(ap, int);
          char num[INT32_BUF_SIZE] = {0};
          print_int32(num, d);
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

  buf_appendc(&buf, &buf_size, *format, &size_needed);
  /* 
   * According to the spec this shouldn't include the size needed for the null
   * character.
   */
  size_needed--;

  /* Ensure we always end with a null char. */
  str[size - 1] = '\0';

  return size_needed;
}

int snprintf(char *str, size_t size, const char *format, ...) {
  va_list ap;
  va_start(ap, format);
  int rv = vsnprintf(str, size, format, ap);
  va_end(ap);
  return rv;
}
