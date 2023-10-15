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

extern char **environ;

int _strcmp(const char *str1, const char *str2);
size_t _strlen(const char *str);
char *_strcpy(char *dest, const char *src);
char *_strdup(const char *src);
char *_getenv(const char *name);
char *_strchr(const char *str, int c);
char *_strcat(char *dest, const char *src);
void *_memcpy(void *dest, const void *src, size_t n);
int _setenv(const char *name, const char *value, int overwrite);
void cmd_parser(char *command, char **args, int *counter);
void cmd_executor(char **args, const char *path, char *argv[]);
void handle_env(void);
void fork_cmd(char *command, char *argv[]);
char *get_path(const char *dir, const char *command);
void print_error(char *argv[], char *args[], char *message);
char *_strtok(char *s, const char *delim);
char *_getline(char **line, size_t  *l_size, FILE *stream);
void handle_exit(char *status);
int _strncmp(const char *str1, const char *str2, size_t n);

#endif /* MAIN_H */
