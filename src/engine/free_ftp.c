/*
** EPITECH PROJECT, 2023
** free_ftp.c
** File description:
** free ftp
*/

#include <stdlib.h>
#include "myftp.h"

void free_ftp(const ftp_t ftp)
{

    ftp.server ? free(ftp.server->work_dir), free(ftp.server) : 0;
    ftp.client ? free(ftp.client) : 0;
    ftp.engine ? free(ftp.engine) : 0;
}
