#ifndef REDWOOD_KERN_LOG_H_
#define REDWOOD_KERN_LOG_H_

#ifndef LOG_PREFIX
#define LOG_PREFIX ""
#endif /* LOG_PREFIX */

enum log_level {
  LOG_DEBUG,
  LOG_INFO,
  LOG_WARNING,
  LOG_ERROR,
  LOG_FATAL,
};

void log_log(enum log_level level, char *message, ...)
  __attribute__ ((format (printf, 2, 3)));

#define log_debug(message) log_log(LOG_DEBUG, LOG_PREFIX message "\n")
#define log_info(message) log_log(LOG_INFO, LOG_PREFIX message "\n")
#define log_warning(message) log_log(LOG_WARNING, LOG_PREFIX message "\n")
#define log_error(message) log_log(LOG_ERROR, LOG_PREFIX message "\n")
#define log_fatal(message) log_log(LOG_FATAL, LOG_PREFIX message "\n")

#endif /* REDWOOD_KERN_LOG_H_ */
