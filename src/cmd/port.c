/*
** EPITECH PROJECT, 2023
** port.c
** File description:
** port cmd for ftp
*/

#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include "myftp.h"

static int parse_data(const char *data, char *ip, int *port)
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    int f = 0;

    if (sscanf(data, "%d,%d,%d,%d,%d,%d", &a, &b, &c, &d, &e, &f) != 6)
        return 1;
    sprintf(ip, "%d.%d.%d.%d", a, b, c, d);
    *port = e * 256 + f;
    return 0;
}

void port(client_t *c)
{
    int port = 0;
    char ip[16];

    if (my_arraylen(((const char **)c->read->data)) != 2)
        return (void)dprintf(c->fd_cl, R500);
    if (parse_data(((const char **)c->read->data)[1], ip, &port))
        return (void)dprintf(c->fd_cl, R500);
    memset(&c->fd_cl_other, 0, sizeof(c->fd_cl_other));
    c->addr.sin_family = AF_INET;
    c->addr.sin_addr.s_addr = inet_addr(ip);
    c->addr.sin_port = htons(port);
    c->fd_cl_other = socket(AF_INET, SOCK_STREAM, 0);
    c->mode = ACTIVE;
    dprintf(c->fd_cl, R200);
}
