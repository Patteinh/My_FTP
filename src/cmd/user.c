/*
** EPITECH PROJECT, 2023
** user.c
** File description:
** user cmd for ftp
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "myftp.h"

void user(client_t *c)
{
    if (my_arraylen(((const char **)c->read->data)) == 1)
        return (void)dprintf(c->fd_cl, R500);
    if (c->is_looged)
        return (void)dprintf(c->fd_cl, R500);
    if (c->username) {
        free(c->username);
        c->username = strdup(((char **)c->read->data)[1]);
    } else
        c->username = strdup(((char **)c->read->data)[1]);
    dprintf(c->fd_cl, R331);
}
