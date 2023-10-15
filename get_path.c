#include "main.h"

/**
 * get_path - constructs the full path
 * @dir: each directory in the path
 * @command: command to be executed
 * Return: pointer to the full path
 */
char *get_path(const char *dir, const char *command)
{
	size_t len = _strlen(dir) + _strlen(command) + 2;
	char *full_path = (char *)malloc(len);

	if (full_path == NULL)
	{
		perror("Error: Failed to allocate memory");
		exit(1);
	}

	_strcpy(full_path, dir);
	_strcat(full_path, "/");
	_strcat(full_path, command);

	return (full_path);
}
