/*
** EPITECH PROJECT, 2023
** myftp
** File description:
** ftp engine loop
*/

#include <stdlib.h>
#include "myftp.h"

static void reset_fd(ftp_t *ftp)
{
    ftp->engine->fdmax = ftp->server->fd_srv;

    FD_ZERO(&ftp->engine->rfds);
    FD_ZERO(&ftp->engine->wfds);
    FD_SET(ftp->server->fd_srv, &ftp->engine->rfds);
    for (size_t i = 0; i < ftp->server->nb_cl; i++) {
        FD_SET(ftp->client[i].fd_cl, &ftp->engine->rfds);
        ftp->client[i].fd_cl > ftp->engine->fdmax ?
        ftp->engine->fdmax = ftp->client[i].fd_cl : 0;
    }
    ftp->engine->fdmax++;
}

static int engine_ftp(ftp_t *ftp)
{
    reset_fd(ftp);
    ftp->engine->fdtotal = select(ftp->engine->fdmax,
    &ftp->engine->rfds, &ftp->engine->wfds, NULL, NULL);
    cerror(ftp->engine->fdtotal == FAIL, "select", ftp);
    check_new_connection(ftp);
    manage_clients(ftp);
    return LOOP;
}

int myftp(int ac, char **av)
{
    ftp_t ftp = { 0 };

    if (check_errors(ac, av) || set_ftp(atoi(av[1]), av[2], &ftp))
        return ERROR;
    while (engine_ftp(&ftp));
    free_ftp(ftp);
    return SUCCESS;
}
