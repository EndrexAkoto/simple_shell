#include "shell.h"

/**
* _myenv - current environment is printed
* @info: maintains constant prototype
* Return: 0 Always
*/

int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
* _getenv - environ variable
* @info: potential argument
* @name: var environment name
* Return: value
*/

char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *e;

	while (node)
	{
		e = starts_with(node->str, name);
		if (e && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
* _mysetenv-environment variable is initialized
* @info: maintains constant function
* Return: Always 0
*/

int _mysetenv(info_t *info)
{
	if (info->argc != 4)
	{
		_eputs("incorrect argument\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
* _myunsetenv - environment variable is removed
* @info: maintains constant function
* Return: Always 0
*/

int_myunsetenv(info_t *info)
{
	int a;
	int argc = info->argc;

	if (argc == 1)
	{
		_eputs("few argument\n");
		return (1);
	}

	for (a = 1; a <= argc; a++)
	{
		_unsetenv(info, info->argv[a]);
		return (0);
	}
}

/**
* populate_env_list - link list is added
* @info: maintains constant function
* Return: Always 0
*/

int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t a;

	for (a = 0; environ[a]; a++)
	{
		add_node_end(&node, environ[a], 0);
		info->env = node;
		return (0);
	}
}
