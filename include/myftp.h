/*
** EPITECH PROJECT, 2023
** myftp.h
** File description:
** myftp.h
*/

#pragma once

#include <sys/stat.h>
#include <sys/select.h>
#include <netinet/in.h>
#include "my.h"

#define IS_DIR(path) ({ \
    struct stat st; \
    !stat(path, &st) && S_ISDIR(st.st_mode); \
})
#define PERMISSIONS F_OK | R_OK | W_OK | X_OK
#define R150 "150 File status okay; about to open data connection.\r\n"
#define R200 "200 Command okay.\r\n"
#define R214 "214 Help message.\r\n"
#define R220 "220 Service ready for new user.\r\n"
#define R221 "221 Service closing control connection.\r\n"
#define R226 "226 Closing data connection.\r\n"
#define R227 "227 Entering Passive Mode (%s,%d,%d).\r\n"
#define R230 "230 User logged in, proceed.\r\n"
#define R250 "250 Requested file action okay, completed.\r\n"
#define R257 "257 \"%s\" created.\r\n"
#define R331 "331 User name okay, need password.\r\n"
#define R332 "332 Need account for login.\r\n"
#define R425 "425 Can't open data connection.\r\n"
#define R426 "426 Connection closed; transfer aborted.\r\n"
#define R500 "500 Unknown command.\r\n"
#define R530 "530 Not logged in.\r\n"
#define R550 "550 Requested action not taken. File unavailable.\r\n"

typedef enum cmd_is_log_e {
    NOT_LOGGED,
    LOGGED
} cmd_is_log_t;

typedef enum type_mode_e {
    NONE,
    PASSIVE,
    ACTIVE
} type_mode_t;

typedef struct server_s {
    struct sockaddr_in addr;
    char *work_dir;
    int fd_srv;
    size_t port;
    size_t nb_cl;
} server_t;

typedef struct client_s {
    struct sockaddr_in addr;
    type_mode_t mode;
    int fd_cl;
    int fd_cl_other;
    int is_looged;
    char *username;
    char *password;
    char *work_dir;
    char *serv_work_dir;
    list_t *read;
} client_t;

typedef struct engine_s {
    int fdmax;
    int fdtotal;
    fd_set rfds;
    fd_set wfds;
} engine_t;

typedef struct ftp_s {
    struct server_s *server;
    struct client_s *client;
    struct engine_s *engine;
} ftp_t;

int  check_errors(int ac, char **av);
int  set_ftp(const int port, char *p, ftp_t *ftp);
void check_new_connection(ftp_t *ftp);
void manage_clients(ftp_t *ftp);
void cerror(const int iserror, const char *e, ftp_t *ftp);
int  client_left(ftp_t *ftp, int bytes_read, size_t i);
int  what_cmd(ftp_t *ftp, size_t idx);
char *construct_path(const char *work_dir, const char *path);
char *set_path(const char *work_dir, const char *path_to_delete);
int  remove_client(ftp_t *ftp, size_t i);
void free_ftp(const ftp_t ftp);

static const char USAGE[] = "USAGE: ./myftp port path\n"
    "\tport is the port number on which the server socket listens\n"
    "\tpath is the path to the home directory for the Anonymous user\n";
static const char USLESS_DELIMITERS[] = "\r\n\t";
static const char USERNAME[] = "Anonymous";
static const char DELIMITERS[] = " ";
static const char PARENT_FOLDER[] = "../";
static const int CMD_NOT_FOUND = 404;
static const char PASSWORD[] = "";
static const int DISCONNECTED = 2;
static const int MAX_PORT = 65535;
static const int MIN_PORT = 1024;
static const int MAX_CLIENTS = 5;
static const int MAX_LEN = 4096;
static const int SIZE = 1024;
static const char ROOT = '/';
static const int FAIL = -1;
static const int AUTO = 0;
static const int LOOP = 1;
