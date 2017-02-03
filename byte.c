/*
 * =====================================================================================
 *
 *       Filename:  byte.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/03/2017 05:30:38 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "byte.h"

/*
 * 检测数据的有效性
 */
bool byte_check_validity (byte_s *bytedata)
{
	if (NULL == bytedata)
	{
		zlog_error(err_log, "call bytedata NULL error");
		return false;
	}

	if (NULL == bytedata->srcdata)
	{
		zlog_error(err_log, "call bytedata->srcdata NULL error");
		return false;
	}

	if (bytedata->end < bytedata->begin)
	{
		zlog_error(err_log, "read too long error");
		return false;
	}

	if (bytedata->end >= bytedata->srclen)
	{
		zlog_error(err_log, "read too long error");
		return false;
	}

	return true;
}

/*
 * 读取指定长度的字节数据
 */
bool read_byte (byte_s *srcbyte, uint32_t len, byte_s *result)
{
	if (NULL == srcbyte)
	{
		zlog_error(err_log, "call srcbyte NULL error");
		return false;
	}

	if (NULL == result)
	{
		zlog_error(err_log, "call result NULL error");
		return false;
	}

	*result = *srcbyte;
	result->end = result->begin + len;

	if (result->end >= srcbyte->srclen)
	{
		zlog_error(err_log, "read too long error");
		return false;
	}

    return true;
}


uint8_t get_byte_1 (byte_s *bytedata)
{
	if (false == byte_check_validity (bytedata))
	{
		zlog_error(err_log, "call byte_check_validity error");
		return 0;
	}
    return (uint8_t)bytedata->srcdata[bytedata->begin];
}

uint16_t get_byte_2 (byte_s *bytedata)
{
	if (false == byte_check_validity (bytedata))
	{
		zlog_error(err_log, "call byte_check_validity error");
		return 0;
	}
    return (uint16_t)bytedata->srcdata[bytedata->begin];
}


uint32_t get_byte_4 (byte_s *bytedata)
{
	if (false == byte_check_validity (bytedata))
	{
		zlog_error(err_log, "call byte_check_validity error");
		return 0;
	}
    return (uint32_t)bytedata->srcdata[bytedata->begin];
}
