#include "shell.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * bfree - frees pointer, NULLs the address
 * @ptr: address pointer free
 *
 * Return: 1 if freed, otherwise 0
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

