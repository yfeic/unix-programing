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

extern int log_to_stderr;

static void log_doit(int,int,int,const char *,va_list ap);

/*
 *Error routines for programs that can run as a daemon.
 */


/*
 * Initialize syslog(),if running as daemon.
 */
void log_open(const char *ident,int option,int facility)
{
	if(log_to_stderr==0)
		openlog(ident,option,facility);
}

/*
 * Nonfatal error related to a system call,
 * Print a message with the system's errno value and return.
 */
void log_ret(const char *fmt,...)
{
	va_list ap;
	va_start(ap,fmt);
	log_doit(1,errno,LOG_ERR,fmt,ap);
	va_end(ap);
}

/*
 * Fatal error related to a system call.
 * Print a message and terminate.
 */
void log_sys(const char *fmt,...)
{
	va_list ap;
	va_start(ap,fmt);
	log_doit(1,errno,LOG_ERR,fmt,ap);
	va_end(ap);
	exit(2);
}

/*
 * Nonfatal error unrelated to a system call.
 * Print a message and return.
 */
void log_msg(const char *fmt,...)
{
	va_list ap;
	va_start(ap,fmt);
	log_doit(0,0,LOG_ERR,fmt,ap);
	va_end(ap);
}

/*
 * Fatal error unrelated to system call.
 * Print a message and terminate.
 */
void log_quit(const char *fmt,...)
{
	va_list ap;
	va_start(ap,fmt);
	log_doit(0,0,LOG_ERR,fmt,ap);
	va_end(ap);
	exit(2);
}

/*
 * Fatal error related to a system call.
 * Error number passed as an explicit parameter.
 * Print a messagee and terminate. 
 */
void log_exit(int error,const char *fmt,...)
{
	va_list ap;
	va_start(ap,fmt);
	log_doit(1,error,LOG_ERR,fmt,ap);
	va_end(ap);
	exit(2);
}

/*
 * Print a message and return to caller.
 * Caller specifies "errnoflag" and "priority"
 */
static void log_doit(int errnoflag,int error,int priority,const char *fmt,va_list ap)
{
	char buf[MAXLINE];

	vsnprintf(buf,MAXLINE-1,fmt,ap);

	if(errnoflag)
		snprintf(buf+strlen(buf),MAXLINE-strlen(buf)-1,":%s",strerror(error));
	strcat(buf,"\n");
	if(log_to_stderr)
	{
		fflush(stdout);
		fputs(buf,stderr);
		fflush(stderr);
	}
	else{
		syslog(priority,"%s",buf);
	}
}
