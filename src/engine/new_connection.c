/*
** EPITECH PROJECT, 2023
** new_connection.c
** File description:
** handle new_connection of clients
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "myftp.h"

static void set_new_client(ftp_t *ftp)
{
    socklen_t size = sizeof(struct sockaddr);

    ftp->client = realloc(ftp->client,
    sizeof(client_t)*(ftp->server->nb_cl + 1));
    ftp->client[ftp->server->nb_cl].fd_cl =
    accept(ftp->server->fd_srv, (struct sockaddr *)
    &ftp->client[ftp->server->nb_cl].addr, &size);
    ftp->client[ftp->server->nb_cl].fd_cl_other = -1;
    cerror(ftp->client[ftp->server->nb_cl].fd_cl == FAIL, "accept", ftp);
    ftp->client[ftp->server->nb_cl].mode = NONE;
    ftp->client[ftp->server->nb_cl].username = NULL;
    ftp->client[ftp->server->nb_cl].password = NULL;
    ftp->client[ftp->server->nb_cl].read = NULL;
    ftp->client[ftp->server->nb_cl].work_dir = strdup(ftp->server->work_dir);
    ftp->client[ftp->server->nb_cl].serv_work_dir = ftp->server->work_dir;
    ftp->client[ftp->server->nb_cl].is_looged = NOT_LOGGED;
    dprintf(ftp->client[ftp->server->nb_cl].fd_cl, R220);
}

void check_new_connection(ftp_t *ftp)
{
    if (FD_ISSET(ftp->server->fd_srv, &ftp->engine->rfds)) {
        set_new_client(ftp);
        FD_CLR(ftp->server->fd_srv, &ftp->engine->rfds);
        ftp->engine->fdtotal--;
        ftp->server->nb_cl++;
    }
}
