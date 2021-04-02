#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    char *buff;
    size_t bufsize = 0;
    size_t chars;

    buff = malloc(bufsize * sizeof(char));
    if(buff == NULL)
    {
        perror("Unable to allocate buffer");
        exit(1);
    }

    printf("$");
    chars = getline(&buff,&bufsize,stdin);
	printf("You said: %s",buff);
    printf("%zu characters were read.\n",chars);
	free(buff);
    return(0);
}