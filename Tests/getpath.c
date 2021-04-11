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
		if (!_strncmp(environ[i], path))/*create our own strncmp*/
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
	int i, copysize = 0, counttoken = 0;
	char **pathtoken = NULL, *copy = NULL, *token = 0;

	copysize = _strlen(path);
	copy = malloc(sizeof(char) * (copysize + 1));
	if (copy == NULL)
	{
		free(copy);
		perror("Error: ");
	}
	copy = _strcpy(copy, path);
	token = strtok(copy, ":");
	while (token)
	{
		counttoken++;
		token = strtok(NULL, ":");
	}
	pathtoken = (char **)malloc(sizeof(char *) * (counttoken + 1));
	token = strtok(path, ":");
	while (token)
	{
		pathtoken[i] = malloc(sizeof(char) * (_strlen(token + 1)));
		_strcpy(pathtoken[i], token);
		token = strtok(NULL, ":");
		i++;
	}
	pathtoken[i] = NULL;
	free(copy);/*free pathtoken?*/
	return (pathtoken);
}
