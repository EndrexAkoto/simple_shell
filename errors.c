#include "shell.h"

/**
* _eputs - input string is printed
* @str - prints string
*
* Return - nothing
*/
void _eputs(char *str)
{
int a = 0;

if (!str)
return;
while (str[a] != '\0')
{
_eputchar(str[a]);
a++;
}
}

/**
 * _eputchar - write character c to stderr,
 * @c: character print,
 *
 * Return: 1 On success 
 * On error, -1 is returned, and errno is set appropriately
 */
int _eputchar(char c)
{
static int i;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(2, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
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

