#include "../include/my_string.h"

int my_strcmp(const char *str1, const char *str2) {
  int i = 0;
  while (str1[i] != '\0' && str2[i] != '\0') {
    if (str1[i] != str2[i]) {
      return str1[i] - str2[i];
    }
    i++;
  }
  return (unsigned char)str1[i] - (unsigned char)str2[i];
  ;
}
int my_strncmp(const char *str1, const char *str2, size_t index) {
  if (str1 == NULL || str2 == NULL) {
    return -1;
  }

  size_t i = 0;

  while (i < index && str1[i] && str1[i] == str2[i]) {
    i++;
  }

  if (i == index)
    return 0;

  return (unsigned char)str1[i] - (unsigned char)str2[i];
}

char *my_strcpy(char *Destination, const char *Source) {
  if (Destination == NULL || Source == NULL)
    return NULL;

  int i;
  for (i = 0; Source[i] != '\0'; i++) {
    Destination[i] = Source[i];
  }
  Destination[i] = '\0';
  return Destination;
}
char *my_strncpy(char *dest, const char *src, size_t n, size_t dest_size) {
  if (dest == NULL || src == NULL) {
    return NULL;
  }
  size_t i;
  if (n == 0)
    return dest;
  for (i = 0; i < n && i < dest_size - 1 && src[i] != '\0'; i++)
    dest[i] = src[i];

  if (i < dest_size)
    dest[i] = '\0';
  // Pad the rest if source shorter than n and buffer allows
  for (; i < dest_size && i < n; i++)
    dest[i] = '\0';

  return dest;
}
int my_strcat(char *dest, const char *src, size_t dest_size) {
  if (!dest || !src || dest_size == 0)
    return -2; // invalid input

  // Find current length of dest safely
  size_t dest_len = 0;
  while (dest_len < dest_size && dest[dest_len] != '\0') {
    dest_len++;
  }

  if (dest_len == dest_size)
    return -1; // dest not null-terminated

  size_t i = 0;

  while (dest_len + i < dest_size - 1 && src[i] != '\0') {
    dest[dest_len + i] = src[i];
    i++;
  }

  dest[dest_len + i] = '\0';

  return (src[i] == '\0') ? 0 : -1;
}
int reverse(char *str) {
  if (str == NULL)
    return -1;
  char *start = str;
  char *end = str;
  while (*end != '\0') {
    end++;
  }
  end--;
  while (start < end) {
    char temp = *start;
    *start = *end;
    *end = temp;
    start++;
    end--;
  }

  return 0;
}

static int count_words(const char *str, char delim) {
  int count = 0;
  int in_word = 0;

  while (*str) {
    if (*str != delim && !in_word) {
      in_word = 1;
      count++;
    } else if (*str == delim) {
      in_word = 0;
    }
    str++;
  }

  return count;
}

char **my_split(const char *str, char delim) {
  if (!str) {
    return NULL;
  }
  int words = count_words(str, delim);
  char **result = malloc(sizeof(char *) * (words + 1));
  int i = 0;
  while (*str) {
    if (*str == delim) {
      str++;
      continue;
    }
    size_t len = 0;
    const char *start = str;
    while (*str && *str != delim) {
      len++;
      str++;
    }
    result[i] = malloc(len + 1);
    if (result[i] == NULL) {
      printf("Malloc failed\n");
    }
    strncpy(result[i], start, len);
    result[i][len] = '\0';
    i++;
  }
  result[i] = NULL;
  return result;
}

void free_split(char **arr) {
  for (int i = 0; arr[i] != NULL; i++)
    free(arr[i]);

  free(arr);
}
