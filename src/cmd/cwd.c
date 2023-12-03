/*
** EPITECH PROJECT, 2023
** vwd.c
** File description:
** cwd cmd for ftp
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "myftp.h"

void cwd(client_t *c)
{
    char *path = NULL;

    if (my_arraylen(((const char **)c->read->data)) != 2)
        return (void)dprintf(c->fd_cl, R500);
    path = ((char **)c->read->data)[1][0] == ROOT ?
    construct_path(c->serv_work_dir, ((char **)c->read->data)[1] + 1) :
    construct_path(c->work_dir, ((char **)c->read->data)[1]);
    if (!path || !IS_DIR(path))
        return (void)dprintf(c->fd_cl, R500);
    if (!strncmp(c->serv_work_dir, path, strlen(c->serv_work_dir))) {
        free(c->work_dir);
        c->work_dir = path;
    } else {
        free(path);
        return (void)dprintf(c->fd_cl, R500);
    }
    dprintf(c->fd_cl, R250);
}
