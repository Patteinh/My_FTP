/*
** EPITECH PROJECT, 2023
** list.c
** File description:
** list cmd for ftp
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "myftp.h"

void list(client_t *c)
{
    pid_t pid;

    if (my_arraylen(((const char **)c->read->data)) != 1)
        return (void)dprintf(c->fd_cl, R500);
    if (c->mode == NONE || c->fd_cl_other < 0)
        return (void)dprintf(c->fd_cl, R425);
    c->mode = NONE;
    dprintf(c->fd_cl, R150);
    pid = fork();
    if (pid == SUCCESS) {
        dup2(c->fd_cl_other, STDOUT_FILENO);
        execl("/bin/ls", "ls", "-l", c->work_dir, NULL);
        exit(SUCCESS);
    }
    waitpid(pid, NULL, 0);
    close(c->fd_cl_other);
    dprintf(c->fd_cl, R226);
}
