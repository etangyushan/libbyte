#ifndef PLOG_H_
#define PLOG_H_

#include <zlog.h>
#include <stdbool.h>

#define LOG4C_CATEGORY_FTL "FTL"
#define LOG4C_CATEGORY_ERR "ERR"
#define LOG4C_CATEGORY_WRN "WRN"
#define LOG4C_CATEGORY_DBG "DBG"
#define LOG4C_CATEGORY_INF "INF"
#define LOG4C_CATEGORY_NTC "NTC"

extern zlog_category_t* ftl_log;
extern zlog_category_t* err_log;
extern zlog_category_t* wrn_log;
extern zlog_category_t* dbg_log;
extern zlog_category_t* inf_log;
extern zlog_category_t* ntc_log;

void log_printf(unsigned int level, char *fmt, ...);

/**
 * @brief 初始化日志配置
 *
 * @param logfile
 *
 * @return 
 */
bool config_zlog (char *logfile);

#endif /* PLOG_H_ */
