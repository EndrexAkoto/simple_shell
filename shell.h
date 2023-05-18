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
#include <errno.h>

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

/*convert_number*/
#define CONVERT_LOWECASE 2
#define CONVERT_UNSIGNED 3
extern char **environ;

/**
* struct liststr - linked singly list
* @next - next node
* @num - number field
* @str - string
*/
typedef struct liststr
{
int num;
char *str;
struct liststr *next;
}

list_t
/**
* @env : copy list of environ
* @environ : modified copy environ from LL env
* env_changed : when environment is changed, turn on
* @path - current command path for string
* @line_count counts error
* @linecount_flag - count line if on
* @alias - alias node
* @cmd_buf - cmd_buf of chaining in address pointer
* @cmd_buf_type - CMD_type ||, &&
* @history - history node
* @fname - filename of the program
* @err_num - code error for exit()s
* @arg - argument containing getline from string
* @argv - string array generated from arg
* @histcount - number count for history
* @readfd - read line input from fd
* @status - last exec'd of return status
* @struct passinfo - functionoof pseudo-arguments
* @allowing pointer struct of prototype
* @argc - counts argument
*/
typedef struct passinfo
{
int aargc;
int err_num;
int _linecount_flag;
int status;
int env_changed;
char **environ;
char *fname;
char *path
char *arg
char **argv;
unsigned int line_count;
list_t *history;
list_t *alias;
list_t *env;

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

