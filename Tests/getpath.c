#include "holberton.h"
/**
 *getpath - function to get PATH and tokenize it
 *@env: enviroment
 *Return: An array of trings tokenized
 */
char **getpath(void)
{
	char *ptr = NULL, **ptrtoken = NULL;

	ptr = retarray();
	ptrtoken = _strtok2(ptr);
	return (ptrtoken);
}
/**
 *retarray - function get an array
 *@env: enviroment
 *Return: the string of all path
 */
char *retarray(void)
{
	int i = 0, j;
	char *ptr = NULL, *path = "PATH=";

	while (environ[i] != NULL)
	{
		if (!_strncmp(environ[i], path))
		{
			for (j = 0; path[j] != '\0'; j++)
				;
			ptr = (environ[i] + j);
		}
		i++;
	}
	return (ptr);
}
/**
 *_strtok2 - tokenizes the path
 *@path: "PATH="
 *Return: "PATH=" tokenized.
 */
char **_strtok2(char *path)
{
    int i = 0, b = 0, copysize = 0;
    char **pathtoken = NULL, *copy = NULL, *token = NULL, *buff = NULL;

    copysize = _strlen(path);
    copy = malloc(sizeof(char) * (copysize + 1));
    if (copy == NULL)
    {
        free(copy);
        perror("Error: ");
    }
    copy = _strcpy(copy, path);
    while (path[b] != '\0')
    {
      if (path[b] == ':')
        b++;
    }
    pathtoken = malloc(sizeof(char *) * (b + 1));
      if (pathtoken == NULL)
      {
        free(pathtoken);
        perror("Error: ");
      }
    token = strtok(copy, ":");
    while (token != NULL)
    {
      pathtoken[i] = token;
      i++;
      token = strtok(NULL, ":");
    }
    free(copy);
    pathtoken[i] = NULL;
    return(pathtoken);
}
/*int main(void)
{
  char path[] = "/home/yael/.vscode-server/bin/08a217c4d27a02a5bcde898fd7981bda5b49391b/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/mnt/c/Windows/system32";
  char **strtokenized = NULL;

  strtokenized = _strtok2(path);
  printf("%s\n", strtokenized[0]);
  printf("%s\n", strtokenized[1]);
  printf("%s\n", strtokenized[2]);
  printf("%s\n", strtokenized[3]);
  printf("%s\n", strtokenized[4]);
  printf("%s\n", strtokenized[5]);
  printf("%s\n", strtokenized[6]);

  return(0);
}*/
