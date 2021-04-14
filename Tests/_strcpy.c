#include "holberton.h"
/**
 * _strcpy - Makes a copy of a string into another
 * @dest: Destination string
 * @src: String to copy
 * Return: The destination string
 */
char *_strcpy(char *dest, char *src)
{
	int i, j = 0, copysize = 0;
	char *copy = NULL;

	copysize = _strlen(src);
	copy = malloc(sizeof(char) * (copysize + 1));
	if (copy == NULL)
	{
		free(copy);
		perror("Error: ");
	}

	for (i = 0; src[i] != '\0'; i++)
		;
	while (j <= i)
	{
		copy[j] = src[j];
		j++;
	}
	return (copy);
}
