#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t my_pid;/*type: pid_t */

    my_pid = getpid();
    printf("%u\n", my_pid);/* %u for unsigned int*/
    return (0);
}