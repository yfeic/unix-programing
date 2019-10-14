/*
 *   Copyright (C) 2019 All rights reserved.
 *
 *   FileName      ：copy.c
 *   Author        ：yuefei.Chen
 *   Email         ：yfei777@outlook.com
 *   Date          ：2019年09月19日
 *   Description   ：
 */

#include "apue.h"

#define BUFFSIZE 4096

int main(void)
{
	int n;
	char buf[BUFFSIZE];
	while((n=read(STDIN_FILENO,buf,BUFFSIZE))>0)
		if(write(STDOUT_FILENO,buf,n)!=n)
			err_sys("write error");
	if(n<0)
		err_sys("read error");
	exit(0);
}
