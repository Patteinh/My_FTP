/*
** EPITECH PROJECT, 2023
** set_ftp.c
** File description:
** set for ftp
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "myftp.h"

static void set_sock(struct sockaddr_in *addr, int port)
{
    memset(addr, 0, sizeof(struct sockaddr_in));
    addr->sin_family = AF_INET;
    addr->sin_port = htons(port);
    addr->sin_addr.s_addr = INADDR_ANY;
}

static void set_server(const int port, char *p, ftp_t *ftp)
{
    ftp->server = malloc(sizeof(server_t));
    ftp->server->port = (size_t)port;
    ftp->server->nb_cl = 0;
    ftp->server->fd_srv = socket(AF_INET, SOCK_STREAM, AUTO);
    ftp->server->work_dir = NULL;
    char *tmp = NULL;

    cerror(ftp->server->fd_srv == FAIL, "socket", ftp);
    set_sock(&ftp->server->addr, ftp->server->port);
    cerror(bind(ftp->server->fd_srv, (struct sockaddr *)&ftp->server->addr,
    sizeof(struct sockaddr_in)), "bind", ftp);
    cerror(listen(ftp->server->fd_srv, MAX_CLIENTS), "listen", ftp);
    cerror(strcmp(p, ".") && access(p, PERMISSIONS), "access", ftp);
    ftp->server->work_dir = realpath(p, NULL);
    tmp = ftp->server->work_dir;
    ftp->server->work_dir = my_strcat(ftp->server->work_dir, "/");
    cerror(!ftp->server->work_dir, "realpath", ftp);
    free(tmp);
}

static void set_engine(ftp_t *ftp)
{
    cerror(!(ftp->engine = malloc(sizeof(engine_t))), "malloc", ftp);
    ftp->engine->fdmax = 0;
    ftp->engine->fdtotal = 0;
}

int set_ftp(const int port, char *p, ftp_t *ftp)
{
    set_server(port, p, ftp);
    set_engine(ftp);
    return SUCCESS;
}
