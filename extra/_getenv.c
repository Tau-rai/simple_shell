#include "main.h"

/**
 * _getenv - gets the environ variable
 * @name: pointer to the environ variable
 * Return: an environ variable
 */
char *_getenv(const char *name)
{
	char **env = environ;
	char *env_var;
	const char *env_name;

	while (*env)
	{
		env_var = *env;
		env_name = name;
		while (*env_var == *env_name && *env_var != '=' && *env_name != '\0')
		{
			env_var++;
			env_name++;
		}
		if (*env_var == '=' && *env_name == '\0')
		{
			return (env_var + 1);
		}
		env++;
	}
	return (NULL);
}


