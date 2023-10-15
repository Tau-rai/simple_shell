#include "main.h"
/**
 * shell_fork - creates a child process that executes inputted commands
 * @args: an array the stores the inputted commands
 * @env: environment array
 * @shell_name: name of the shell
 */
void shell_fork(char **args, char **env, char *shell_name)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
		perror(shell_name);
	if (pid == 0)
	{
		if (execve(args[0], args, env) == -1)
			perror(shell_name);
	}
	else
	{
		wait(&status);
		free_args(args);
	}
	return;
}
