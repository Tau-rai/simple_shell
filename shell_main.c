#include "main.h"

/**
 * main - responsible for the repetition of a custom shell
 * @argc: number of arguments
 * @argv: command line argumnet array
 * @envp: enviroment variable array
 *
 * Return: return 0
 */
int main(int argc, char **argv, char **envp)
{
	char *cmdprompt = "$ ";
	size_t length = BUFF_SIZE;
	size_t length = BUFF_SIZE;
	ssize_t r;
	int check;
	char *cmd = malloc(sizeof(char) * length);
	char *cmd = malloc(sizeof(char) * length);
	(void)argc;
	/*signal(SIGINT, handlesignal);*/
	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, cmdprompt, 2);
		r = getline(&cmd, &length, stdin);
		if (r <= 0)
		if (r <= 0)
			break;
		check = check_cmd(cmd, envp, argv[0]);
		if (check == 1)
			continue;
		if (check == 2)
			break;
		if (cmd != NULL)
			free(cmd);
		cmd = NULL;
		length = 0;
	}
	if (cmd != NULL)
		free(cmd);
	cmd = NULL;
	length = 0;
	length = 0;
	return (0);
}

/**
 * handlesignal - handles interrupt ctrl-c
 * @signum: signal number of ctrl-c
 */
/*void handlesignal(int signum)
{
	(void)signum;
	if (cmd != NULL)
		free(cmd);
	exit(0);
}*/
