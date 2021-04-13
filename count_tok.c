#include "holberton.h"
/**
 *count_tok - function to count strings and tokenize
 *@command: given pointer, array of strings.
 *Return: strings interpretated
 */
char **count_tok(char *command)
{
	int i;
	char **array = NULL, *copy = NULL, *token = NULL;

	i = _strlen(command);
	copy = malloc((i + 1) * sizeof(char));
	for (i = 0; command[i] != '\0'; i++)
	{
		copy[i] = command[i];
	}
	copy[i] = '\0';
	token = strtok(copy, " ");
	i = 0;
	while (token != NULL)
	{
		i++;
		token = strtok(NULL, " ");
	}
	free(copy);
	array = malloc(sizeof(char *) * (i + 1));
	token = strtok(command, " ");
	i = 0;
	while (token != NULL)
	{
		array[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	array[i] = NULL;
	return (array);
}
