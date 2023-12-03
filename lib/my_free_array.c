/*
** EPITECH PROJECT, 2023
** my_free_array
** File description:
** free array
*/

#include <stdlib.h>

void my_free_array(char **array)
{
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}
