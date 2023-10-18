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
/**
 * handle_cd - handles the built in cd function
 * @cmd: pointer to the command
 * @env: env variavle
 * Return: Nothing
 */
void handle_cd(char *cmd, char **env)
{
	char *home_dir, *cur_dir, *last_dir;
	char *args[128];
	int num_args = pop_args(args, cmd, NULL);

	if (_strcmp(args[1], "~") == 0 || args[1] == NULL)
	{
		home_dir = getenv("HOME");
		if (home_dir)
			chdir(home_dir);
	}
	else if (_strcmp(args[1], "-") == 0)
	{
		last_dir = getenv("OLDPWD");
		if (last_dir)
			chdir(last_dir);
	}
	else
	{
		if (chdir(args[1]) == -1)
		{
			perror("Error: Failed to change dir");
		}
	}
	/* Update the PWD env var */
	cur_dir = getcwd(NULL, 0);
	if (cur_dir)
	{
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cur_dir, 1);
		free(cur_dir);
	}
}
