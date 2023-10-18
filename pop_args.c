#include "main.h"

/**
 * pop_args - populates array
 * @args: args array
 * @cmd: command whose tokens are elements of array
 * @name: name of shell
 * Return: returns 0 if array populated else -1 if err
 */
int pop_args(char **args, char *cmd, char *name)
{
	char *token;
	int i = 0;

	if (args == NULL)
	{
		perror(name);
		return (-1);
	}
	token = strtok(cmd, " \n");
	while (token != NULL)
	{
		args[i] = _strdup(token);
		if (args[i] == NULL)
		{
			perror(name);
			return (-1);
		}
		token = strtok(NULL, " \n");
		i++;
	}
	args[i] = NULL;
	return (0);
}
