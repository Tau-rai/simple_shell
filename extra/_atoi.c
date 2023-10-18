#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @str: pointer to a string
 * Return: an integer
*/
int _atoi(char *str)
{
    int sign = 1;
    int num = 0;

    while (!(*str >= '0' && *str <= '9') || (*str != '-' && *str != '+'))
    {
        str++;
    }

    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    else if (*str == '+')
        str++;

    while (*str >= '0' && *str <= '9')
    {
        num = num * 10 + (*str - '0');
        str++;
    }
    printf("num is -> %d", num);
    return (sign * num);
}