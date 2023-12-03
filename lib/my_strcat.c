/*
** EPITECH PROJECT, 2023
** strcat
** File description:
** concatenate two strings
*/

#include <stdlib.h>
#include <string.h>
#include "my.h"

char *my_strcat(const char *left, const char *right)
{
    const size_t len = strlen(left) + strlen(right);
    char *new = malloc(sizeof(char) * (len + 1));
    int i = 0;
    int j = 0;

    if (!left || !right || !new)
        return (NULL);
    for (; left[i]; i++)
        new[i] = left[i];
    for (; right[j]; i++, j++)
        new[i] = right[j];
    new[i] = '\0';
    return (new);
}
