#include "holberton.h"
/**
 *no_interactive - If non-intercative mode, go trhough this.
 *Return: 0
 */
void no_interactive(void)
{
	ssize_t chars = 0;
	size_t buffsize = 0;
	char *buff = NULL, **command = NULL;

	chars = getline(&buff, &buffsize, stdin);
	printf("%ld\n", chars);
	command = count_tok(buff);/* to get input tokenized*/
	_fork(command);
	printf("%s\n", "pffff");

}
