#include "main.h"

/**
 * handle_builtins - handles the built in functions
 * @cmd: pointer to the command arg
 * @env: pointer to the env var arg
 * @shell_name: the nam eof the shell
 * Return: Nothing
 */
int handle_builtins(char *cmd, char **env, char *shell_name)
{

	if (_strcmp(cmd, "env\n") == 0)
	{
		handle_env(env);
		return (1);
	}
	else if (_strncmp(cmd, "exit", 4) == 0)
	{
		handle_exit(cmd);
		return (1);
	}
	else if (_strncmp(cmd, "cd", 2) == 0)
	{
		handle_cd(cmd, env);
		return (1);
	}
	return (0);
}
