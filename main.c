/*
 * main.c
 *
 *  Created on: Feb 3, 2017
 *      Author: root
 */
#include "byte.h"

void test(byte_s *srcbyte)
{
	char ch = 0;
    uint32_t iterator = 0;
	for (iterator = 0; iterator < srcbyte->srclen; iterator++)
	{
		ch = get_byte_char (srcbyte, iterator);
//		zlog_info(inf_log, "get_byte_1 num:%c", ch);
	}

}

void speed ()
{
	uint32_t count = 1234567890;
	char *str = "1234";
	int num = 0;
	while (count--)
	{
        memcpy (&num, str, 4);
	}
}


void speed2 ()
{
	uint32_t count = 1234567890;
	char *str = "1234";
	byte_s srcbyte;
	memset (&srcbyte, 0, sizeof(byte_s));

	byte_s result;
	memset (&result, 0, sizeof(byte_s));

	srcbyte.srcdata = str;
	srcbyte.srclen = strlen(str);
	while (count--)
	{
		 read_byte (&srcbyte, srcbyte.srclen, &result);
	}
}

int main()
{
	config_zlog ("zlog.conf");

	char *str = "123456789abc";

	byte_s srcbyte;
	memset (&srcbyte, 0, sizeof(byte_s));

	srcbyte.srcdata = str;
	srcbyte.srclen = strlen(str);

	speed2 ();
//	test(&srcbyte);


	return 0;
}
