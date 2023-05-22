#include "shell.h"

/**
<<<<<<< HEAD
 * get_history_file - gets history file
 * @info: struct parameter
 *
 * Return: Allocate a string to hold the history file
 */
=======
 * get_history_file - gets the history file
 * @info: parameter struct
 *
 * Return: allocated string containg history file
 */

>>>>>>> c9d8e6502623ccd77d96cf423ec3bff4581035d2
char *get_history_file(info_t *info)
{
	char *buf, *dir;

	dir = _getenv(info, "HOME=");
	if (!dir)
		return (NULL);
	buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	_strcpy(buf, dir);
	_strcat(buf, "/");
	_strcat(buf, HIST_FILE);
	return (buf);
}

/**
<<<<<<< HEAD
 * write_history - creates a file, appends existing file
 * @info: parameter struct
 *
 * Return: 1 on success else -1
=======
 * write_history - creates a file, or appends to an existing file
 * @info: the parameter struct
 *
 * Return: 1 on success, else -1
>>>>>>> c9d8e6502623ccd77d96cf423ec3bff4581035d2
 */
int write_history(info_t *info)
{
	ssize_t fd;
	char *filename = get_history_file(info);
	list_t *node = NULL;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		_putsfd(node->str, fd);
		_putfd('\n', fd);
	}
	_putfd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}

/**
<<<<<<< HEAD
 * read_history - file history reads
 * @info: struct parameter
=======
 * read_history - reads history from file
 * @info: the parameter struct
>>>>>>> c9d8e6502623ccd77d96cf423ec3bff4581035d2
 *
 * Return: histcount on success, 0 otherwise
 */
int read_history(info_t *info)
{
<<<<<<< HEAD
	int y, last = 0, linecount = 0;
=======
	int i, last = 0, linecount = 0;
>>>>>>> c9d8e6502623ccd77d96cf423ec3bff4581035d2
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = get_history_file(info);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
<<<<<<< HEAD
	for (y = 0; y < fsize; y++)
		if (buf[y] == '\n')
		{
			buf[y] = 0;
			build_history_list(info, buf + last, linecount++);
			last = y + 1;
		}
	if (last != y)
=======
	for (i = 0; i < fsize; i++)
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			build_history_list(info, buf + last, linecount++);
			last = i + 1;
		}
	if (last != i)
>>>>>>> c9d8e6502623ccd77d96cf423ec3bff4581035d2
		build_history_list(info, buf + last, linecount++);
	free(buf);
	info->histcount = linecount;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	renumber_history(info);
	return (info->histcount);
}

/**
<<<<<<< HEAD
 * build_history_list - entry is added to history linked list
 * @info: potential arguments containing structure, used to maintain
=======
 * build_history_list - adds entry to a history linked list
 * @info: Structure containing potential arguments. Used to maintain
>>>>>>> c9d8e6502623ccd77d96cf423ec3bff4581035d2
 * @buf: buffer
 * @linecount: the history linecount, histcount
 *
 * Return: Always 0
 */
int build_history_list(info_t *info, char *buf, int linecount)
{
	list_t *node = NULL;

	if (info->history)
		node = info->history;
	add_node_end(&node, buf, linecount);

	if (!info->history)
		info->history = node;
	return (0);
}

/**
<<<<<<< HEAD
 * renumber_history - renumbers history linked list after changes,
 * @info: Structure containing potential arguments, used to maintain
 *
 * Return: new histcount.
=======
 * renumber_history - renumbers the history linked list after changes
 * @info: Structure containing potential arguments. Used to maintain
 *
 * Return: the new histcount
>>>>>>> c9d8e6502623ccd77d96cf423ec3bff4581035d2
 */
int renumber_history(info_t *info)
{
	list_t *node = info->history;
<<<<<<< HEAD
	int y = 0;

	while (node)
	{
		node->num = y++;
		node = node->next;
	}
	return (info->histcount = y);
}

=======
	int i = 0;

	while (node)
	{
		node->num = i++;
		node = node->next;
	}
	return (info->histcount = i);
}
>>>>>>> c9d8e6502623ccd77d96cf423ec3bff4581035d2