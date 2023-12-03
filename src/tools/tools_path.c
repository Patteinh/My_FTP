/*
** EPITECH PROJECT, 2023
** tools_path.c
** File description:
** tools_path for ftp
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "myftp.h"

char *set_path(const char *work_dir, const char *path_to_delete)
{
    char *real_path = NULL;
    char *final_path = NULL;
    size_t work_dir_len = strlen(work_dir);
    size_t path_to_delete_len = strlen(path_to_delete);

    final_path = (char*)malloc(work_dir_len + path_to_delete_len + 2);
    if (!final_path) {
        return NULL;
    }
    memcpy(final_path, work_dir, work_dir_len);
    final_path[work_dir_len] = '/';
    memcpy(final_path + work_dir_len + 1, path_to_delete, path_to_delete_len);
    final_path[work_dir_len + path_to_delete_len + 1] = '\0';
    real_path = realpath(final_path, NULL);
    if (!real_path) {
        free(final_path);
        return NULL;
    }
    free(final_path);
    return real_path;
}

static char *concatenate_path(const char *work_dir, const char *path)
{
    size_t work_dir_len = strlen(work_dir);
    size_t path_len = strlen(path);
    char *concat_path = (char*)malloc(work_dir_len + path_len + 2);

    if (!concat_path)
        return NULL;
    memcpy(concat_path, work_dir, work_dir_len);
    concat_path[work_dir_len] = '/';
    memcpy(concat_path + work_dir_len + 1, path, path_len);
    concat_path[work_dir_len + path_len + 1] = '\0';
    return concat_path;
}

static char *append_slash_to_path(const char *path)
{
    size_t path_len = strlen(path);
    char *final_path = (char*)malloc(path_len + 2);

    if (!final_path)
        return NULL;
    path[path_len - 1] != ROOT ?
    snprintf(final_path, path_len + 2, "%s/", path) :
    snprintf(final_path, path_len + 1, "%s", path);
    return final_path;
}

char *construct_path(const char *work_dir, const char *path)
{
    char *real_path = NULL;
    char *final_path = NULL;
    char *concat_path = concatenate_path(work_dir, path);

    if (!concat_path)
        return NULL;
    real_path = realpath(concat_path, NULL);
    free(concat_path);
    if (!real_path)
        return NULL;
    final_path = append_slash_to_path(real_path);
    free(real_path);
    return final_path;
}
