#include "redwood/log.h"

#include <stdarg.h>

#include "redwood/com.h"
#include "redwood/libc.h"

static enum log_level current_level = LOG_DEBUG;

void log_log(enum log_level level, char *message, ...) {
  if (level < current_level) {
    return;
  }

  /*
   * This is a hack. We need to write a version of printf that can just use a
   * putc function.
   */
  char buf[256];

  va_list ap;
  va_start(ap, message);
  int rv = vsnprintf(buf, sizeof(buf), message, ap);
  va_end(ap);

  if (rv < 0) {
    com_print(COM1, "LOG_H: Failed to print :sadface\n");
    return;
  }

  com_print(COM1, buf);
}
