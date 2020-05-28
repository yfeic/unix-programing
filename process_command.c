/*
 *   Copyright (C) 2019 All rights reserved.
 *
 *   FileName      ：process_command.c
 *   Author        ：yuefei.Chen
 *   Email         ：yfei777@outlook.com
 *   Date          ：2019年09月18日
 *   Description   ：
 */

#include "apue.h"
#include <sys/wait.h>

int main(void)
{
	char buf[MAXLINE];
	pid_t pid;
	int status;

	printf("%% ");
	while(fgets(buf,MAXLINE,stdin)!=NULL)
	{
		if(buf[strlen(buf)-1]=='\n')
			buf[strlen(buf)-1]=0; //replace newline with null
		if((pid=fork())<0)
		{
			err_sys("fork error");
		}
		else if(pid==0)
		{
			execlp(buf,buf,(char *)0);
			err_ret("couldn't execute: %s",buf);
			exit(127);
		}

		if((pid=waitpid(pid,&status,0))<0)
			err_sys("waitpid error");
		printf("%% ");
	}

	exit(0);
}
