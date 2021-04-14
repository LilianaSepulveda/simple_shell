#include "holberton.h"
/**
 * _strlen - Function to determine the length of a string
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
/**
 *str_concat - Function to concatenate 2 strings
 *@s1: 1st string to concatenate
 *@s2: 2nd string to concatenate
 *Return: Concatenated String
 */
char *str_concat(char *s1, char *s2)
{
	int a, b, c, d;
	char *f;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	for (a = 0; s1[a] != '\0'; a++)
		;
	for (b = 0; s2[b] != '\0'; b++)
		;
	f = malloc(sizeof(char) * (b + a + 1));
	if (f == NULL)
		return (NULL);
	for (c = 0; s1[c] != '\0'; c++)
		f[c] = s1[c];
	for (d = 0; s2[d] != '\0'; d++)
		f[c + d] = s2[d];
	f[c + d] = '\0';
	return (f);
}