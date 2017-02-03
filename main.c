/*
 * main.c
 *
 *  Created on: Feb 3, 2017
 *      Author: root
 */
#include "byte.h"

int main()
{
	config_zlog ("zlog.conf");

	char *str = "123456789abc";

	byte_s srcbyte;
	memset (&srcbyte, 0, sizeof(byte_s));

//	byte_s result;
//	memset (&result, 0, sizeof(byte_s));

	srcbyte.srcdata = str;
	srcbyte.srclen = strlen(str);

	get_byte_1 (&srcbyte);
	return 0;
}
