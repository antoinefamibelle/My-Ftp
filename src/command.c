/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** command
*/

#include "server.h"

char *get_pure_command(char *str)
{
    int i = 0;
    char *string;

    if (str == NULL)
        return NULL;
    for (i = 0; str[i] != '\r' && str[i] != '\n' && str[i]; i++);
    string = malloc(sizeof(char) * i + 1);
    if (string == NULL) {
        printf("Malloc has just failed");
        return NULL;
    }
    i = 0;
    while (str[i] != '\r' && str[i] != '\n' && str[i]) {
        string[i] = str[i];
        i += 1;
    }
    string[i] = '\0';
    return string;
}

void cwd(char **cmd, server_t *server)
{
    if (chdir(cmd[1]) == 0) {
        my_strcat(server->path, cmd[1]);
        send_message_client(server->client->client_fd, "250\r\n");
    }
    else {
        send_message_client(server->client->client_fd, "250\r\n");
    }
}

void manage_command(char **cmd, server_t *server)
{
    char *str = get_pure_command(cmd[0]);

    if (strcasecmp("user", str) == 0) {
        user(cmd, server->client);
    }
    else if (strcasecmp("pass", str) == 0) {
        pass(cmd, server->client);
    }
    else if (strcasecmp("CWD", str) == 0) {
        cwd(cmd, server);
    }
    else if (strcasecmp("CDUP", str) == 0) {
        cdup(cmd, server->client);
    }
    else if (strcasecmp("DELE", str) == 0) {
        send_message_client(server->client->client_fd, "250\r\n");
    }
    else if (strcasecmp("PWD", str) == 0) {
        pwd(server->client);
    }
    else if (strcasecmp("PASV", str) == 0) {
        send_message_client(server->client->client_fd, "227\r\n");
    }
    else if (strcasecmp("PORT", str) == 0) {
        send_message_client(server->client->client_fd, "200\r\n");
    }
    else if (strcasecmp("HELP", str) == 0) {
        send_message_client(server->client->client_fd,"214\r\n");
    }
    else if (strcasecmp("NOOP", str) == 0)
        send_message_client(server->client->client_fd,"200\r\n");
    else if (strcasecmp("QUIT", str) == 0)
        send_message_client(server->client->client_fd,"221\r\n");
    else 
        send_message_client(server->client->client_fd,"500\r\n");
    return;
}