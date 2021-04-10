#include "holberton.h"
/**
 *getpath - function to get PATH and tokenize it
 *@env: enviroment
 *Return: An array of trings tokenized
 */
char **getpath(char **env)
{
	char *ptr = NULL, **ptrtoken = NULL;

	ptr = retarray(env);
	ptrtoken = _strtok2(ptr);
	return (ptrtoken);
}
/**
 *retarray - function get an array
 *@env: enviroment
 *Return: the string of all path
 */
char *retarray(char **env)
{
	int i = 0;
	char *ptr = NULL;

	while (env[i] != NULL)
	{
		if (_strncmp(env[i] != NULL))/*create our own strncmp*/
		{
			ptr = _strncmp(env[i]);
			return (ptr);
		}
		i++;
	}
	return (NULL);
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
