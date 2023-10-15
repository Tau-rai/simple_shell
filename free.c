#include "main.h"
/**
 * free_args - frees the elements of an array
 * @args: string array
 */
void free_args(char **args)
{
	int i = 0;

	if (args == NULL)
		return;
	while(args[i])
	{
		free(args[i]);
		args[i] = NULL;
		i++;
	}
	free(args);
}

/**
 * freelist - frees the elements of a path linked list
 * @head: the head node of list
 */
void freelist(struct path_node *head)
{
	struct path_node *temp;

	while (head != NULL)
	{
		temp = head;
		head = (head)->next;
		free((temp)->dir);
		free(temp);
	}
}
