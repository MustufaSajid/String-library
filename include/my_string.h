#ifndef __MY_STRING_H__
#define __MY_STRING_H__

/**
 * @file my_string.h
 * @brief A simple string Library.
 * 
 * @warning This library is NOT thread-safe. Do not use it in multithreaded contexts
 */

#include <stddef.h>

/**
 * @brief Compare two strings.

 * Compares str1 and str2 lexicographically.

 * @param str1 First string to compare
 * @param str2 Second string to compare
 * @return 0 if strings are equal, negative if str1 < str2, positive if str1 > str2
 * @warning NOT thread-safe
 */
int my_strcmp(const char *str1, const char *str2);

/**
 * @brief Copy a string.
 * Copies the null-terminated string from Source to Destination.
 * @param Destination Buffer to copy string to (must not be NULL)
 * @param Source String to copy from (must not be NULL)
 * @return Pointer to Destination on success, NULL on invalid input
 * @warning NOT thread-safe. Caller must ensure Destination is large enough.
 */
char *my_strcpy(char *Destination, const char *Source);

/**
 * @brief Concatenate two strings with size checking.
 * Appends src to dest, ensuring the resulting string fits in the dest buffer.
 * @param dest Destination buffer (must be null-terminated)
 * @param src Source string to append
 * @param dest_size Size of the destination buffer
 * @return 0 on success, -1 if string was truncated, -2 on invalid input
 * @warning NOT thread-safe
 */
int my_strcat(char *dest, const char *src, size_t dest_size);

/**
 * @brief Compare two strings up to n characters.
 * Compares at most index characters of str1 and str2.
 * @param str1 First string to compare
 * @param str2 Second string to compare
 * @param index Maximum number of characters to compare
 * @return 0 if first index characters are equal, negative if str1 < str2, 
 *         positive if str1 > str2, -1 on NULL input
 * @warning NOT thread-safe
 */
int my_strncmp(const char *str1, const char *str2, size_t index);

/**
 * @brief Copy at most n characters from src to dest.
 * Copies up to n characters from src to dest, padding with null bytes if needed,
 * and ensuring null-termination within dest_size.
 * @param dest Destination buffer (must not be NULL)
 * @param src Source string (must not be NULL)
 * @param n Maximum number of characters to copy
 * @param dest_size Size of destination buffer
 * @return Pointer to dest on success, NULL on invalid input
 * @warning NOT thread-safe. Caller must ensure dest_size is sufficient.
 */
char *my_strncpy(char *dest, const char *src, size_t n, size_t dest_size);

/**
 * @brief Reverse a string in place.
 * Reverses the characters in the given string in place.
 * @param str String to reverse (must not be NULL)
 * @return 0 on success, -1 if str is NULL
 * @warning NOT thread-safe. Modifies the string in place.
 */
int reverse(char *str);

/**
 * @brief Split a string by a delimiter.
 * Splits the string str by the delimiter character delim, returning an array
 * of pointers to newly allocated strings. The array is NULL-terminated.
 * @param str String to split (must not be NULL)
 * @param delim Character delimiter
 * @return Dynamically allocated array of strings, or NULL on invalid input.
 *         Must be freed with free_split().
 * @warning NOT thread-safe. Caller must free the result with free_split().
 *          Each string in the array is separately allocated on the heap.
 */
char **my_split(const char *str, char delim);

/**
 * @brief Free memory allocated by my_split().
 * Frees all strings in the array and the array itself.
 * @param arr Array of strings returned by my_split() (NULL-safe, returns if NULL)
 * @warning NOT thread-safe.
 */
void free_split(char ***arr);

#endif 
