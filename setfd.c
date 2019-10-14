/*
 *   Copyright (C) 2019 All rights reserved.
 *
 *   FileName      ：setfd.c
 *   Author        ：yuefei.Chen
 *   Email         ：yfei777@outlook.com
 *   Date          ：2019年09月22日
 *   Description   ：
 */

#include "apue.h"
#include <fcntl.h>

void set_fd(int fd,int flags)// flags are file status flags to turn on
{
	int val;

	if((val=fcntl(fd,FGETFL,0))<0)
		err_sys("fcntl F_GETFL error");

	val |=flags;	//turn on flags
	//var &=~flags //turn off flags

	if(fcntl(fd,FSETFL,val)<0)
		err_sys("fcntl F_SETFL error");
}
