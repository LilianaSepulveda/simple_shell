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
	char **add_command = NULL, **aux = NULL, *au = NULL;

	/*aux = malloc(sizeof(char *) * (sizeof(path) + sizeof(command) + 1));
	for(i  = 0; path[i] != NULL; i++)
	{
		au = str_concat("/", command);
		aux[i] = str_concat(path[i], au);
		i++;

	}
	aux[i] = NULL;
	return (aux);*/

	lcomm = _strlen(command);/*command length*/

	while (path[nparr] != NULL)
		nparr++;/*n of pointers in the array*/
	add_command = (char **)malloc(sizeof(char*) * (nparr + 1));/*malloc for a char** */
	for (i = 0; path[i] != NULL; i++)/*to scroll path*/
	{
		larr = _strlen(path[i]);/*length of array in pos i of the array*/
		add_command[i] = malloc(sizeof(char) * (larr + 1));/* malloc to give enough space in each string*/
		for(j = 0; j <= (lcomm + larr); j++)/*scroll strings*/
		{
			if (j < larr)/*fills each position from path string*/
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
int main(void)
{
	char command[] = "ls", **path = NULL, **received = NULL;

	path = malloc(sizeof(char *) * 4);
	if (path == NULL)
		return(-1);
	path[0] = "/usr/local/sbin";
	path[1] = "/usr/local/bin";
	path[2] = "/usr/sbin";
	path[3] = NULL;
	received = add_command(command, path);
	printf("%s\n", received[0]);
	printf("%s\n", received[1]);
	printf("%s\n", received[2]);
	free(path);
	return(0);
}
