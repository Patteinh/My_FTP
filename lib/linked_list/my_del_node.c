/*
** EPITECH PROJECT, 2023
** my_del_node.c
** File description:
** del node of a linked list
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"

void del_front_node(list_t **l)
{
    list_t *tmp = (*l);

    if (!(*l))
        return;
    (*l) = (*l)->next;
    free(tmp);
}

void del_back_node(list_t **l)
{
    list_t *tmp = (*l);

    if (!(*l))
        return;
    if (!tmp->next) {
        free(tmp);
        (*l) = NULL;
        return;
    }
    for (; tmp->next->next; tmp = tmp->next);
    list_t *last = tmp->next;
    tmp->next = NULL;
    free(last);
}

void del_node_at_position(list_t **l, size_t pos)
{
    list_t *tmp = (*l);
    list_t *del_node;

    if (!(*l))
        return;
    if (pos == 0)
        return (del_front_node(l));
    for (unsigned int i = 0; i < pos; i++) {
        if (!tmp->next)
            return;
        del_node = tmp;
        tmp = tmp->next;
    }
    del_node->next = tmp->next;
    free(tmp);
}
