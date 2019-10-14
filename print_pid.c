/*
 *   Copyright (C) 2019 All rights reserved.
 *
 *   FileName      ：print_pid.c
 *   Author        ：yuefei.Chen
 *   Email         ：yfei777@outlook.com
 *   Date          ：2019年09月18日
 *   Description   ：
 */
#include "apue.h"

int main(void)
{
	printf("helo world from process ID %ld\n",(long)getpid());
	exit(0);
}
