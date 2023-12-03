/*
** EPITECH PROJECT, 2023
** my_strlen_array
** File description:
** count line in array
*/

#include <stddef.h>

int my_arraylen(const char **array)
{
    size_t len = 0;

    while (array[++len]);
    return (len);
}
