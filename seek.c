/*
 *   Copyright (C) 2019 All rights reserved.
 *
 *   FileName      ：seek.c
 *   Author        ：yuefei.Chen
 *   Email         ：yfei777@outlook.com
 *   Date          ：2019年09月19日
 *   Description   ：
 */

#include "apue.h"

int main(void)
{
	if(lseek(STDIN_FILENO,0,SEEK_CUR)==-1)
		printf("can not seek\n");
	else
		printf("seek OK\n");
	exit(0);
}
