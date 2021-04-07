#ifndef HOLBERTON_H
#define HOLBERTON_H
#define _GNU_SOURCE
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>

extern char **environ;
int _strlen(char *str);
int _putchar(char c);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);

#endif
