#include "shell.h"

/**
  * sig_hdl - Handles the signals
  * @sig_id: The identifier of the signal to handle
  *
  * Return: Nothing to returns
  */
void sig_hdl(int sig_id)
{
	if (sig_id == SIGINT)
		write(STDOUT_FILENO, "\n($) ", 5);
}
