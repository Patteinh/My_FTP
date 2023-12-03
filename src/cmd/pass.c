/*
** EPITECH PROJECT, 2023
** pass.c
** File description:
** password cmd for ftp
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "myftp.h"

void pass(client_t *c)
{
    if (c->is_looged)
        return (void)dprintf(c->fd_cl, R500);
    if (!c->username)
        return (void)dprintf(c->fd_cl, R500);
    if (my_arraylen(((const char **)c->read->data)) == 1) {
        c->password = strdup("");
        if (!strcmp(c->username, USERNAME) && !strcmp(c->password, PASSWORD)) {
            c->is_looged = LOGGED;
            return (void)dprintf(c->fd_cl, R230);
        }
    }
    c->username ? free(c->username), c->username = NULL : 0;
    c->password ? free(c->password), c->password = NULL : 0;
    dprintf(c->fd_cl, R530);
}
