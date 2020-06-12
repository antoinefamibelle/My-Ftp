/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** '
*/

int	my_strcmp(char *str, char *string)
{
	int i = 0;

	while (str[i] == string[i] && str[i] && string[i])
		i = i + 1;
	if (str[i] == '\0' && string[i] == '\0')
		return (0);
    return (str[i] - string[i]);
}