/*
** EPITECH PROJECT, 2023
** quit.c
** File description:
** quit cmd for ftp
*/

#include <stdio.h>
#include "myftp.h"

void quit(client_t *c)
{
    c->is_looged = DISCONNECTED;
    dprintf(c->fd_cl, R221);
}
