/*
** EPITECH PROJECT, 2023
** help.c
** File description:
** help cmd for ftp
*/

#include <stdio.h>
#include "myftp.h"

void help(client_t *c)
{
    if (my_arraylen(((const char **)c->read->data)) != 1)
        return (void)dprintf(c->fd_cl, R500);
    dprintf(c->fd_cl, R214);
}
