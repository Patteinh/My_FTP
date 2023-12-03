/*
** EPITECH PROJECT, 2023
** pasv.c
** File description:
** pasv cmd for ftp
*/

#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include "myftp.h"

static char *convert_ip(char *given_ip)
{
    for (char *c = given_ip; *c; c++)
        if (*c == '.')
            *c = ',';
    return given_ip;
}

void pasv(client_t *c)
{
    char *ip = NULL;
    struct sockaddr_in sin = { 0 };
    struct sockaddr_in sin2 = { 0 };
    socklen_t size = sizeof(sin2);

    if (my_arraylen(((const char **)c->read->data)) != 1)
        return (void)dprintf(c->fd_cl, R500);
    c->fd_cl_other = socket(AF_INET, SOCK_STREAM, 0);
    sin.sin_family = AF_INET;
    sin.sin_port = 0;
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(c->fd_cl_other, (struct sockaddr *)(&sin), sizeof(sin));
    listen(c->fd_cl_other, 1);
    getsockname(c->fd_cl_other, (struct sockaddr *)(&sin2), &size);
    ip = convert_ip(inet_ntoa(c->addr.sin_addr));
    dprintf(c->fd_cl, R227, ip, ntohs(sin2.sin_port) / 256,
    ntohs(sin2.sin_port) % 256);
    c->mode = PASSIVE;
}
