/*
 *   Copyright (C) 2019 All rights reserved.
 *
 *   FileName      ：futimens.c
 *   Author        ：yuefei.Chen
 *   Email         ：yfei777@outlook.com
 *   Date          ：2019年09月28日
 *   Description   ：
 */


#include "apue.h"
#include <fcntl.h>

int main(int argc,char *argv[])
{
	int i,fd;
	struct stat statbuf;
	struct timespec times[2];

	for(i=1;i<argc;i++)
	{
		if(stat(argv[1],&statbuf)<0)
		{
			/* fetch current time */
			err_ret("%s: stat error",argv[i]);
			continue;
		}

		if((fd=open(argv[i],O_RDWR|O_TRUNC))<0)
		{
			/* truncate */
			err_ret("%s: open error",argv[i]);
			continue;
		}

		times[0] =statbuf.st_atim;
		times[1] =statbuf.st_mtim;

		if(futimens(fd,times)<0)
		{
			err_ret("%s: futimens error",argv[1]);
			close(fd);
		}
	}

	exit(0);
}
