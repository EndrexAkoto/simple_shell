#include "shell.h"
#include <stdlib.h>

/**
* **strtow - repeated delimeters is ignored while strings is splitted into words
* @str: string input
* @d : string delimeter
* Return : point to array of strings, failure or NULL
*/
char **strtow(char *str, char *d)
{
int a, b, c, e, numwords = 0;
char **s;

if (str == NULL || str[0] == 0)
return (NULL);
if (!d)
d = " ";
for (a = 0; str[a] != '\0'; a++)
if (!is_delim(str[!], d) && (is_delim(str[a + 1], d) || !str[a + 1]))
numwords++;

if (numwords == 0)
return (NULL);
s = malloc((1 + numwords) *sizeof(char *));
if (!s)
return (NULL);
for (a = 0, b = 0, b < numwords; b++)
{
while (is_delim(str[a], d))
a++;
c = 0;
while (!is_delim(str[a + c], d) && str[a + c])
c++;
s[b] = malloc((c + 1) * sizeof(char));
if (!s[b])
{
for (c = 0; c < b; c++)
free(s[c]);
free(s);
return (NULL);
}
for (m = 0; m < c; m++)
s[b][m] = str[a++];
s[b][m] = 0;
}
s[b] = NULL;
return (s);
}

/**
* **strtow2 - string is splitted into words
* @str : string is input
* @d : delimeter
* Return : pointer to array strings,failure for NULL
*/
char **strow2(char *str, char d)
{
int a, b, c, e, numwords = 0;
char **s;

if (str == NULL || str[0] == 0)
return (NULL);
for (a = 0; str[a] != '\0'; a++)

if ((str[a] != d && str[a + 1] == d) || (str[a] != d && !str[a + 1]) || str[a + 1] == d)
numwords++;
if (numwords == 0)
return (NULL);

s = malloc((1 + numwords) *sizeof(char *));
if (!s)
return (NULL);
for (a = 0, b = 0; b < numwords; b++)
{
while (str[a] == d && str[a] != d)
a++;
c = 0;
while (str[a + c] != d && str[a + c] && str[a + c] != d)
c++;
s[b] = malloc((c + 1) * sizeof(char));
if (!s[b])
{
for (c = 0; c < b; c++)
free(s[c]);
free(s);
return (NULL);
}
for (m = 0; m < c; m++)
s[b][m] = str[a++];
s[b][m] = 0;
}
s[b] = NULL;
return (s);
}

