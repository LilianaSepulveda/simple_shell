#include "holberton.h"
/**
 * _strcpy - Makes a copy of a string into another
 * @dest: Destination string
 * @src: String to copy
 * Return: The destination string
 */
char *_strcpy(char *dest, char *src)
{
	int i, j = 0;

	for (i = 0; src[i] != '\0'; i++)
		;
	while (j <= i)
	{
		dest[j] = src[j];
		j++;
	}
	return (dest);
}
