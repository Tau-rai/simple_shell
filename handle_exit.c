#include "main.h"

/**
 * handle_exit - handles the built-in exit shell command
 * @status: pointer to a string
 * Return: an integer value
 */
void handle_exit(char *status)
{
	int exit_status = 0;

	if (status != NULL)
	{
		exit_status = _atoi(status);
		if (exit_status < 0 || exit_status > 255)
		{
			perror(" Invalid exit status");
			exit(1);
		}
	}
	else
		exit(127);

	free(status);
	exit(exit_status);
}
