/*
** EPITECH PROJECT, 2023
** pwd.c
** File description:
** pwd cmd for ftp
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "myftp.h"

void pwd(client_t *c)
{
    char *buf = NULL;

    if (my_arraylen(((const char **)c->read->data)) != 1)
        return (void)dprintf(c->fd_cl, R500);
    buf = strdup(&c->work_dir[strlen(c->serv_work_dir) - 1]);
    strlen(buf) != 1 ? buf[strlen(buf) - 1] = '\0' : 0;
    dprintf(c->fd_cl, R257, buf);
    free(buf);
}
