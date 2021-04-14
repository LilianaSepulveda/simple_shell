#include "holberton.h"

/**
 * main - entry point
 * Return: 0 on success
 */

int main(void)
{
	ssize_t chars = 0;
	size_t buffsize = 0;
	char *buff = NULL, **command = NULL, **Path = NULL, **tpath = NULL, **fullpath = NULL;
	int _forky = 0, i = 0;
	pid_t pid;
	struct stat st;
	/**
	/*Path = getpath();
	/*if (isatty(STDIN_FILENO) != 1)  this is becauseif issaty returns 1 it is a
	{/*fd reffering to a terminal*/
	/*	no_interactive(Path);/*go to a function to execute the command
	/*	free(Path); /*it's already used, so we can end this process
	/*	return (0);
	}*/
	while (chars != EOF)
	{
		write(1, "$ ", 2);
		chars = getline(&buff, &buffsize, stdin);
		if (chars == EOF)/*exits with EOF (CTRL+D)*/
			break;
		buff[chars - 1] = '\0';
		if (buff[0] == '\0')
			continue;
		command = count_tok(buff);
		if (_fork(command) == -1) ;
		{free_tokens(command), free(buff), continue;}
		free(command);
	}
	free(buff);
	return (0);
}
