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
		exit_status = _atoi(status);
	free(status);
	exit(exit_status);
}
