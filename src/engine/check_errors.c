/*
** EPITECH PROJECT, 2023
** check_errors.c
** File description:
** check_errors ftp
*/

#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include "myftp.h"

int help_ftp(void)
{
    printf(USAGE);
    return SUCCESS;
}

int is_number(const char *port)
{
    for (size_t i = 0; port[i]; i++)
        if (!isdigit(port[i]))
            return ERROR;
    return SUCCESS;
}

int check_errors(int ac, char **av)
{
    if (ac == 3 && strcmp(av[1], "") && strcmp(av[2], "") && !is_number(av[1]))
        return SUCCESS;
    return ac == 2 && !strcmp(av[1], "-h") ? help_ftp() : ERROR;
}
