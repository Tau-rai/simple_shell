#include "main.h"

/**
 * handle_env - handles the environ variable
 * @envp: the environment array
 * Return: Nothing
 */
void handle_env(char **envp)
{
	char **env = envp;
	char newline = '\n';

	while (*env)
	{
		write(STDOUT_FILENO, *env, _strlen(*env));
		write(STDOUT_FILENO, &newline, 1);
		env++;
	}
}

