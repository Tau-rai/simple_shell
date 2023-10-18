#include "main.h"
/**
 * shell_fork - creates a child process that executes inputted commands
 * @args: an array the stores the inputted commands
 * @env: environment array
 * @shell_name: name of the shell
 * @path: path of command in args[0]
 */
void shell_fork(char **args, char **env, char *shell_name, char *path)
{
	pid_t pid;
	int status;

	if (path == NULL)
	{
		print_error(shell_name, args[0], ": command not found\n");
		free_args(args);
		return;
	}
	pid = fork();
	if (pid == -1)
	{
		perror(shell_name);
		free(path);
		free(args);
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (execve(path, args, env) == -1)
			print_error(shell_name, args[0], ": No such file or directory\n");
		free(path);
		free(args);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (wait(&status) == -1)
		{
			perror(shell_name);
			free(path);
			free(args);
			exit(EXIT_FAILURE);
		}
		free(path);
		free(args);
	}
}
