#include "shell.h"

/**
  * main - to enter to the Shell
  *
  * Return: 0
  */
int main(void)
{
	char *line_cmd = NULL, **u_tokns = NULL;
	ssize_t len_ofLine = 0;
	size_t line_size = 0;
	int w_len = 0, execFlag = 0;	

	while (len_ofLine >= 0)
	{
		signal(SIGINT, sig_hdl);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);
		len_ofLine = getline(&line_cmd, &line_size, stdin);
		if (len_ofLine == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		w_len = count_input(line_cmd);
		if (line_cmd[0] != '\n' && w_len > 0)
		{
			u_tokns = tokenize(line_cmd, " \t", w_len);
			execFlag = execBuiltInCommands(u_tokns, line_cmd);
			if (!execFlag)
			{
				u_tokns[0] = find(u_tokns[0]);
				if (u_tokns[0] && access(u_tokns[0], X_OK) == 0)
					exec(u_tokns[0], u_tokns);
				else
					perror("./hsh");
			}

			frees_tokens(u_tokns);
		}
	}

	free(line_cmd);
	return (0);
}
