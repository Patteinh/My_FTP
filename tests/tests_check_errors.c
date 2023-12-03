/*
** EPITECH PROJECT, 2023
** tests_myftp.c
** File description:
** tests_myftp
*/

#include <criterion/criterion.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "myftp.h"

int help_ftp(void);

Test(help_ftp, test_help)
{
    freopen("test_help_output.txt", "w", stdout);
    help_ftp();
    fclose(stdout);
    FILE* file = fopen("test_help_output.txt", "r");
    char output[1024];
    fgets(output, 1024, file);
    cr_assert_str_eq(output, "USAGE: ./myftp port path\n");
    fclose(file);
}

Test(check_args, test_check_args)
{
    char* av1[] = {"./myftp", "8080", "."};
    cr_assert_eq(check_errors(3, av1), SUCCESS);
    char* av2[] = {"./myftp", "-h"};
    freopen("test_check_args_output.txt", "w", stdout);
    cr_assert_eq(check_errors(2, av2), SUCCESS);
    fclose(stdout);
    FILE* file = fopen("test_check_args_output.txt", "r");
    char output[1024];
    fgets(output, 1024, file);
    cr_assert_str_eq(output, "USAGE: ./myftp port path\n");
    fclose(file);
    char* av3[] = {"./myftp"};
    cr_assert_eq(check_errors(1, av3), ERROR);
    char* av4[] = {"./myftp", "8080"};
    cr_assert_eq(check_errors(2, av4), ERROR);
    char* av5[] = {"./myftp", "8080", ""};
    cr_assert_eq(check_errors(3, av5), ERROR);
    char* av6[] = {"./myftp", "", ""};
    cr_assert_eq(check_errors(3, av6), ERROR);
    char* av8[] = {"./myftp", "8080", "."};
    cr_assert_eq(check_errors(3, av8), SUCCESS);
    char* av9[] = {"./myftp", "808A", "."};
    cr_assert_eq(check_errors(3, av9), ERROR);
}
