#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * main - shell entry point
 *
 * Return: 0
 */
int main(void)
{char input_line[MAX_INPUT_LINE];
char **commands1;
char **args;
int condition;
int x;

/* exit status default*/
int exit_status = 0;
while (1)
{

/* command line read */
if (fgets(input_line, MAX_INPUT_LINE, stdin) == NULL)
break;

/* prompt print */
printf("$ ");
fflush(stdout);

/* newline character remove */
input_line[strcspn(input_line, "\n")] = '\0';

/* command line split into commands */
commands1 = split_line(input_line);

/* execute commands */
for (x = 0; commands1[x] != NULL; x++)
{

/* command into arguments is split */
args = split_line(commands1[y]);

/* command execute */
if (args[0] != NULL)
{
if (strcmp(args[0], "exit") == 0)
{
if (args[1] != NULL)
{
exit_status = atoi(args[1]);
}

/* Free memory */
free(args);
free(commands1);
exit(exit_status);
}
else if (strcmp(args[0], "cd") == 0)
{

/* directory change */
if (args[1] != NULL)
{
if (strcmp(args[1], "-") == 0)
{

/* handle "cd -" */
char *prev_dir = getenv("OLDPWD");
if (prev_dir != NULL)
{
if (chdir(prev_dir) == -1)
perror("chdir");
}
else
{
fprintf(stderr, "cd: OLDPWD not set\n");
}
}
else
{
if (chdir(args[1]) == -1)
{
perror("chdir");
}
else
{

/* PWD environment variable update*/
char current_dir[MAX_INPUT_LINE];
if (getcwd(current_dir, sizeof(current_dir)) != NULL)
{
if (setenv("PWD", current_dir, 1) == -1)
{
fprintf(stderr, "cd: Failed to update PWD\n");
}
}
else
{
perror("getcwd");
}
}
}
}
else
{

/* Change HOME directory when no argument is taken */
char *home_dir = getenv("HOME");
if (home_dir != NULL)
{
if (chdir(home_dir) == -1)
perror("chdir");
}
else
{
fprintf(stderr, "cd: HOME not set\n");
}
}
}
else if (strcmp(args[0], "env") == 0)
{

/* Print environment */
print_environment();
}
else if (strcmp(args[0], "setenv") == 0)
{

/* set environment variable */
if (args[1] != NULL && args[2] != NULL)
{
if (setenv(args[1], args[2], 1) == -1)
{
fprintf(stderr, "setenv: Failed to set environment variable\n");
}
}
else
{
fprintf(stderr, "setenv: Usage: setenv VARIABLE VALUE\n");
}
}
else if (strcmp(args[0], "unsetenv") == 0)
{

/* Unset environment variable */
if (args[1] != NULL)
{
if (unsetenv(args[1]) == -1)
{
fprintf(stderr, "unsetenv: Failed to unset environment variable\n");
}
}
else
{
fprintf(stderr, "unsetenv: Usage: unsetenv VARIABLE\n");
}
}
else
{

/* command execute*/
condition = execute_command(args);
if (condition == -1)
{

/* command not found, try with PATH */
execute_command_path(args);
}
}
}

/* memory free */
free(args);
}

/* memory free */
free(commands1);
}

/* Use exit_status argument for exit() */
exit(exit_status);
return (0);
}

