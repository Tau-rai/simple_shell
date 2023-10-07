#include "main.h"

#define BUFF_SIZE 1024

int main()
{
	pid_t pid;
	char *command;
	size_t command_size = BUFF_SIZE;
	char *token;
	char *args[128];
	int i = 0, status;
	char cmd[] = "$ ";

	command = (char *)malloc(command_size * sizeof(char));

	while (1)
	{
		write(STDOUT_FILENO, &cmd, 2);
		if (getline(&command, &command_size, stdin) == -1)
		{
			perror("Error: Failled to getline");
			exit(1);
		}

		command[_strlen(command) - 1] = '\0';


		else if (pid == 0)
		{
			i = 0;

			token = strtok(command, " \n");
			while (token != NULL)
			{
				args[i++] = token;
				token = strtok(NULL, " \n");
			}
			args[i] = NULL;


			if (execve(args[0], args, NULL) == -1)
			{
				perror("Failed to execute");
				exit(1);
			}
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

	free(command);

	return 0;
}
