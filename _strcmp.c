#include "holberton.h"

/**
*_strcmp - Function to compare two strings
*@s1: string 1
*@s2:string 2
*Return: Integer
*/
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}
