/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** log
*/

#include "server.h"

void user(char **arr, client_t *client)
{
    char *user = get_pure_command(arr[1]);

    if (user == NULL) {
        client->username = NULL;
        send_message_client(client->client_fd, 
        "You have to enter a valid username\r\n");
    }
    if (strcmp("anonymous",user) == 0) {
        client->islog = true;
        client->username = user;
        send_message_client(client->client_fd, 
        "230 User logged in, proceed.\r\n");
    }
    else {
        client->username = user;
        send_message_client(client->client_fd, 
        "331 User name okay, need password.\r\n");
    }
    return;
}

void pass(char **arr, client_t *client)
{
    if (arr[1] == NULL) {
        client->password = NULL;
        send_message_client(client->client_fd, 
        "332 Need account for login.\r\n");
    }
    else {
        send_message_client(client->client_fd, 
        "230 User logged in, proceed.\r\n");
    }
    return;
}