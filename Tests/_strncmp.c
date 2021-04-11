#include "holberton.h"
/**
 * _strncmp - compares two strings
 * @env:given string
 * Return: String modified by 5 positions.
 */
int _strncmp(char *s1, char *s2)
{
	int i = 0, h = 0, g = 0;
	char *strncmp = NULL;

	while (s2[h] != '\0')
	{
		h++;
	}
	while(i < h)
	{
		if (s1[i] != s2[i])
			g++;
		i++;
	}
	if (g != 0)
		return (-1);
	return (0);
}
