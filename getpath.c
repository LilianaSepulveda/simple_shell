#include "holberton.h"
/**
 *getpath - function to get PATH and tokenize it
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
	char **pathtoken = NULL, *copy = NULL, *token = NULL, *copy2 = NULL;

	copysize = _strlen(path);
	copy = malloc(sizeof(char) * (copysize + 1));
	if (copy == NULL)
	{
		free(copy);
		perror("Error: ");
	}
	copy2 = malloc(sizeof(char) * (copysize + 1));
	if (copy2 == NULL)
	{
		free(copy2);
		perror("Error: ");
	}
	copy = _strcpy(copy, path);
	copy2 = _strcpy(copy2, path);
	token = strtok(copy, ":");
	while (token)
	{
		b++;
		token = strtok(NULL, ":");
	}
	free(copy);
	pathtoken = (char **)malloc(sizeof(char *) * (b + 1));
	token = NULL;
	token = strtok(copy2, ":");
	while (token)
	{
		pathtoken[i] = token;
		token = strtok(NULL, ":");
		i++;
	}
	pathtoken[i] = NULL;
	free(copy2);
	return (pathtoken);
}
/*
*int main(void)
*{
* char path[] = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin";
* char **strtokenized = NULL;
* strtokenized = _strtok2(path);
* printf("%s\n", strtokenized[0]);
* printf("%s\n", strtokenized[1]);
* printf("%s\n", strtokenized[2]);
* printf("%s\n", strtokenized[3]);
* printf("%s\n", strtokenized[4]);
* printf("%s\n", strtokenized[5]);
* return(0);
*}
*/
