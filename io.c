/*
 *   Copyright (C) 2019 All rights reserved.
 *
 *   FileName      ：io.c
 *   Author        ：yuefei.Chen
 *   Email         ：yfei777@outlook.com
 *   Date          ：2019年09月18日
 *   Description   ：
 */

#include "apue.h"

#define BUFFERSIZE 4096

int main(void)
{
	if(0)
	{
		//不带缓冲的I/O
		int n;
		char buf[BUFFERSIZE];

		while((n=read(STDIN_FILENO,buf,BUFFERSIZE))>0)
			if(write(STDOUT_FILENO,buf,n)!=n)
				err_sys("write error");
		if(n<0)
			err_sys("read error");
		exit(0);
	}
	else
	{
		//标准I/O
		int c;

		while((c=getc(stdin))!=EOF)
			if(putc(c,stdout)==EOF)
				err_sys("output error");
		if(ferror(stdin))
			err_sys("input error");
		exit(0);
	}
}
