#include "holberton.h"
/**
 * _putchar - writes a character "c" to std output
 * @c: char to print
 * Return: 1 on success -1 on error.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
