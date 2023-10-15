#include "main.h"

/**
 * handle_env - handles the environ variable
 * Return: Nothing
 */
void handle_env(void)
{
	char **env = environ;

	while (*env)
	{
		write(STDOUT_FILENO, *env, _strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}

