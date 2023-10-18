#include "main.h"

int _setenv(const char *name, const char *value, int overwrite);
/**
 * _setenv - changes or add an enviro variaable
 * @name: pointer to the name of the env
 * @value: pointer to the value of the env
 * @overwrite: an integer value
 * Return: Always 0 Success.
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	size_t env_len = 0;
	size_t len;
	char *env, *tmp;
	char **new_env;

	if (name == NULL || name[0] == '\0' || _strchr(name, '=') != NULL)
	{
		write(STDERR_FILENO, "Error: Failed to allocate memory\n", 29);
		return (-1);
	}
	len = _strlen(name) + _strlen(value) + 2;
	env = malloc(len);

	if (env == NULL)
	{
		write(STDERR_FILENO, "Error: Failed to allocate memory\n", 29);
		return (-1);
	}

	tmp = env;
	while (*name != '\0')
		*tmp++ = *name++;

	*tmp++ = '=';

	while (*value != '\0')
		*tmp++ = *value++;

	*tmp = '\0';

	if (_getenv(name) != NULL && !overwrite)
	{
		free(env);
		return (0);
	}

	while (environ[env_len] != NULL)
		env_len++;

	new_env = malloc((env_len + 2) * sizeof(char *));
	if (new_env == NULL)
	{
		free(env);
		write(STDERR_FILENO, "Error: Failed to allocate memory\n", 29);
		return (-1);
	}

	_memcpy(new_env, environ, env_len * sizeof(char *));
	new_env[env_len] = env;
	new_env[env_len + 1] = NULL;

	environ = new_env;

	return (0);
}

