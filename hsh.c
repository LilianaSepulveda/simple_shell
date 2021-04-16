#include "holberton.h"

/**
 * main - entry point
 * Return: 0 on success
 */

int main(void)
{
	ssize_t chars = 0;
	size_t buffsize = 0;
	char *buff = NULL, **command = NULL;
	pid_t pid;
	struct stat st;


	while (chars != EOF)
	{
		if (isatty(STDIN_FILENO) != 1)/*this is becauseif issaty returns 1 it is a*/
		{	no_interactive();/*go to a function to execute the command*/
			return (0);	}
		write(1, "$ ", 2);
		fflush(stdin);
		chars = getline(&buff, &buffsize, stdin);
		if (chars == EOF)/*exits with EOF (CTRL+D)*/
			break;
		buff[chars - 1] = '\0';
		if (buff[0] == '\0')
			continue;
		command = count_tok(buff);
		pid = fork();
		wait(NULL);
		if (pid == 0)
		{
			if (stat(command[0], &st) == 0)
			{
				if (execve(command[0], command, environ) == -1)
				{perror("Error: command not found ./hsh");
					return (-1); }
			}
			free_tokens(command);
			exit(127);
		}
	}
	free(buff);
	free_tokens(command);
	return (0);
}
