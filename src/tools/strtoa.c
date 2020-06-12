/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** strtoa
*/

#include "server.h"

void jump_space(char *str, int *p)
{
    int i = *p;

    while (str[i] && (str[i] == ' ' || str[i] == '\t'))
        ++i;
    *p = i;
}

int word_length(char *str, int *p)
{
    int cpt = 0;
    int i = *p;

    jump_space(str, &i);
    while (str[i]) {
        if (str[i] == ' ' || str[i] == '\t')
            break;
        ++i;
        ++cpt;
    }
    jump_space(str, &i);
    *p = i;
    return (cpt);
}

char **word_array_malloc(char *str)
{
    int i = 0;
    int j = 0;
    int length = 0;
    char **arr;

    while (str[i]) {
        word_length(str, &i);
        ++length;
    }
    arr = malloc(sizeof(char *) * (length + 1));
    i = 0;
    while (str[i]) {
        length = word_length(str, &i);
        arr[j] = malloc(sizeof(char) * (length + 1));
        ++j;
    }
    return (arr);
}

char **my_strtoa(char *str)
{
    int i = 0;
    int j = 0;
    int l = 0;
    char **arr;

    arr = word_array_malloc(str);
    while (str[i]) {
        jump_space(str, &i);
        while (str[i] && str[i] != ' ' && str[i] != '\t') {
            arr[j][l] = str[i];
            ++i;
            ++l;
        }
        if (str[i])
            arr[j][l] = '\0';
        l = 0;
        ++j;
    }
    return (arr);
}
