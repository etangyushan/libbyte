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
	char *srcdata;  //原始数据的指针
//	char *curdata;  //当前数据的指针
	uint32_t begin;      //相对原始数据的偏移位置，这个可以作为当前数据的指针相对原始数据的偏移量
	uint32_t end;        //相对原始数据的偏移位置
	uint32_t curoffset;  //当前已经处理的数据相对原始数据的偏移
//	uint32_t size;       //总的字节数，end - begin，减法比较耗时需要考虑
	uint32_t srclen;     //原始数据的大小
} byte_s;

#endif
