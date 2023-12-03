/*
** EPITECH PROJECT, 2023
** lib.h
** File description:
** lib.h
*/

#pragma once

#include <stddef.h>

typedef struct list_s {
    void *data;
    struct list_s *next;
} list_t;

int  my_arraylen(const char **array);
char *my_clean_str(const char *str, const char *delim);
char *my_strcat(const char *left, const char *right);
char **my_str_to_array(const char *str, const char *d);
void my_free_array(char **array);
void add_node(list_t **l, void *elem);
void add_first_node(list_t **l, void *elem);
void add_back_node(list_t **l, void *elem);
void add_node_at_position(list_t **l, void *elem, size_t pos);
void *get_front_node(list_t *l);
void *get_back_node(list_t *l);
void *get_node_at_position(list_t *l, size_t pos);
void del_front_node(list_t **l);
void del_back_node(list_t **l);
void del_node_at_position(list_t **l, size_t pos);
size_t get_list_size(list_t *l);
void my_free_list(list_t *l);

static const int SUCCESS = 0;
static const int FAILURE = 1;
static const int ERROR = 84;
