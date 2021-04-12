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

	Path = getpath();
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
		fullpath = add_command(command[0],tpath);
		_forky = _fork(fullpath, tpath);
		
	}
	free(Path);
	free(command);
	free(buff);
	return (0);
}
