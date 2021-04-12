#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    char *buff = NULL;
    size_t bufsize = 0;
    size_t chars = 0;
	char *chao = "exit\n";
	char *token = NULL;

	while(1)
	{
    	printf("$");
    	chars = getline(&buff,&bufsize,stdin);
		token = strtok(buff, " ");
		while (token != NULL)
		{
			printf("%s\n", token);
			token = strtok(NULL, " ");
		}
		if (chars == EOF)
		{
			printf("Bye!\n");
			break;
		}
		if (!strcmp(chao, buff))
		{
			printf("Bye!\n");
			break;
		}
		printf("%zu characters were read.\n",chars);
	}
	free(buff);
    return(0);
}