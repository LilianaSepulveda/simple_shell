#include "holberton.h"
/**
 * _fork - Function to fork and execute command line
 * @command: Command line tokenized to be executed
 * Return: 0 if success -1 if went wrong
 */

int _fork(char **command)
{
	pid_t pid;
	struct stat st;
	int i = 0, x = -1, z = 0;
	char **path = NULL, **fullpath = NULL, *aux = NULL;

	aux = strdup(command[0]);
	while (aux[z] != '\0')
	{
		if (aux[z] == '\n')
			aux[z] = '\0';
		z++;
	}
	pid = fork();
	wait(NULL);
	if (pid == 0)
	{
		if (command[0][0] == '/')
		{
			if (execve(aux, command, environ) == -1)
			{
				perror("Error: command not found");
				return (-1);
			}
		}
		else if (command[0][0] != '/')
		{
			path = getpath();
			fullpath = add_command(command[0], path);
			if (execve(fullpath[0], command, environ) == -1)
			{
				perror("Error: command not found");
				return (-1);
			}
		}
		exit(127);
	}
}
