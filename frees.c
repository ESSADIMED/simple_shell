#include "shell.h"

/**
  * frees_get_env - ...
  *@env_path: to frees The environment variable 
  *
  * Return: Nothing to returns
  */
void frees_get_env(char *env_path)
{
	int i;

	for (i = 4; i >= 0; i--)
		env_path--;

	free(env_path);
}

/**
  * frees_tokens - ...
  * @tokns: ...
  *
  * Return: Nothing to returns
  */
void frees_tokens(char **tokns)
{
	char **temp = tokns;

	if (tokns)
	{
		while (*tokns)
			free(*tokns++);

		free(temp);
	}
}
