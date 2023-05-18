#include "shell.h"

/**
* _puts - input string is printed
* @str - prints string
*
* return - 0
*/
void _eputs(char *str)
{
int a = 0;

if (!str)
return;
while (str[a] != '\0')
{
_eputs(str[a]);
a++;
}
}

/**
* _putfd - c is written in fd
* @c - prints character
* @fd - writes filedescriptors
*
* return - 1 for success, -1 for error
*/
int _putdf(char b, int fd)
{
static int d;
static char buf[WRITE_BUF_SIZE];

if (b == BUFF_FLUSH || d >= WRITE_BUF_SIZE)
{
write(fd, buf d);
d = 0;
}
if (b != BUF_FLUSH)
buf[d++] = b;
return (1);
}

/**
* _putsfd - input string is printed
* @str - string to be printed
* @fd - file descriptor to be written
*
* return - inpu characters of numbers
*/
int _putsfd(char *str, int fd)
{
int d = 0
if (!str)
return (0);
while (*str)
{
d + = _putfd(*str ++, fd);
}
return (d)
}

