#include "main.h"
/**
 * _getenv - gets the value of environment variable
 * @name: the name of the environment variable
 * @envp: the environment array
 * Return: the pointer to the environment value
*/
char *_getenv(const char *name, char **envp)
{
	char *key;
	char **env = envp;
	char *value;

	while (*env != NULL)
	{
		key = malloc(sizeof(char) * (strlen(*env) + 1));
		if ((strncmp(name, strcpy(key, *env), strlen(name)) == 0)
&& key[strlen(name)] == '=')
		{
			value = malloc(_strlen(key) - _strlen(name) + 1);
			_strcpy(value, key + strlen(name) + 1);
			free(key);
			return (value);
		}
		free(key);
		key = NULL;
		env++;
	}
	return (NULL);
}
