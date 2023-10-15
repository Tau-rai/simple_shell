#include "main.h"

/**
 * pop_args - populates array
 * @args: args array
 * @cmd: command whose tokens are elements of array
 * @size: size of array
 * @shell_name: name of shell
 *
 * Return: returns 0 if array populated else -1 if err
 */
int pop_args(char **args, char *cmd, int size, char *shell_name, struct path_node *head)
{
	char *token;
	int i = 0;
	struct stat status;
	char *path;
	
	if (args == NULL)
	{
		perror(shell_name);
		return (-1);
	}
	token = strtok(cmd, " \n");
	while(token != NULL)
	{
		if (stat(token, &status) != 0)
		{
			path = check_path(token, head);
			if (path == NULL)
			{
				args[i] = NULL;
				perror(shell_name);
				return (-1);
			}
			args[i] = path;
			token = strtok(NULL, " \n");
			i++;
			continue;
		}
		args[i] = _strdup(token);
		if (args[i] == NULL)
		{
			perror(shell_name);
			return (-1);
		}
		token = strtok(NULL, " \n");
		i++;
	}
	args[i] = NULL;
	return (0);
}
