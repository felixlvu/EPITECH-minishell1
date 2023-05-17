/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** mysh
*/

#include "my.h"
#include "mym.h"
#include <string.h>

int all_builtins(char **args, Mysh *mysh)
{
    if (my_strcmp(args[0], "cd") == 0) {
        execute_cd(mysh, args);
        return 2;
    }
    if (my_strcmp(args[0], "exit") == 0)
        exit(0);
    if (my_strcmp(args[0], "env") == 0) {
        print_env(mysh);
        return 2;
    }
    if (my_strcmp(args[0], "setenv") == 0) {
        event_setenv(mysh, args);
        return 2;
    }
    if (my_strcmp(args[0], "unsetenv") == 0) {
        mysh->new_env = event_unsetenv(mysh, args);
        return 2;
    }
    return 0;
}

int execute_child(char *command, Mysh *mysh, char **args)
{
    char *temp = NULL;
    int ret = 0;

    temp = find_command_path(command, mysh, args);

    if (args[0][0] == '.' && args[0][1] == '/') {
        ret = execute_command(command);
    } else {
        if (execve(temp, args, NULL) == -1) {
        my_printf("%s", args[0]);
        my_printf(": command not found\n");
        return 0;
        }
    }
    return ret;
}

char **init_args(char **args, char *command)
{
    char *token = NULL;
    int i = 0;

    args = malloc(sizeof(char *) * (my_strlen(command) + 1));
    token = strtok(command, " \t\r\n\a");
    while (token != NULL) {
        args[i] = token;
        i++;
        token = strtok(NULL, " \t\r\n\a");
    }
    args[i] = NULL;

    return args;
}

int find_command(char *command, Mysh *mysh)
{
    int ret = 0;
    char **args = NULL;
    char *path = NULL;
    mysh->pwd = NULL;

    args = init_args(args, command);

    if (args[0] == NULL)
        return 0;

    if (all_builtins(args, mysh) == 2)
        return 0;

    path = find_command_path(command, mysh, args);

    ret = check_child_command(mysh, command, args, path);
    return ret;
}
