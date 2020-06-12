/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** path
*/

#include "server.h"

void pwd(client_t *client)
{
    send_message_client(client->client_fd,"257 ");
    send_message_client(client->client_fd, client->path);
    send_message_client(client->client_fd, "\r\n");
    return;
}

void cdup(char **cmd, client_t *client)
{
    int cut = 0;
    int i = 0;
    char *path;

    if (strcmp(client->path, "/") == 0) {
        send_message_client(client->client_fd, "200\r\n");
    }
    while (client->path[cut] != '/' && client->path[cut] != '\0')
        cut += 1;
    path = malloc(sizeof(char) * cut + 1);
    if (path == NULL)
        return;
    while (i != cut) {
        path = client->path[i];
        i += 1;
    }
    path[i] = '\0';
    client->path = path;
    return;
}