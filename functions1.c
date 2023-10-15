#include "main.h"

/**
 * _strchr - locates a character in a string
 * @str: pointer to a string
 * @c: character to be located
 * Return: a pointer to the first occurance of the char
 */
char *_strchr(const char *str, int c)
{
	while (*str != '\0' && *str != c)
	{
		str++;
	}
	if (*str == c)
	{
		return ((char *)str);
	}
	else
	{
		return (NULL);
	}
}
/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 * Return: pointer to the new string
 */
char *_strcat(char *dest, const char *src)
{
	char *ptr = dest + _strlen(dest);

	while (*src != '\0')
	{
		*ptr++ = *src++;
	}
	*ptr = '\0';
	return (dest);
}

/**
 * print_error - prints out the error message
 * @argv: array of strings
 * @args: array of arguments
 * @message: the error msg
 * Return: Nothing
 */

void print_error(char *argv[], char *args[], char *message)
{
	write(STDERR_FILENO, argv[0], _strlen(argv[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, args[0], _strlen(args[0]));
	write(STDERR_FILENO, message, _strlen(message));
}
/**
 * _strtok - tokenizes a string
 * @s: pointer to a string
 * @delim: the delimiter
 * Return: tokenized strings
 */
char *_strtok(char *s, const char *delim)
{
	static char *ptr;
	char *start = s;

	if (!s)
		s = ptr;
	/*skip leading delims*/
	while (*s && _strchr(delim, *s))
		s++;

	if (!*s)
		return (NULL);/* if no more token */

	start = s; /* start of the token*/
	while (*s && !_strchr(delim, *s))
		s++;

	ptr = NULL;
	if (*s) /* if delim is present at end of token, null-terminate*/
	{
		ptr = s + 1;
		*s = '\0';
	}
	else
		ptr = s;

	return (start);
}

/**
 * _strncmp - compares the first n bytes of str1 and str2
 * @str1: is the first string
 * @str2: is the second string
 * @n: an integer value
 * Return: Returns an integer value
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	while (n > 0 && *str1 && *str1 == *str2)
	{
		str1++;
		str2++;
		n--;
	}
	if (n  == 0)
		return (0);

	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}
