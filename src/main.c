/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** bootstrap
*/

#include "server.h"

int test_path(char *path)
{
    DIR *dir = opendir(path);

    if (dir)
        return 0;
    return 84;
}

int main(int ac, char **av)
{
    server_t *server;

    if (ac != 3) {
        printf("./myftp port path \n Every argument is required\n");
        return 84;
    }
    if (strcmp(av[1], "-help") == 0) {
        printf("This is the help");
        return (0);
    }
    if (test_path(av[1]) == 84)
        return 84;
    server = init_server(atoi(av[1]));
    if (server == NULL)
        return 84;
    if (manage_client(server) == 84) {
   
        return 84;
    }
    return 0;
}