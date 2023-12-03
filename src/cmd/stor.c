/*
** EPITECH PROJECT, 2023
** stor.c
** File description:
** stor cmd for ftp
*/

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/sendfile.h>
#include "myftp.h"

static void execute_upload(client_t *c, int file_fd)
{
    struct stat stat_buf;
    int status;
    pid_t pid = fork();

    if (pid == -1) {
        close(file_fd);
        return (void)dprintf(c->fd_cl, R550);
    } else if (pid == 0) {
        dup2(c->fd_cl_other, STDIN_FILENO);
        fstat(file_fd, &stat_buf);
        sendfile(file_fd, c->fd_cl_other, NULL, stat_buf.st_size);
        close(file_fd);
        exit(SUCCESS);
    } else {
        waitpid(pid, &status, 0);
        close(file_fd);
        if (WIFEXITED(status) && WEXITSTATUS(status))
            return (void)dprintf(c->fd_cl, R550);
        dprintf(c->fd_cl, R226);
    }
}

void stor(client_t *c)
{
    char full_path[MAX_LEN];
    int file_fd;

    if (my_arraylen(((const char **)c->read->data)) != 2)
        return (void)dprintf(c->fd_cl, R500);
    if (c->mode == NONE || c->fd_cl_other < 0)
        return (void)dprintf(c->fd_cl, R425);
    c->mode = NONE;
    snprintf(full_path, MAX_LEN, "%s/%s", c->work_dir,
    ((const char **)c->read->data)[1]);
    file_fd = open(full_path, O_WRONLY | O_CREAT | O_TRUNC);
    if (file_fd == -1)
        return (void)dprintf(c->fd_cl, R550);
    dprintf(c->fd_cl, R150);
    execute_upload(c, file_fd);
}
