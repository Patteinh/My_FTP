/*
** EPITECH PROJECT, 2023
** my_get_node.c
** File description:
** get node of a linked list
*/

#include <stddef.h>
#include "my.h"

void *get_front_node(list_t *l)
{
    if (!l)
        return (0);
    return (l->data);
}

void *get_back_node(list_t *l)
{
    if (!l)
        return (0);
    for (; l->next; l = l->next);
    return (l->data);
}

void *get_node_at_position(list_t *l, size_t pos)
{
    if ((!l) || (pos >= get_list_size(l)))
        return (0);
    if (pos == 0)
        return (get_front_node(l));
    for (unsigned int i = 0; i < pos; l = l->next, i++);
    return (l->data);
}
