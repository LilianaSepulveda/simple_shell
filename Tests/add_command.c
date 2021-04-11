#include "holberton.h"
/**
 * add_command - Function to add a comand to the end of path
 *@command:command to add
 *@path: string recieved
 *Return: Array modified
 */
char **add_command(char *command, char **path)
{
	int lcomm = 0, larr = 0, i, j, k = 0, nparr = 0;
	char **add_command = NULL;

	lcomm = _strlen(command);

	while (path[nparr] != NULL)
		nparr++;
	add_command = (char **)malloc(sizeof(char*) * (nparr + 1));
	for (i = 0; path[i] != NULL; i++)
	{
		larr = _strlen(path[i]);
		add_command[i] = malloc(sizeof(char) * (lcomm + larr + 2));
		for(j = 0; j <= (lcomm + larr); j++)
		{
			if (j < larr)
				add_command[i][j] = path[i][j];
			else if (j == larr)
				add_command[i][j] = '/';
			else
			{
				add_command[i][j] = command[k];
				k++;
			}
		}
		add_command[i][j] = '\0';
	}
	add_command[i] = NULL;
	return (add_command);
}
/*int main(void)
{
	char command[] = "ls", **path, **received = NULL;

	path = malloc(sizeof(char *) * 4);
	path[0] = "/usr/local/sbin";
	path[1] = "/usr/local/bin";
	path[2] = "/usr/sbin";
	received = add_command(command, path);
	printf("%s\n", received[0]);
	printf("%s\n", received[1]);
	printf("%s\n", received[2]);
	return(0);
}*/
