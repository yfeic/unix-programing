/*
 *   Copyright (C) 2019 All rights reserved.
 *
 *   FileName      ：print_gid.c
 *   Author        ：yuefei.Chen
 *   Email         ：yfei777@outlook.com
 *   Date          ：2019年09月18日
 *   Description   ：
 */

#include "apue.h"


int main()
{
	printf("uid=%d,gid=%d\n",getuid(),getgid());
	exit(0);
}
