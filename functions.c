#include "main.h"

/**
 * _strlen - calculate the length of a string
 *  @str: pointer to a string
 * Return: the length of the string
 */
size_t _strlen(const char *str)
{
        const char *s = str;

        while (*s)
                s++;

        return (s - str);
}

/**
 * _strcmp - compares two strings
 * @str1: pointer a string
 * @str2: pointer a string
 * Return: 0 Success.
 */
int _strcmp(const char *str1, const char *str2) {
        while (*str1 != '\0' && *str2 != '\0') {
                if (*str1 != *str2) {
                        return (*str1 - *str2);
                }
                str1++;
                str2++;
        }

        return (*str1 - *str2);
}
/**
 * _strdup - duplicates a string
 * @src: pointer to a string
 * Return: pointer to a new string
 */
char *_strdup(const char *src)
{
        size_t len;
        char *dest;

        if (src == NULL)
                return (NULL);

        len = _strlen(src) + 1;
        dest = (char *)malloc(len);

        if (dest == NULL)
                return (NULL);

        _strcpy(dest , src);

        return (dest);
}

/**
 * _strcpy - copies one string into another
 * @dest: pointer to a string
 * @src: pointer to a source string
 * Return: new string 
 */
char *_strcpy(char *dest, const char *src)
{
        char *new_str = dest;

        while (*src != '\0')
        {
                *dest = *src;
                dest++;
                src++;
        }
        *dest = '\0';

        return (new_str);
}
