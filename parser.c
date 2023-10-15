#include "main.h"

/**
 * cmd_parser - parse through the tokens to find a command
 * @command: pointer to a command
 * @args: pointer to an array of strings
 * @counter: counts the args
 * Return: Nothing.
 */
void cmd_parser(char *command, char **args, int *counter)
{
	char *token = strtok(command, " \n");
	*counter = 0;

	while (token != NULL && *counter < 127)
	{
		args[(*counter)++] = token;
		token = strtok(NULL, " \n");
	}
	args[*counter] = NULL;
}

