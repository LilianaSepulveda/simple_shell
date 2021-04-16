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
	int i = 0, b = 0;
	char **pathtoken = NULL, *copy = NULL, *token = NULL;

	while (path[i] != '\0')
	{
		if (':' == path[i])
		{
			b++;
			i++;
		}
		i++;
	}
	pathtoken = malloc(sizeof(char *) * (b + 1));
	if (pathtoken == NULL)
	{
		free(pathtoken);
		perror("Error:");
	}
	copy = _strcpy(path);
	token = strtok(copy, ":");
	i = 0;
	while (token)
	{
		pathtoken[i] = _strcpy(token);
		token = strtok(NULL, ":");
		i++;
	}
	pathtoken[i] = NULL;
	free(copy);
	return (pathtoken);
}
/**
 * free_tokens - function to free tokens
 * @tok_2free: array to free
 * Return - void
 */
void free_tokens(char **tok_2free)
{
	int i = 0;

	while (tok_2free[i])
		free(tok_2free[i++]);
	free(tok_2free);
}
