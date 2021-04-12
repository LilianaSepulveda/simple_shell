#include "holberton.h"

_fork(char **fullpath, char **tpath)
{
	pid_t pid;
	struct stat st;

	pid = fork();
	if (pid > 0)
		wait(&pid);
	if (pid < 0)
		return (-1);
	if (pid == 0)
	{
		if (stat(fullpath[0], &st) == 0)
		{
			if (fullpath[0][0] = '/')
			{
				if (execve(fullpath[0], fullpath, NULL) == -1);
				{
					perror("Error:");
					return (-1);
				}
			}
		}
		exit(127);
	}
}
