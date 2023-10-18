#include "main.h"

char *_getline(char **line, size_t *l_size, FILE *stream);
/**
 * _getline - reads input from stdin one char at a time
 * @line: pointer to an array of chars
 * @l_size: an integer size of string buffer
 * @stream: input from the user
 * Return: pointer to a string buffer
 */
char *_getline(char **line, size_t *l_size, FILE *stream)
{
	static char buffer[BUFF_SIZE];
	static int buff_indx;
	static int buff_size;

	size_t l_indx = 0;
	size_t k;
	char cread;
	char *temp;
	buff_indx = 0;
	buff_size = 0;

	while (1)
	{
		if (buff_indx >= buff_size)
		{
			buff_size = read(fileno(stream), buffer, BUFF_SIZE); /* read user input*/
			buff_indx = 0;
			if (buff_size == 0)
			{
				if (l_indx == 0)
					return (NULL);

				if (*line != NULL)
					(*line)[l_indx] = '\0';

				return (*line); /* End of input, return the line */
			}
		}

		cread = buffer[buff_indx++];
		/* check if line buffer is too small*/
		if (l_indx + 1 >= *l_size)
		{
			*l_size = (*l_size == 0) ? 64 : *l_size * 2;
			temp = (char *)malloc(*l_size); /*allocate a new buffer*/
			if (temp == NULL)
			{
				perror("Failed to allocate memory");
				exit(1);
			}
			if (*line != NULL)
			{
				for (k = 0; k < l_indx; k++)
					temp[k] = (*line)[k]; /* copy data to new buffer */

				free(*line);
			}
			*line = temp;
		}

		(*line)[l_indx++] = cread;
		if (cread == '\n')
		{
			(*line)[l_indx] = '\0';
			return (*line);
		}
	}
}
