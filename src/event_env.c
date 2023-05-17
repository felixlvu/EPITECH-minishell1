/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** mysh
*/

#include "my.h"
#include "mym.h"

char **find_arg(Mysh *mysh, char **args, char **temp, int i)
{
    if (my_strncmp(mysh->new_env[i], args[1], my_strlen(args[1])) == 0) {
        if (mysh->new_env[i][my_strlen(args[1])] == '='
        && mysh->new_env[mysh->index + 1] != NULL) {
            temp[i] = malloc(sizeof(char) *
            (my_strlen(mysh->new_env[mysh->index + 1]) + 1));
            temp[i][my_strlen(mysh->new_env[mysh->index + 1])] = '\0';
            temp[i] = my_strcpy(temp[i], mysh->new_env[mysh->index + 1]);
            mysh->index++;
        } else {
            temp[i] = malloc(sizeof(char) *
            (my_strlen(mysh->new_env[mysh->index]) + 1));
            temp[i][my_strlen(mysh->new_env[mysh->index])] = '\0';
            temp[i] = my_strcpy(temp[i], mysh->new_env[mysh->index]);
        }
    } else if (mysh->new_env[mysh->index] != NULL) {
        temp[i] = malloc(sizeof(char) *
        (my_strlen(mysh->new_env[mysh->index]) + 1));
        temp[i][my_strlen(mysh->new_env[mysh->index])] = '\0';
        temp[i] = my_strcpy(temp[i], mysh->new_env[mysh->index]);
    } return temp;
}

char **event_unsetenv(Mysh *mysh, char **args)
{
    char **temp = NULL;
    int len_env = 0;
    mysh->index = 0;
    int i = 0;

    for (len_env = 0; mysh->new_env[len_env] != NULL; len_env++);
    temp = malloc(sizeof(char *) * (len_env));
    for (i = 0; my_strncmp(mysh->new_env[i],
    args[1], my_strlen(args[1])) != 0; i++) {
        if (i == len_env - 1)
            return (mysh->new_env);
    }
    for (i = 0; mysh->new_env[i] != NULL; i++) {
        temp = find_arg(mysh, args, temp, i);
        mysh->index++;
        free(mysh->new_env[i]);
    }
    free(mysh->new_env);
    temp[len_env - 1] = NULL;
    return (temp);
}

void print_env(Mysh *mysh)
{
    int i = 0;

    for (i = 0; mysh->new_env[i] != NULL; i++) {
        my_putstr(mysh->new_env[i]);
        my_putstr("\n");
    }
}
