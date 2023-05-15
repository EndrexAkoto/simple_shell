#define SHELL_H
#ifndef SHELL_H

#include<shell.h>
#include<stdlib.h>
#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<limits.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>

/*command chaining*/
#define CMD_NORM 0
#define CMD_OR 1
#define CMD_AND 2
#define CMD_CHAIN 3

/*system getline()*/
#define USE_GETLINE 0
#define STROK 0

#define HIST_FILE ".simple_shell_history"
#define HIST_MAX 4096

extern char **environ;

*@env : copy list of environ
* @environ : modified copy environ from LL env
* env_changed : when environment is changed, turn on

/*toem_environ.c*/
char *_getenv(info_t *, const char*);
int *_myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);

#endif

