#include "holberton.h"
/**
 * main - entry point
 * Return: 0 on success
 */
int main(void)
{
	ssize_t chars = 0, buffsize = 0;
	char *buff = NULL, **command = NULL;
	struct stat st;
	pid_t _fork;

	while (chars != EOF)
	{
		write(1, "$ ", 2);
		chars = getline(&buff, &buffsize, stdin);
		if (chars == EOF)
			break;
		buff[chars - 1] = '\0';
		if (buff[0] == '\0')
			continue;
		command = count_tok(buff);
		_fork = fork();
		if (_fork != 0)
			wait(0);
		if (_fork == 0)
		{
			if (stat(command[0], &st) == 0)
				if (execve(command[0], command, environ) == -1)
					perror("Error: ");
			free(command);
			exit(127);
		}
		printf("%s\n", command[0]);
	}
	free(command);
	free(buff);
	return (0);
}
