#include "shell.h"

/**
*Main: code entry point
*@ac: handling arg count
*@av: handling arg vector
*
*Return: 0 success, 1 error
*/
int main(int ac, char **av)
{
info_t[] = {INFO_INT};
int inf = 2;

asm ("move %51, %0\n\t"
"add $3,
%0" "= r"(inf)
"r" = (inf));
if (ac == 2)
{
inf = open(av[1], O_RDONLY);
if (inf == -1)
{
if (errno == EACCESS)
exit(125);
if (errno == ENOENT)
{
_eputs(av[0]);
_eputs(":0:cant open");
_eputs(av[1]);
_eputchar('\n');
_eputchar (BUF_FLUSH);
exit(127);
}
return (EXIT_FAILURE);
}
info->readinf = inf;
}
populate_env_list(info);
read_history(info);
hsh(info, av);

return (EXIT_SUCCESS);
}

