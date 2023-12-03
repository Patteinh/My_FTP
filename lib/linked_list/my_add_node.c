/*
** EPITECH PROJECT, 2023
** my_add_node.c
** File description:
** add node of a linked list
*/

#include <stdlib.h>
#include "my.h"

void add_first_node(list_t **l, void *elem)
{
    (*l) = malloc(sizeof(list_t));
    (*l)->data = elem;
    (*l)->next = NULL;
}

void add_front_node(list_t **l, void *elem)
{
    list_t *tmp = NULL;

    if (!(*l)) {
        add_first_node(l, elem);
        return;
    }
    tmp = malloc(sizeof(list_t));
    tmp->data = elem;
    tmp->next = (*l);
    (*l) = tmp;
}

void add_back_node(list_t **l, void *elem)
{
    list_t *tmp = (*l);

    if (!(*l)) {
        add_first_node(l, elem);
        return;
    }
    for (; tmp->next; tmp = tmp->next);
    tmp->next = malloc(sizeof(list_t));
    tmp->next->data = elem;
    tmp->next->next = NULL;
}

void add_node_at_position(list_t **l, void *elem, size_t pos)
{
    list_t *tmp = (*l);
    list_t *tmp2 = NULL;

    if (!(*l) || (pos > get_list_size(*l)))
        return;
    if (pos == 0)
        return (add_front_node(l, elem));
    for (unsigned int i = 0; i < pos - 1; i++)
        tmp = tmp->next;
    tmp2 = malloc(sizeof(list_t));
    tmp2->data = elem;
    tmp2->next = NULL;
    tmp2->next = tmp->next;
    tmp->next = tmp2;
}

void add_node(list_t **l, void *elem)
{
    (!(*l)) ? add_first_node(l, elem) : add_back_node(l, elem);
}
