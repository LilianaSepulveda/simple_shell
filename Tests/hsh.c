#include "holberton.h"
/**
 * main - entry point
 * Return: 0 on success
 */
int main(void)
{
	ssize_t chars = 0, buffsize = 0;
	char *buff = NULL, **command = NULL, **Path = NULL, **tpath = NULL, **fullpath = NULL;
	int _forky = 0;
	pid_t pid;
	struct stat st;

	Path = getpath();
	printf("%s\n", Path[0]);
	printf("%s\n", Path[1]);
	printf("%s\n", Path[2]);
	printf("%s\n", Path[3]);
	printf("%s\n", Path[4]);
	printf("%s\n", Path[5]);
	printf("%s\n", Path[6]);

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
		tpath = Path;
		/*fullpath = add_command(command[0],tpath);*/
		_forky = fork();
		if (_forky != 0)
			wait(0);
		if (_forky == 0)
		{
			if (stat(command[0], &st) == 0)
				if (execve(command[0], command, environ))
					perror("Error: ");
			free(command);
			exit(127);
		}

	}
	free(command);
	free(buff);
	return (0);
}
