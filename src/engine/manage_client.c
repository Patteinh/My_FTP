/*
** EPITECH PROJECT, 2023
** manage_clients.c
** File description:
** manage_clients of ftp
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "myftp.h"
#include "cmd.h"

static void check_cmd(ftp_t *ftp, size_t idx)
{
    int cmd_idx = what_cmd(ftp, idx);

    if (cmd_idx == CMD_NOT_FOUND)
        return (void)dprintf(ftp->client[idx].fd_cl, R500);
    if (ALLCMD[cmd_idx].is_log == LOGGED &&
    ftp->client[idx].is_looged == NOT_LOGGED)
        return (void)dprintf(ftp->client[idx].fd_cl, R530);
    ALLCMD[cmd_idx].cmd_function(&ftp->client[idx]);
}

static void get_cmd(ftp_t *ftp, size_t i, char *buf)
{
    if (ftp->client[i].fd_cl == FAIL || ftp->client[i].read || !buf)
        return;
    add_node(&ftp->client[i].read, my_str_to_array(buf, DELIMITERS));
    free(buf);
}

static void read_cmd(ftp_t *ftp, size_t i, char *buf)
{
    char *cleaned_buf = my_clean_str(buf, USLESS_DELIMITERS);
    if (!cleaned_buf)
        return;
    get_cmd(ftp, i, cleaned_buf);
    check_cmd(ftp, i);
    my_free_array((char **)ftp->client[i].read->data);
    del_back_node(&ftp->client[i].read);
}

static void read_clients(ftp_t *ftp, size_t i)
{
    char buf[MAX_LEN];
    ssize_t bytes_read;

    bytes_read = read(ftp->client[i].fd_cl, buf, MAX_LEN - 1);
    cerror(bytes_read == FAIL, "read", ftp);
    buf[bytes_read] = '\0';
    client_left(ftp, bytes_read, i) ? read_cmd(ftp, i, buf) : 0;
}

void manage_clients(ftp_t *ftp)
{
    for (size_t i = 0; i < ftp->server->nb_cl; i++) {
        FD_ISSET(ftp->client[i].fd_cl, &ftp->engine->rfds) ?
        read_clients(ftp, i) : 0;
        if (ftp->client[i].is_looged == DISCONNECTED)
            remove_client(ftp, i);
    }
}
