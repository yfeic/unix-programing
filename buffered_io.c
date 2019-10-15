/*
 *   Copyright (C) 2019 All rights reserved.
 *
 *   FileName      ：buffered_io.c
 *   Author        ：yuefei.Chen
 *   Email         ：yfei777@outlook.com
 *   Date          ：2019年10月13日
 *   Description   ：
 */

#include "apue.h"

int main(void)
{
	char buf[MAXLINE];
	while(fgets(buf,MAXLINE,stdin)!=NULL)
		if(fputs(buf,stdout)==EOF)
			err_sys("output error");

	if(ferror(stdin))
		err_sys("input error");
	exit(0);
}
