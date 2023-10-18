#include "main.h"

/**
 * main - entry point
 * @argv: array of strings
 * @argc: number of arguments
 * Return: Always 0 Success.
 */
int main(__attribute__((unused))int argc, char *argv[])
{
	char *command;
	char *stat_arg;
	size_t command_size = BUFF_SIZE;
	char cmd[] = "$ ";
	ssize_t r_size;

	command = (char *)malloc(command_size * sizeof(char));

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			/* only print prompt if input comes from terminal*/
			write(STDOUT_FILENO, &cmd, 2);
		}
		r_size = (ssize_t)_getline(&command, &command_size, stdin);

		if (r_size <= 0)
			break; /* handle end of file*/

		command[_strlen(command) - 1] = '\0';

		if (_strcmp(command, "exit") == 0)
		{
			handle_exit(NULL);
		}
		else if (_strncmp(command, "exit ", 5) == 0)
		{
			stat_arg = command + 5;
			handle_exit(stat_arg);
		}
		else if (_strcmp(command, "env") == 0)
		{
				handle_env(); /* handle env command */
		}
		else
			fork_cmd(command, argv);

		free(command);  /*free memory before getting next command*/
		 command = NULL;
		 command_size = 0;
	}
	free(command);
	return (0);
}
