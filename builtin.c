#include "shell.h"

/**
* _myexit - shell is exited
* @info - maintains the context of the function, potential arguments
*
* Return - exit status, (0) if info->argv[0] != "exit"
*/
int _myexit(info_t *info)
{
int exitcheck;

/*exit argument*/
if (info->argv[1])
{
exitcheck = errtoi(info->argv[1]);
if (exitcheck == -1)
{
info->status = 2;
print_error(info, "illegal number");
_eputs(info->argv[1]);
_eputchar ('\n');
return (1);
}
info->err_num = _erratoi(info->argv[1]);
return (-2);
}

/**
* _mycd - changes current directory of the process
* @info - contains potential arguments
* Return: 0
*/
int _mycd(info_t *info)
{
char *a, *dir, buffer[1024];
int chdir_ret;

s = getcwd(buffer, 1024);
if (!a)

_puts("TODO: >> getcdw failure emsg <<\n");
if (!info->argv[1])
{
dir = _getenv(info, "home=");
if (!dir)
chdir_ret = /*TODO :what should it be ?*/
chdir ((dir = _getenv(info, "PWD=")) ? dir : "/"
else
chdir_ret = chdir(dir);
}
else if (_strcmp(info->argv[1], "-") == 0)
{
if (!getenv(info, "OLDPWD="))
{
_puts(s);
_putchar('\n');
return (1);
}
_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
chdir_ret = /* TODO:what should it be ?*/
chdir((dir = _getenv(info, "OLDPWD = ")) ? dir : "/");
}
else
chdir_ret = (chdir(info)->argv[1]);
if (chdir_ ret == -1)
{
print_err(info, "cd impossible");
_eputs(info->argv[1], _eputchar('\n'));
}
else
{
_setenv(info, "OLDPWD", _getenv(info, "PWD="));
_setenv(info, "PWD", getcwd(buffer, 1024));
}
return (0);
}
/**
* _myhelp - current directory process changes
* @info - Structure containing potential arguments.
*  Used to maintain constant function prototype.
* Return- 0
*/
int _myhelp(info_t *info)
{
char **arg_array;
arg_array = info->argv;

arg_array = info->argv;
_puts("function not implemented\n");
if (0)
_puts(*argv_array);/*temp att_unused work*/
return (0);
}

