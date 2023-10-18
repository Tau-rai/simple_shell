#include "main.h"
#include <unistd.h>

/**
 * _atoi - converts a string into an int
 * @s: string that is converted
 *
 * Return: returns the converted int
 */
int _atoi(char *s)
{
	int len = 0;
	int a;
	unsigned int num = 0;
	int cal;
	int neg = 0;

	while (s[len] != '\0')
		len++;

	for (a = 0; a < len; a++)
	{
		if (s[a] == '-')
		{
			neg++;
		}
		else if ((s[a] >= 48) && (s[a] < 58))
		{
			while ((s[a] >= 48) && (s[a] < 58))
			{
				cal = s[a] - 48;
				num = (num * 10) + cal;
				a++;
			}
			break;
		}
	}
	if ((neg % 2) != 0)
		num = -num;
	return (num);
}
