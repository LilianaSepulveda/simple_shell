#include "holberton.h"
/**
 * _strlen - Fnction to determine the length of a string
 * @str: String
 * Return: Length of the string
 */
int _strlen(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		;
	return (i);
}
