/*
** EPITECH PROJECT, 2023
** tools_ftp.c
** File description:
** tools for ftp
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "cmd.h"

void cerror(const int iserror, const char *e, ftp_t *ftp)
{
    iserror ? perror(e), free_ftp(*ftp), exit(ERROR) : 0;
}

int client_left(ftp_t *ftp, int bytes_read, size_t i)
{
    if (bytes_read == 0) {
        ftp->client[i].is_looged = DISCONNECTED;
        return 0;
    }
    return 1;
}

int what_cmd(ftp_t *ftp, size_t idx)
{
    for (size_t i = 0; ALLCMD[i].cmd; i++)
        if (!strcmp(((char **)ftp->client[idx].read->data)[0], ALLCMD[i].cmd))
            return (i);
}
