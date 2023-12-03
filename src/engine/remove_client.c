/*
** EPITECH PROJECT, 2023
** remove_client.c
** File description:
** remove_client of ftp
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "myftp.h"

int remove_client(ftp_t *ftp, size_t i)
{
    close(ftp->client[i].fd_cl);
    ftp->client[i].username ? free(ftp->client[i].username) : 0;
    ftp->client[i].password ? free(ftp->client[i].password) : 0;
    ftp->client[i].work_dir ? free(ftp->client[i].work_dir) : 0;
    ftp->server->nb_cl--;
    if (i < ftp->server->nb_cl) {
        memmove(&ftp->client[i], &ftp->client[i + 1],
            (ftp->server->nb_cl - i) * sizeof(client_t));
    }
    ftp->client = realloc(ftp->client, sizeof(client_t) * ftp->server->nb_cl);
    return (0);
}
