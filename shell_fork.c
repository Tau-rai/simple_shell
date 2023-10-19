#include "main.h"
/**
 * shell_fork - creates a child process that executes inputted commands
 * @args: an array the stores the inputted commands
 * @env: environment array
 * @name: name of the shell
 * @pth: path of command in args[0]
 * @n: points to the number of commands
 * @e: contains exit status
 */
void shell_fork(char **args, char **env, char *name, char *pth, int *n, int *e)
{
	pid_t pid;
	int status;

	(*n)++;
	if (pth == NULL)
	{
		print_error(name, n, args[0], ": not found\n");
		free_args(args);
		*e = 127;
		return;
	}
	pid = fork();
	if (pid == -1)
		perror(name);
	if (pid == 0)
	{
		if (execve(pth, args, env) == -1)
		{
			print_error(name, n, args[0], ": No such file or directory\n");
			*e = 2;
		}
		else
		{
			*e = 0;
		}
	}
	else
	{
		wait(&status);
		free(pth);
		free_args(args);
	}
}

