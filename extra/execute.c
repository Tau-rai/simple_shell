#include "main.h"

/**
 * cmd_executor - executes the commands
 * @args: an array of strings
 * @argv: an array of strings
 * @path: value of the PATH environ variable
 * Return: Nothing
 */
void cmd_executor(char **args, const char *path, char *argv[])
{
	char *token, *path_copy;
	char *full_path = NULL;

	/* if args[0] contains a slash, attempt to execute it directly*/
	if (_strchr(args[0], '/'))
	{
		if (execve(args[0], args, environ) == -1)
		{
			print_error(argv, args, ": No such file or directory\n");
			exit(1);
		}
	}
	else
	{
		path_copy = _strdup(path);
		token = _strtok(path_copy, ":");

		while (token != NULL)
		{
			full_path = get_path(token, args[0]);
			/* check if executable exists in the directory*/
			if (access(full_path, X_OK) == 0)
			{
				/* execute command */
				if (execve(full_path, args, NULL) == -1)
				{
					print_error(argv, args, ": No such file or directory\n");
					exit(1);
				}
			}
			free(full_path);
			token = _strtok(NULL, ":");
		}
		free(path_copy);
	}
	write(STDERR_FILENO, args[0], _strlen(args[0]));
	write(STDERR_FILENO, ": command not found\n", 21);
	exit(1);
}
