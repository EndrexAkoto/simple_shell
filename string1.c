#include "shell.h"
#include <stdlib.h>

/**
 * _strcpy - copy string
 * @dest: destination
 * @src: source
 *
 * Return: pointer destination
 */
char *_strcpy(char *dest, char *src)
{
	int y = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[y])
	{
		dest[y] = src[y];
		y++;
	}
	dest[y] = 0;
	return (dest);
}

/**
 * _strdup - duplicates string
 * @str: string duplicate
 *
 * Return: pointer duplicated string
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 * _puts - prints input string
 * @str: string to be printed
 *
 * Return: nothing
 */
void _puts(char *str)
{
	int y = 0;

	if (!str)
		return;
	while (str[y] != '\0')
	{
		_putchar(str[y]);
		y++;
	}
}

/**
 * _putchar - writes character c to stdout
 * @c: character to print
 *
 * Return: On success 1
 * On error, -1 is returned while errno is set appropriately
 */
int _putchar(char c)
{
	static int y;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || y >= WRITE_BUF_SIZE)
	{
		write(1, buf, y);
		y = 0;
	}
	if (c != BUF_FLUSH)
		buf[y++] = c;
	return (1);
}

