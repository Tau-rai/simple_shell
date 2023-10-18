#include "main.h"

int get_numargs(char *cmdcpy);
/**
 * check_cmd - starts analysing possible routes of how to execute given command
 * @cmd: command
 * @env: the current environment array
 * @shell_name: the name of the shell
 * Return: return 0 if success, 1 if continue, 2 if break;
 */
int check_cmd(char *cmd, char **env, char *shell_name)
{
	int num_args;
	char **args;
	int r;
	char *cmdcpy;
	struct path_node *head;

	if (handle_builtins(cmd, env, shell_name))
	{
		return (1);
	}

	cmdcpy = _strdup(cmd);
	if (cmdcpy == NULL)
	{
		perror("Error: Memory allocation failed");
		return (1);
	}
	num_args = get_numargs(cmdcpy);
	if (num_args != 0)
	{
		head = add_list(env);
		args = malloc(sizeof(char *) * (num_args + 1));

		if (args == NULL)
		{
			perror("Error: Failed to allocate memory");
			free(cmdcpy);
			return (1);
		}
		r = pop_args(args, cmd, shell_name);
		if (r == -1)
		{
			free_args(args);
			freelist(head);
			free(cmdcpy);
			return (1);
		}
		shell_fork(args, env, shell_name, check_path(args[0], head));
		freelist(head);
	}
	free(cmdcpy);
	return (1);
}

/**
 * get_numargs - get the number of arguments in command
 * @cmdcpy: a copy of the command
 *
 * Return: returns the number of args
 */
int get_numargs(char *cmdcpy)
{
	int num_args = 0;
	char *token;

	token = strtok(cmdcpy, " \n");
	while (token)
	{
		num_args++;
		token = strtok(NULL, " \n");
	}
	return (num_args);
}
