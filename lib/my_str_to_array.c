/*
** EPITECH PROJECT, 2023
** my_str_to_array.c
** File description:
** str to array with delim
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

static int its_delim(const char *str, int i, const char *delim)
{
    if (skip_delim(str[i], delim)) {
        for (; skip_delim(str[i], delim); i++);
        i--;
    }
    return (i);
}

static int count_word(const char *str, const char *delim)
{
    int nb_words = 1;

    if (!str)
        return (0);
    for (int i = 0; str[i]; i++, nb_words++)
        i = its_delim(str, i, delim);
    return (nb_words / 2);
}

static int len_word(const char *str, int i, const char *delim)
{
    int len_word = 0;

    for (; !skip_delim(str[i], delim) && str[i]; len_word++, i++);
    return (len_word);
}

char **my_str_to_array(const char *str, const char *delim)
{
    const size_t nb_words = count_word(str, delim);
    char **array = malloc(sizeof(char *) * (nb_words + 1));
    int i = 0;
    int line = 0;

    if (!str || !array || !nb_words) {
        free(array);
        return (NULL);
    }
    for (int c = 0; str[i]; c = 0, line++) {
        while (skip_delim(str[i], delim) && str[i++]);
        array[line] = malloc(sizeof(char) * (len_word(str, i, delim) + 1));
        for (; !skip_delim(str[i], delim) && str[i]; i++ , c++)
            array[line][c] = str[i];
        array[line][c] = '\0';
        while (skip_delim(str[i], delim) && str[i++]);
    }
    array[line] = NULL;
    return (array);
}
