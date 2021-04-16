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
	pid_t pid;
	struct stat st;

	chars = getline(&buff, &buffsize, stdin);
	buff[chars - 1] = '\0';
	printf("%s\n", buff);
	printf("%ld\n", chars);
	command = count_tok(buff);/* to get input tokenized*/
	pid = fork();
	wait(NULL);
	if (pid == 0)
	{
		if (stat(command[0], &st) == 0)
		{
			if (execve(command[0], command, environ) == -1)
			{
				free(command);
				free(buff);
				perror("Error: command not found ./hsh");
				return;
			}
		}
		perror("Error: ");
		free(command);
		exit(127);
	}
	free_tokens(command);
	free(buff);
}
