#include "holberton.h"

/**
 *counter - function to count words
 *@words: the strings given to separate by " ".
 *Return: number of words
 */
int counter(char *words)
{
	int i, count = 0;

	for (i = 0; words[i]; i++)
	{
		if (words[i] == 32 && words[i + 1] != 32 && (words[i + 1]) != '\0')
			count++;
		if (words[0] != 32)
			count++;
	}
	printf("%d\n", count);
	return (count);
}
int main (void)
{
	char *words = "me la suda malparida cosa";
	int total_words;
	printf("")
	total_words = counter(words);

	printf("%d words were found\n", total_words);
	return (total_words);

}

