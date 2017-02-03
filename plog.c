#include "plog.h"

zlog_category_t* ftl_log;
zlog_category_t* err_log;
zlog_category_t* wrn_log;
zlog_category_t* dbg_log;
zlog_category_t* inf_log;
zlog_category_t* ntc_log;

void log_printf(unsigned int level, char *fmt, ...) {

	char line[8192];
	va_list ap;
	va_start(ap, fmt);
	vsnprintf(line, sizeof(line), fmt, ap);
	va_end(ap);

	switch (level) {
	case ZLOG_LEVEL_DEBUG:
		zlog_debug(dbg_log, line);
		break;
	case ZLOG_LEVEL_INFO:
		zlog_debug(dbg_log, line);
		break;
	case ZLOG_LEVEL_NOTICE:
		zlog_notice(ntc_log, line);
		break;
	case ZLOG_LEVEL_WARN:
		zlog_warn(wrn_log, line);
		break;
	case ZLOG_LEVEL_ERROR:
		zlog_error(err_log, line);
		break;
	case ZLOG_LEVEL_FATAL:
		zlog_fatal(ftl_log, line);
		break;
	default:
		break;
	}
}

/**
 * @brief 初始化日志配置
 *
 * @param logfile
 *
 * @return 
 */
/**
 * @brief 初始化日志配置
 *
 * @param logfile
 *
 * @return 
 */
bool config_zlog (char *logfile)
{
  // 程序日志初始化
  if (zlog_init(logfile)) 
  {
	printf("init program logfile failed: %s\n", logfile);
	return false;
  }

  ftl_log = zlog_get_category(LOG4C_CATEGORY_FTL);
  err_log = zlog_get_category(LOG4C_CATEGORY_ERR);
  wrn_log = zlog_get_category(LOG4C_CATEGORY_WRN);
  dbg_log = zlog_get_category(LOG4C_CATEGORY_DBG);
  inf_log = zlog_get_category(LOG4C_CATEGORY_INF);
  ntc_log = zlog_get_category(LOG4C_CATEGORY_NTC);

  zlog_debug(dbg_log, "日志配置初始化成功");

  return true;
}

