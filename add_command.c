#include "holberton.h"
/**
 * add_command - Function to add a comand to the end of path
 *@command:command to add
 *@path: string recieved
 *Return: Array modified
 */
char **add_command(char *command, char **path)
{
	int lcomm = 0, larr = 0, i, j, k, nparr = 0;
	char **add_command = NULL;

	lcomm = _strlen(command);/*command length*/
	while (path[nparr] != NULL)
		nparr++;/*n of pointers in the array*/
	add_command = (char **)malloc(sizeof(char *) * (nparr + 1));
	if (add_command == NULL)
	{
		free(add_command);
		perror("Error: ");
	}
	for (i = 0; path[i] != NULL; i++)/*to scroll path*/
	{
		k = 0;
		larr = _strlen(path[i]);/*length of array in pos i of the array*/
		add_command[i] = malloc(sizeof(char) * (larr + lcomm + 2));
		if (add_command[i] == NULL)
		{
			free(add_command);
			perror("Error: ");
		}
		for (j = 0; j <= (lcomm + larr + 2); j++)/*scroll strings*/
		{
			if (j < larr)/*fills each position from path string*/
			{
				add_command[i][j] = path[i][j];
			}
			else if (j == larr + 1)
			{
				add_command[i][j] = '/';
			}
			else
			{add_command[i][j] = command[k], k++; }
		}
		add_command[i][j] = '\0';
	}
	add_command[i] = NULL;
	return (add_command);
}
