/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** server
*/

#ifndef SERVER_H_
#define SERVER_H_

#include <sys/types.h> /* Voir NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/select.h>
#include <sys/time.h>
#include <dirent.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

static char code_220[3] = "220";

typedef struct client_s {
    int client_fd;
    int client_len;
    struct sockaddr_in data;
    bool islog;
    char *path;
    char *username;
    char *password;
} client_t;

typedef struct server_s {
    int socket_fd;
    int new_socket;
    char *path;
    int port;
    int error;
    int address_len;
    client_t *client;
    struct sockaddr_in server_addr;
} server_t;

//server.c//
server_t *init_server(int);
void send_message_client(int , char *);
int manage_server(server_t *);
//server.c//

//client.c//
int manage_client(server_t *);
//client.c//

//strtoa.c//
char **my_strtoa(char *str);
//strtoa.c//

//getnextline.c//
char *get_next_line(const int);
//getnextline.c//

//strcat.c//
char *my_strcat(char *, char const *);
//strcat.c//

//strcmp.c//
int my_strcmp(char *, char *);
//strcmp.c//

//command.c//
void manage_command(char **, server_t *);
char *get_pure_command(char *str);
//command.c//

//log.c//
void user(char **, client_t *);
void pass(char **, client_t *);
//log.c//

//path.c//
void cdup(char **, client_t *);
//void cwd(char **, client_t *);
void pwd(client_t *);
//path.c

#endif