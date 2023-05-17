/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** mysh
*/

#include "my.h"
#include "mym.h"

int execute_command(char *command)
{
        char **args = NULL;
        char *temp = NULL;
        char *pwd = NULL;

        pwd = getcwd(pwd, 0);
        args = str_to_word_array(command, ' ');
        temp = malloc(sizeof(char) *
        ((my_strlen(pwd) + my_strlen(args[0])) + 2));
        temp = my_strcpy(temp, pwd);
        temp = my_strcat(temp, "/");
        temp = my_strnncat(temp, args[0], 2, my_strlen(temp));
        temp[my_strlen(temp)] = '\0';
        execve(temp, args, NULL);
    return 0;
}
