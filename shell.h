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

/*read/write buffers*/
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1


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

/*toem_getenv.c*/
char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

/*toem_atoi.c*/
int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

#endif

