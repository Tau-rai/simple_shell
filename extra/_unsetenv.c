#include "main.h"

/**
 * _unsetenv - deletes the variable name from  the  environment
 * @name: the name of the variable
 * Return: Always 0 Success.
*/
int _unsetenv(const char *name)
{
    int k, j, found = 0;

    if (name == NULL || name[0] == '\0' || _strchr(name, '=' != NULL))
    {
        write(STDERR_FILENO, "Error: Invalid variable name\n", 29);
        return (-1);
    }

    while (environ[k] != NULL)
    {
        if (_strncmp(environ[k], name, _strlen(name)) == 0 && environ[k][_strlen(name)] == '=')
        {
            /*path found remove variable*/
            free(environ[k]);

            j = k;
            while (environ[j] != NULL)
            { /* shift remaining vars to the left*/
                environ[j] = environ[j + 1];
                j++;
            }
            found = 1;
            break;
        }
        k++;
    }
    if (!found)
    {
        write(STDERR_FILENO, "Error: Variable not found\n", 28);
        return (-1);
    }
    
    return (0);
}