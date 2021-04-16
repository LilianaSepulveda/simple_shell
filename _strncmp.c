#include "holberton.h"
/**
 * _strncmp - compares two strings
 *@s1: given string
 *@s2: string to compare with s1
 * Return: String modified by 5 positions.
 */
int _strncmp(char *s1, char *s2)
{
	int i = 0, h = 0, g = 0;

	while (s2[h] != '\0')
	{
		h++;
	}
	while (i < h)
	{
		if (s1[i] != s2[i])
			g++;
		i++;
	}
	if (g != 0)
		return (-1);
	return (0);
}
