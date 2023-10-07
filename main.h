#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int _strcmp(const char *str1, const char *str2);
size_t _strlen(const char *str);
char *_strcpy(char *dest, const char *src);
char *_strdup(const char *src);
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);


#endif /* MAIN_H */
