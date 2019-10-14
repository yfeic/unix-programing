/*
 *   Copyright (C) 2019 All rights reserved.
 *
 *   FileName      ：exception.c
 *   Author        ：yuefei.Chen
 *   Email         ：yfei777@outlook.com
 *   Date          ：2019年09月17日
 *   Description   ：
 */

#include "apue.h"
#include <errno.h>
#include <stdarg.h>
#include <syslog.h>

static void err_doit(int,int,const char *,va_list);


/*
 * Nonfatal error related to a system call.
 * print a message and return.
 */
void err_ret(const char *fmt,...)
{
	va_list ap;
	va_start(ap,fmt);
	err_doit(1,errno,fmt,ap);
	va_end(ap);
}

/*
 * Fatal error related to a system call
 * print a message and terminate.
 */
void err_sys(const char *fmt,...)
{
	va_list ap;
	va_start(ap,fmt);
	err_doit(1,errno,fmt,ap);
	va_end(ap);
	exit(1);
}

/*
 * Nonfatal error unrelated to a system call.
 * Error code passed as explict parameter.
 * print a message and return.
 */
void err_cont(int error,const char *fmt,...)
{
	va_list ap;
	va_start(ap,fmt);
	err_doit(1,error,fmt,ap);
	va_end(ap);
}

/*
 * Fatal error unrelated to a system call.
 * Error code passed as explict arameter.
 * print a message and terminate.
 */
void err_exit(int error,const char *fmt,...)
{
	va_list ap;
	va_start(ap,fmt);
	err_doit(1,error,fmt,ap);
	va_end(ap);
	exit(1);
}

/*
 * Fatal error related to a system call.
 * Print a message,dump core,and terminate.
 */
void err_dump(const char *fmt,...)
{
	va_list ap;
	va_start(ap,fmt);
	err_doit(1,errno,fmt,ap);
	va_end(ap);
	abort();	//dump core and terminate 
	exit(1);
}

/*
 * Nonfatal error unrelated to a system call.
 * print a message and return.
 */
void err_msg(const char *fmt,...)
{
	va_list ap;
	va_start(ap,fmt);
	err_doit(0,0,fmt,ap);
	va_end(ap);
}

/*
 * Fatal error unrelated tto a system call.
 * Print a message and terminate.
 */
void err_quit(const char *fmt,...)
{
	va_list ap;
	va_start(ap,fmt);
	err_doit(0,0,fmt,ap);
	va_end(ap);
	exit(1);
}

/*
 * Print a message and retuen to caller.
 * Caller specifiles "errnoflag"
 */
static void err_doit(int errnoflag,int error,const char *fmt,va_list ap)
{
	char buf[MAXLINE];
	vsnprintf(buf,MAXLINE-1,fmt,ap);
	if(errnoflag)
		snprintf(buf+strlen(buf),MAXLINE-strlen(buf)-1,":%s",strerror(error));
	strcat(buf,"\n");
	fflush(stdout);
	fputs(buf,stderr);
	fflush(NULL);
}

