#include "shell.h"

/**
 * execBuiltInCommands - Executes a built-in command
 * @u_tokns: ...
 * @line: ...
 *
 * Return: 1 if is a built-in command or 0 if not
 */
int execBuiltInCommands(char **u_tokns, char *line)
{
        char *bar = line;
	int i = 0;
	char *ListBuiltinCmds[] = { "env", "help", "cd", "exit", NULL };

	while (ListBuiltinCmds[i])
	{
		if (_strcmp(u_tokns[0], ListBuiltinCmds[i]) == 0)
		{
			switch (i)
			{
				case 0:
				        _print_env();
					return (1);
				case 1:
					_open_help();
					return (1);
				case 2:
				    chdir(u_tokns[1]);
					return (1);
				case 3:
					_handle_exit(u_tokns, line);
					default:
					break;
			}
		}
		i++;
		bar++;
	}

	return (0);
}
