/*
 * =====================================================================================
 *
 *       Filename:  byte.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/03/2017 05:30:33 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef BYTE_H_
#define BYTE_H_

#include "plog.h"
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

/*
 * 数据的基本结构
 */
typedef struct byte_s_
{
	char *srcdata;       //原始数据的指针
	uint32_t srclen;     //原始数据的大小

	uint32_t curdata_begin;      //当前数据相对原始数据的开始位置的偏移，这个可以作为当前数据的指针相对原始数据的偏移量
	uint32_t curdata_end;        //当前数据相对原始数据的结束位置的偏移

} byte_s;

#endif
