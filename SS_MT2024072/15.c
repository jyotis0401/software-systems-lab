/*
============================================================================
Name : 15.c
Author : Jyoti Singh
Description : Write a program to display the environmental variable of the user (use environ).
Date: 26th Aug, 2024.
============================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>


#include <unistd.h>
#include <stdio.h>

extern char **environ;

int main(){
	int i = 0;
	
	while(environ[i]) {
		printf("%s\n", environ[i++]); // prints in form of variable=value
	}

	return 0;
}

/*
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ gcc 15.c
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ ./a.out
TERM_PROGRAM=Apple_Terminal
SHELL=/bin/bash
TERM=xterm-256color
TMPDIR=/var/folders/wl/sfl9wr6j6nq_n18388tg05j00000gn/T/
CONDA_SHLVL=1
Apple_PubSub_Socket_Render=/private/tmp/com.apple.launchd.UvgbLxDSOZ/Render
CONDA_PROMPT_MODIFIER=(base) 
TERM_PROGRAM_VERSION=388.1.3
OLDPWD=/Users/jyotisingh
TERM_SESSION_ID=DD14B619-4C1F-49A8-83BD-5971792AC2D7
USER=jyotisingh
CONDA_EXE=/opt/anaconda3/bin/conda
SSH_AUTH_SOCK=/private/tmp/com.apple.launchd.Sis0HBdWvl/Listeners
__CF_USER_TEXT_ENCODING=0x1F5:0x0:0x0
_CE_CONDA=
PATH=/opt/anaconda3/bin:/opt/anaconda3/condabin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin
CONDA_PREFIX=/opt/anaconda3
PWD=/Users/jyotisingh/Desktop/SystemsSoftware
XPC_FLAGS=0x0
_CE_M=
XPC_SERVICE_NAME=0
SHLVL=1
HOME=/Users/jyotisingh
CONDA_PYTHON_EXE=/opt/anaconda3/bin/python
LOGNAME=jyotisingh
LC_CTYPE=UTF-8
CONDA_DEFAULT_ENV=base
SECURITYSESSIONID=186a6
_=./a.out
*/