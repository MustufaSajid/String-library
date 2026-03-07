#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int my_strcmp(const char *str1, const char *str2);
char *my_strcpy(char *Destination, const char *Source);
int my_strcat(char *dest, const char *src, size_t dest_size);
int my_strncmp(const char *str1, const char *str2, size_t index);
char *my_strncpy(char *dest, const char *src, size_t n, size_t dest_size);
int reverse(char *str);
char **my_split(const char *str, char delim);
void free_split(char **arr);
