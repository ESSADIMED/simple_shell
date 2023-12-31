#include "shell.h"

/**
  * remove_new_line - Removes a new line character from string
  * @str: string
  *
  * Return: string without a new line character "\n"
  */
char *remove_new_line(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}

	return (str);
}
