/*
 *   Copyright (C) 2020 All rights reserved.
 *
 *   FileName      ：mkstmp.c
 *   Author        ：yuefei.Chen
 *   Email         ：yfei777@outlook.com
 *   Date          ：2020年05月28日
 *   Description   ：
 */
#include "apue.h"
#include <errno.h>

void make_temp(char *template);

int main(void){
	char good_template[]="/tmp/dirXXXXXX";//right
	char *bad_template="/tmp/dirXXXXXX"; //wrong
	
	printf("trying to create first temp file...\n");
	make_temp(good_template);

	printf("trying to create second temp file...\n");
	make_temp(bad_template);

	exit(0);
}

void make_temp(char *template){
	int fd;
	struct stat sbuf;

	if((fd=mkstemp(template))<0){
		err_sys("can't create tempfile");
	}
	printf("tempname =%s\n",template);
	close(fd);
	if(stat(template,&sbuf)<0){
		if(errno==ENOENT){
			printf("file doesn't exist\n");
		}else{
			err_sys("stat failed");
		}
	}else{
		printf("file exists\n");
		unlink(template);
	}
}
