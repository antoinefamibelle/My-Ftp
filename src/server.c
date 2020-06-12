/*
** EPITECH PROJECT, 2020
** NWP
** File description:
** server
*/

#include "server.h"

client_t *init_client(void)
{
    client_t *client = malloc(sizeof(client_t));

    if (client == NULL)
        return NULL;
    client->client_fd = 0;
    client->client_len = sizeof(client->data);
    client->path = "/";
    client->password = NULL;
    client->username = NULL;
    client->islog = false;
    return client;
}

server_t *init_server(int port)
{
    server_t *server = malloc(sizeof(server_t));

    if (server == NULL) {
        printf("Malloc has failed\n");
        return NULL;
    }
    server->client = init_client();
    if (server->client == NULL) {
        printf("Client malloc failed");
        return NULL;
    }
    server->address_len = sizeof(server->server_addr);
    server->port = port;
    server->path = "/";
    server->socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server->socket_fd == -1) {
        printf("Socket has failed\n");
        return NULL;
    }
    server->server_addr.sin_family = AF_INET;
    server->server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server->server_addr.sin_port = htons(server->port);
    if (bind(server->socket_fd, 
    (struct sockaddr*)&server->server_addr,sizeof(server->server_addr)) == -1) {
        printf("Binding has just failed");
        return NULL;
    }
    if (listen(server->socket_fd, 10) == -1) {
        printf("Listen has just failed");
        return NULL;
    }
    return server;
}