/*
** EPITECH PROJECT, 2023
** noop.c
** File description:
** noop cmd for ftp
*/

#include <stdio.h>
#include "myftp.h"

void noop(client_t *c)
{
    if (my_arraylen(((const char **)c->read->data)) != 1)
        return (void)dprintf(c->fd_cl, R500);
    dprintf(c->fd_cl, R200);
}
