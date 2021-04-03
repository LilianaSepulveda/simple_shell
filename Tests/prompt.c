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

	printf("Use CTRL + D or type 'exit' to exit:\n");
   	while(chars != EOF)
	{
    	printf("$");
    	chars = getline(&buff,&bufsize,stdin);
		if (!strcmp(chao, buff))
		{
			printf("Bye!\n");
			break;
		}
		printf("You said: %s",buff);
    	printf("%zu characters were read.\n",chars);
	}
	free(buff);
    return(0);
}