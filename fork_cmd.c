#include "main.h"

/**
 * fork_cmd - forks and executes commands from terminal
 * @command: exxcutables from the terminal
 * @argv: an array of strings
 * Return:nothing
 */
void fork_cmd(char *command, char *argv[])
{
	pid_t pid;
	char *path;
	char *args[128];
	int counter, k, status;

	pid = fork();
	if (pid == -1)
	{
		perror("Error: Failed to fork");
		exit(1);
	}
	else if (pid == 0)
	{
		path = _getenv("PATH");
		cmd_parser(command, args, &counter);
		cmd_executor(args, path, argv);

		for (k = 0; k < counter; k++)
			free(args[k]);
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			exit(1);
		}
	}
}
