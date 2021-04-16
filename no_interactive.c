#include "holberton.h"
/**
 *no_interactive - If non-intercative mode, go trhough this.
 *Return: 0
 */
void no_interactive(void)
{
	size_t buffsize = 0;
	char *buff = NULL, **command = NULL;
	pid_t pid;
	struct stat st;
	int i = 0;

	while (getline(&buff, &buffsize, stdin) != EOF)
	{
		i = 0;
		while (buff[i])
		{
			if (buff[i] == '\n')
				buff[i] = '\0';
			i++;
		}
		command = count_tok(buff);/* to get input tokenized*/
		pid = fork();
		wait(NULL);
		if (pid == 0)
		{
			if (stat(command[0], &st) == 0)
			{
				if (execve(command[0], command, environ) == -1)
				{
					free_tokens(command);
					free(buff);
					perror("Error: command not found ./hsh");
					return;
				}
			}
			perror("Error: ");
			free_tokens(command);
			exit(127);
		}
		free_tokens(command);
		command = NULL;
	}
	free(buff);
}
