/*
 *   Copyright (C) 2019 All rights reserved.
 *
 *   FileName      ：err_use.c
 *   Author        ：yuefei.Chen
 *   Email         ：yfei777@outlook.com
 *   Date          ：2019年09月18日
 *   Description   ：
 */

#include "apue.h"
#include <errno.h>

int main(int argc,char *argv[])
{
	fprintf(stderr,"EACCES: %s\n",strerror(EACCES));
	errno= ENOENT;
	perror(argv[0]);
	exit(0);
}
