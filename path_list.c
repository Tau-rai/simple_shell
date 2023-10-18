#include "main.h"
/**
 * add_node - adds a new node to a linked list
 * @head: address of head node
 * @token: token which is used as date for the node
 *
 * Return: returns address of node which becomes the head node
 */
struct path_node *add_node(struct path_node **head, char *token)
{
	struct path_node *new;
	char *path = malloc(_strlen(token) + _strlen("/") + 1);

	_strcpy(path, token);
	_strcat(path, "/");
	new = malloc(sizeof(struct path_node));
	if (new == NULL)
		return (NULL);
	new->dir = path;
	new->next = *head;
	*head = new;
	return (*head);
}

/**
 * add_list - creates a linked list from the value of path variable
 * @env: the environment array
 * Return: returns the address of the head node
 */
struct path_node *add_list(char **env)
{
	char *value;
	char *token;
	struct path_node *head = NULL;

	value = _getenv("PATH", env);
	token = strtok(value, ":");
	while (token != NULL)
	{
		add_node(&head, token);
		token = strtok(NULL, ":");
	}
	free(value);
	return (head);
}
/**
 * check_path - checks whether a token represents a valid file/command
 * @token: token containing potential command/file
 * @head: head node of a path linked list
 *
 * Return: the token if the value is a option flag/ path of command else NULL
 */
char *check_path(char *token, const struct path_node *head)
{
	char *path;
	struct stat status;

	if (_strchr(token, '/'))
		return (_strdup(token));
	while (head != NULL)
	{
		path = malloc(_strlen(head->dir) + _strlen(token) + 1);
		_strcpy(path, head->dir);
		_strcat(path, token);
		if (stat(path, &status) == 0)
			return (path);
		free(path);
		path = NULL;
		head = head->next;
	}
	return (NULL);
}
