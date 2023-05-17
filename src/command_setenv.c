/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** mysh
*/

#include "my.h"
#include "mym.h"

void exit_multi_args(Mysh *mysh, char **args, int i)
{
    if (args[2] == NULL) {
        mysh->new_env[i] = malloc(sizeof(char) * (my_strlen(args[1]) + 2));
        mysh->new_env[i] = my_strcpy(mysh->new_env[i], args[1]);
        mysh->new_env[i] = my_strcat(mysh->new_env[i], "=");
        mysh->new_env[i] = my_strcat(mysh->new_env[i], "\0");
    } else {
        mysh->new_env[i] = malloc(sizeof(char) *
        (my_strlen(args[1]) + my_strlen(args[2]) + 2));
        mysh->new_env[i] = my_strcpy(mysh->new_env[i], args[1]);
        mysh->new_env[i] = my_strcat(mysh->new_env[i], "=");
        mysh->new_env[i] = my_strcat(mysh->new_env[i], args[2]);
        mysh->new_env[i] = my_strcat(mysh->new_env[i], "\0");
    }
}

int exit_event(Mysh *mysh, char **args)
{
    for (int i = 0; mysh->new_env[i] != NULL; i++) {
        if (my_strncmp(mysh->new_env[i], args[1], my_strlen(args[1])) == 0 &&
        mysh->new_env[i][my_strlen(args[1])] == '=') {
            free(mysh->new_env[i]);
            exit_multi_args(mysh, args, i);
            return 1;
        }
    }
    return 0;
}

char **check_args(char **args, int len, char **temp)
{
    if (args[2] == NULL) {
        temp[len] = malloc(sizeof(char) * (my_strlen(args[1]) + 2));
        temp[len][my_strlen(args[1])] = '\0';
    } else {
        temp[len] = malloc(sizeof(char) *
        (my_strlen(args[1]) + my_strlen(args[2]) + 2));
        temp[len][my_strlen(args[1]) + (my_strlen(args[2]) + 1)] = '\0';
    }

    temp[len] = my_strcpy(temp[len], args[1]);
    temp[len] = my_strcat(temp[len], "=");

    return temp;
}

void event_setenv(Mysh *mysh, char **args)
{
    char **temp = NULL;
    int len = 0;

    if (args[1] == NULL) {
        print_env(mysh);
        return;
    }
    if (exit_event(mysh, args) == 1)
        return;

    temp = copy_array_add(mysh->new_env, 1);
    for (len = 0; temp[len] != NULL; len++);

    free(temp[len]);
    temp = check_args(args, len, temp);
    if (args[2] != NULL)
        temp[len] = my_strcat(temp[len], args[2]);

    temp[len + 1] = NULL;
    mysh->new_env = copy_array(temp);
}
