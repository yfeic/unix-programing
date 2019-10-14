/*
 * our own header,to be included before all standard system headers.
 */

#ifndef _APUE_H
#define _APUE_H

#define _POSIX_C_SOURCE 200809L

#if defined(SOLARIS)    	/* Solaris 10*/
#define _XOPEN_SOURCE 600
#else
#define _XOPEN_SOURCE 700
#endif

#include <sys/types.h> 		/* some systems still requires this*/
#include <sys/stat.h>
#include <sys/termios.h> 	/*for winsize*/

#if defined(MACOS) || !defined(TIOCGWINSZ)
#include <sys/ioctl.h>
#endif

#include <stdio.h>		/* for convenience */
#include <stdlib.h>		/* for convenience */
#include <stddef.h>		/* for offsetof */
#include <string.h>		/* for convenience */
#include <unistd.h>		/* for convenience */
#include <signal.h>		/* for SIG_ERR */

#define MAXLINE 4096 		/* max line length */

/*
 * Default file access permissions for new files 
 */

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IXGRP | S_IXOTH)

/*
 * Default permisssions for new directories
 */

#define DIR_MODE (FILE_MODE | S_IXUSR | S_IXGRP | S_IXOTH)

typedef void Sigfunc(int);/* for signal handlers */

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))



/*
 *prototypes for our own functions
 */

char *path_alloc(size_t *);  	//2.16
long open_max(void); 		//2.17

int set_cloexec(int);		//13.9
void clr_fl(int,int);
void set_fl(int,int);		//3.12

void pr_exit(int);		//8.5

void pr_mask(const char *);	//10.14

Sigfunc *signal_intr(int,Sigfunc *);	//10.19

void daemonize(const char *);		//13.1

void sleep_us(unsigned int);		//14.5
ssize_t readn(int,void *,size_t);	//14.24
ssize_t writen(int,const void *,size_t);	//14.24

int fd_pipe(int *);			//17.2
int recv_fd(int,ssize_t (*func)(int,const void *,size_t));	//17.14
int send_fd(int,int);			//17.13
int send_err(int,int,const char *);	//17.12
int serv_listen(const char *);		//17.8
int serv_accept(int,uid_t *);		//17.9

int cli_conn(const char *);		//17.10
int buf_args(char *,int (*func)(int,char **));	//17.23

int tty_cbreak(int);	//18.20
int tty_raw(int);	//18.20
int tty_reset(int);	//18.20
void tty_atexit(void); 	//18.20
struct termios *tty_termios(void);	//18.20

int ptym_open(char *,int);	//19.9
int ptys_open(char *);		//19.9

#ifdef TIOCCGWINSZ
pid_t pty_fork(int *,char *,int, const struct termios *,const struct winsize *);
#endif

int lock_reg(int,int,int,off_t,int,off_t); 	//14.5

#define read_lock(fd,offset,whence,len)  lock_reg((fd),F_SETLK,F_RDLCK,(offset),(whence),(len))
#define readw_lock(fd,offset,whence,len)  lock_reg((fd),F_SETLKW,F_RDLCK,(offset),(whence),(len))
#define write_lock(fd,offset,whence,len)  lock_reg((fd),F_SETLK,F_WRLCK,(offset),(whence),(len))
#define writew_lock(fd,offset,whence,len)  lock_reg((fd),F_SETLKW,F_WRLCK,(offset),(whence),(len))
#define un_lock(fd,offset,whence,len)  lock_reg((fd),F_SETLK,F_UNLCK,(offset),(whence),(len))

pid_t lock_test(int,int,off_t,int,off_t);	//14.6

#define is_read_lockable(fd,offset,whence,len)  (locktest((fd),F_RDLCK,(offset),(whence),(len))==0)
#define is_write_lockable(fd,offset,whence,len)  (locktest((fd),F_WRLCK,(offset),(whence),(len))==0)

void err_msg(const char *,...);
void err_dump(const char *,...) __attribute__((noreturn));
void err_quit(const char *,...) __attribute__((noreturn));
void err_cont(int,const char *,...);
void err_exit(int,const char *,...) __attribute((noreturn));
void err_ret(const char *,...);
void err_sys(const char *,...) __attribute__((noreturn));

void log_msg(const char *,...);
void log_open(const char *,int,int);
void log_quit(const char *,...) __attribute__((noreturn));
void log_ret(const char *,...);
void log_sys(const char *,...) __attribute__((noreturn));
void log_exit(int,const char *,...) __attribute__((noreturn));

void TELL_WAIT(void);
void TELL_PARENT(pid_t);
void TELL_CHILD(pid_t);
void WAIT_PARENT(pid_t);
void WAIT_CHILD(void);


#endif /*_APUE_H*/
