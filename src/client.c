/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** client
*/

#include "server.h"

void send_message_client(int fd, char *str)
{
    write(fd, str, strlen(str));
}

void send_message_server(char *message)
{
    printf("%s\r\n", message);
}

int client_management(server_t *server)
{
    char **arr;
    char *buffer = malloc(sizeof(char) * 1024 + 1);

    send_message_client(server->client->client_fd, "220\r\n");
    if (buffer == NULL)
        return 84;
    read(server->client->client_fd, buffer, 1024);
    arr = my_strtoa(buffer);
    while (1 && strcmp("QUIT\r\n", arr[0]) != 0) {
        manage_command(arr, server);
        read(server->client->client_fd, buffer, 1024);
        arr = my_strtoa(buffer);
    }
    send_message_client(server->client->client_fd, "221\r\n");
    return 0;
}

int manage_client(server_t *server)
{
    while (1) {
        server->client->client_fd = accept(server->socket_fd,
        (struct sockaddr *) &server->client->data, 
        (socklen_t *)&server->client->client_len);
        if (server->client->client_fd < 0) {
            printf("Accept has just failed");
            return 84;
        }
        if (fork() == 0) {
            printf("Connection from %s:%d\n", 
            inet_ntoa(server->client->data.sin_addr), 
            ntohs(server->client->data.sin_port));
            printf("We have a new connection in pid %d\n",
            server->client->client_fd);
            client_management(server);
        }
        else
            close(server->client->client_fd);
    }
}

