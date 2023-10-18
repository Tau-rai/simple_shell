#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <stddef.h>
#include <errno.h>

#define BUFF_SIZE 1024

extern char *cmd;

int _strcmp(const char *str1, const char *str2);
size_t _strlen(const char *str);
char *_strcpy(char *dest, const char *src);
char *_strdup(const char *src);
char *_getenv(const char *name, char **envp);
char *_strchr(const char *str, int c);
char *_strcat(char *dest, const char *src);
void *_memcpy(void *dest, const void *src, size_t n);
int _setenv(const char *name, const char *value, int overwrite);
void cmd_parser(char *command, char **args, int *counter);
void cmd_executor(char **args, const char *path, char *argv[]);
void handle_env(char **envp);
void fork_cmd(char *command, char *argv[]);
char *get_path(const char *dir, const char *command);
void print_error(char *name, char *command, char *message);
char *_strtok(char *s, const char *delim);
char *_getline(char **line, size_t  *l_size, FILE *stream);
int _atoi(char *strtoint);
void handle_exit(char *status);
int _strncmp(const char *str1, const char *str2, size_t n);
int get_numargs(char *cmdcpy);
void displayenv(char **env);
void shell_fork(char **args, char **env, char *shell_name, char *path);
int check_cmd(char *cmd, char **envp, char *name);
void free_args(char **args);
void handlesignal(int signum);
/**
 * struct path_node - contains a dir for the path variable
 * @dir: path
 * @next: address of the following node
 *
 */
struct path_node
{
	char *dir;
	struct path_node *next;
};
char *check_path(char *token, const struct path_node *head);
int pop_args(char **args, char *cmd, char *shell_name);
void freelist(struct path_node *head);
struct path_node *add_node(struct path_node **head, char *token);
struct path_node *add_list(char **env);
#endif /* MAIN_H */
