#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024

int main(void)
{
char input[MAX_INPUT_LENGTH];
char *args[MAX_INPUT_LENGTH / 2 + 1];
int status;
pid_t pid;

while (1)
{
printf("($) ");
fflush(stdout);

if (fgets(input, sizeof(input), stdin) == NULL)
{
printf("\n");
break;
}

if (input[strlen(input) - 1] == '\n')
input[strlen(input) - 1] = '\0';

char *token = strtok(input, " ");
int i = 0;
while (token != NULL)
{
args[i] = token;
token = strtok(NULL, " ");
i++;
}
args[i] = NULL;

pid = fork();

if (pid < 0)
{
perror("Fork failed");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
if (execvp(args[0], args) == -1)
{
perror(args[0]);
exit(EXIT_FAILURE);
}
}
else
{
waitpid(pid, &status, 0);
}
}

{return EXIT_SUCCESS; }
}

