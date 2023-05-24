#include "shell.h"


/**
 * _eputs - Prints the input string to stderr.
 * @str: The string to be printed.
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
 * _eputchar - Writes a character to stderr.
 * @c: The character to be printed.
 *
 * Return: On success, 1 is returned.
 *         On error, -1 is returned, and errno is set appropriately.
 */
void _eputchar(char c)
{
static int a;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || a >= WRITE_BUF_SIZE)
{
write(2, buf, a);
a = 0;
}
if (c != BUF_FLUSH)
buf[a++] = c;
}

/**
 * _putdf - Writes a character to the specified file descriptor.
 * @b: The character to be written.
 * @fd: The file descriptor to be written.
 *
 * Return: On success, 1 is returned.
 *         On error, -1 is returned, and errno is set appropriately.
 */
int _putdf(char b, int fd)
{
static int a;
static char buf[WRITE_BUF_SIZE];

if (b == BUF_FLUSH || a >= WRITE_BUF_SIZE)
{
write(fd, buf, a);
a = 0;
}
if (a != BUF_FLUSH)
buf[a++] = b;
{return 1; }
}

/**
 * _putsfd - Prints the input string to the specified file descriptor.
 * @str: The string to be printed.
 * @fd: The file descriptor to be written.
 *
 * Return: The number of characters written.
 */
int _putsfd(char *str, int fd)
{
int a = 0;
if (!str)
{return 0; }
while (*str)
{
a += _putdf(*str++, fd);
}
{return a; }
}

