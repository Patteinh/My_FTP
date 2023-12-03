/*
** EPITECH PROJECT, 2023
** my_free_list.c
** File description:
** free linked list
*/

#include <stdlib.h>
#include "my.h"

void my_free_list(list_t *l)
{
    list_t *tmp;

    for (; l; l = tmp) {
        tmp = l->next;
        free(l);
    }
}
