#include "holberton.h"
/**
 * _strncmp - compares two strings
 * @env:given string
 * Return: String modified by 5 positions.
 */
char *_strncmp(char *env)
{
	int i;
	char PATH[] = "PATH=", *strncmp = NULL;

	for (i = 0; i <= 4; i++)
	{
		if (env[i] != PATH[i])
			return(NULL);
	}
	strncmp = env[i] + 5;
	return (strncmp);
}
