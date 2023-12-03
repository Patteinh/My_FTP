/*
** EPITECH PROJECT, 2023
** my_clean_str.c
** File description:
** remove unwanted letters from string
*/

#include <stdlib.h>
#include <stddef.h>

static int skip_delim(const char c, const char *delim)
{
    for (int i = 0; delim[i]; i++)
        if (c == delim[i])
            return (1);
    return (0);
}

static int count_letter(const char *str, const char *delim)
{
    size_t nb_letters = 0;

    if (!str)
        return (0);
    for (int i = 0; str[i]; i++)
        if (!skip_delim(str[i], delim))
            nb_letters++;
    return (nb_letters);
}

char *my_clean_str(const char *str, const char *delim)
{
    const size_t len = count_letter(str, delim);
    char *new = malloc(sizeof(char) * (len + 1));
    int i = 0;
    int j = 0;

    if (!str || len == 0) {
        free(new);
        return (NULL);
    }
    while (str[i]) {
        for (; str[i] && skip_delim(str[i], delim); i++);
        for (; str[i] && !skip_delim(str[i], delim); i++, j++)
            new[j] = str[i];
    }
    new[j] = '\0';
    return (new);
}
