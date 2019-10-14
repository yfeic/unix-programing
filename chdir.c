/*
 *   Copyright (C) 2019 All rights reserved.
 *
 *   FileName      ：chdir.c
 *   Author        ：yuefei.Chen
 *   Email         ：yfei777@outlook.com
 *   Date          ：2019年10月07日
 *   Description   ：
 */

#include "apue.h"

int main(void)
{
	if(chdir("/tmp")<0)
	{
		err_sys("chdir faild");
	}

	printf("chdir to /tmp succeed\n");
	exit(0);
}
