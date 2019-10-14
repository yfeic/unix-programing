/*
 *   Copyright (C) 2019 All rights reserved.
 *
 *   FileName      ：hole.c
 *   Author        ：yuefei.Chen
 *   Email         ：yfei777@outlook.com
 *   Date          ：2019年09月19日
 *   Description   ：
 */

#include "apue.h"
#include <fcntl.h>

char buf1[] ="abcdefghij";
char buf2[] ="ABCDEFGHIJ";

int main(void)
{
	int fd;
	if((fd=creat("file.hole",FILE_MODE))<0)
		err_sys("create error");
	if(write(fd,buf1,10)!=10)
		err_sys("buf1 write error");
	//offset now is 10
	
	if(lseek(fd,16384,SEEK_SET)==-1)
		err_sys("lseek error");
	//offset now is 16384
	
	if(write(fd,buf2,10)!=10)
		err_sys("buf2 write error");
	//offset now is 16394
	
	exit(0);
}

