/*
** EPITECH PROJECT, 2023
** my_size_list.c
** File description:
** get size of linked list
*/

#include "my.h"

size_t get_list_size(list_t *l)
{
    size_t len = 0;

    for (; l; l = l->next, len++);
    return (len);
}
