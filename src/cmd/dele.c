/*
** EPITECH PROJECT, 2023
** dele.c
** File description:
** dele cmd for ftp
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "myftp.h"

void dele(client_t *c)
{
    char *path_to_delete = NULL;

    if (my_arraylen(((const char **)c->read->data)) != 2)
        return (void)dprintf(c->fd_cl, R500);
    path_to_delete = set_path(c->work_dir, ((char **)c->read->data)[1]);
    if (!path_to_delete) {
        free(path_to_delete);
        return (void)dprintf(c->fd_cl, R550);
    }
    if (unlink(path_to_delete)) {
        free(path_to_delete);
        return (void)dprintf(c->fd_cl, R550);
    }
    dprintf(c->fd_cl, R250);
    free(path_to_delete);
}
