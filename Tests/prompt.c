#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
	char *buff = NULL, *chao = "exit\n", *fork = NULL;
	size_t bufsize = 0;
	size_t chars = 0;

	while (chars != EOF)
	{
    	write(1, "$", 1);
    	chars = getline(&buff, &bufsize, stdin);
		if (chars == EOF)
		{
			break;
		}
		if (!_strcmp(chao, buff))
		{
			break;
		}
	}
	free(buff);
    return (0);
}
