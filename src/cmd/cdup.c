/*
** EPITECH PROJECT, 2023
** cdup.c
** File description:
** cdup cmd for ftp
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "myftp.h"

void cdup(client_t *c)
{
    char *buf = NULL;

    if (my_arraylen(((const char **)c->read->data)) != 1)
        return (void)dprintf(c->fd_cl, R500);
    if (strcmp(c->serv_work_dir, c->work_dir) == 0)
        return (void)dprintf(c->fd_cl, R200);
    buf = construct_path(c->work_dir, PARENT_FOLDER);
    if (!buf)
        return (void)dprintf(c->fd_cl, R550);
    free(c->work_dir);
    c->work_dir = buf;
    dprintf(c->fd_cl, R200);
}
