/*
** EPITECH PROJECT, 2023
** cmd.h
** File description:
** cmd for ftp
*/

#pragma once

#include "myftp.h"

void user(client_t *c);
void pass(client_t *c);
void quit(client_t *c);
void cwd(client_t *c);
void cdup(client_t *c);
void pwd(client_t *c);
void pasv(client_t *c);
void port(client_t *c);
void retr(client_t *c);
void stor(client_t *c);
void list(client_t *c);
void dele(client_t *c);
void help(client_t *c);
void noop(client_t *c);

typedef struct command_s {
    const cmd_is_log_t is_log;
    const char *cmd;
    void (*const cmd_function)(client_t *);
} command_t;

static const command_t ALLCMD[] = {
    {NOT_LOGGED, "USER", help},
    {NOT_LOGGED, "PASS", pass},
    {NOT_LOGGED, "QUIT", quit},
    {NOT_LOGGED, "HELP", help},
    {LOGGED, "CWD", cwd},
    {LOGGED, "CDUP", cdup},
    {LOGGED, "PWD", pwd},
    {LOGGED, "PASV", pasv},
    {LOGGED, "PORT", port},
    {LOGGED, "RETR", retr},
    {LOGGED, "STOR", stor},
    {LOGGED, "LIST", list},
    {LOGGED, "DELE", dele},
    {LOGGED, "NOOP", noop},
    {LOGGED, NULL, NULL}
};
