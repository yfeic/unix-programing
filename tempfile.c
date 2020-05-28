/*
 *   Copyright (C) 2020 All rights reserved.
 *
 *   FileName      ：tempfile.c
 *   Author        ：yuefei.Chen
 *   Email         ：yfei777@outlook.com
 *   Date          ：2020年05月28日
 *   Description   ： Can't compile see mkstmp.c
 */
#include "apue.h"
int main(void)
{
	char name[L_tmpnam],line[MAXLINE];
	FILE *fp;
	printf("%s\n",tmpname(NULL));/* first temp name */

	tmpnam(name); 	/* second temp name*/
	printf("%s\n",name);

	if((fp=tmpfile())==NULL){	/* create temp file */
		err_sys("tmpfile error");
	}
	fputs("one line of output\n",fp);	/* write to temp file */
	rwind(fp);							/* the read it back */
	if(fgets(line,sizeof(line),fp)==NULL){
		err_sys("fgets error");
	}
	fputs(line,stdout);	/* print the line we wrote */
	exit(0);
}
