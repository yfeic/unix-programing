/*
 *   Copyright (C) 2019 All rights reserved.
 *
 *   FileName      ：getcwd.c
 *   Author        ：yuefei.Chen
 *   Email         ：yfei777@outlook.com
 *   Date          ：2019年10月08日
 *   Description   ：
 */

#include "apue.h"

int main(void)
{
	char *ptr;
	size_t size;

	if(chdir("/tmp")<0)
	{
		err_sys("chdir faild");
	}

	ptr=path_alloc(&size);

	if(getcwd(ptr,size)==NULL)
	{
		err_sys("getcwd faild");
	}
	printf("cwd=%s\n",ptr);
	exit(0);
}
