/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** mysh
*/

#include "my.h"
#include "mym.h"

char* find_command_path(const char* command, Mysh *mysh, char **args)
{
    char **path_entry = NULL;
    char * temp = NULL;

    path_entry = str_to_word_array(mysh->path, ':');
    if (access(args[0], X_OK) == 0)
        return args[0];
    if (path_entry[0] == NULL)
        path_entry[0] = mysh->path;
    for (int i = 0; path_entry[i] != NULL ;i++) {
        free(temp);
        temp = malloc(sizeof(char) *
        ((my_strlen(path_entry[i]) + my_strlen(args[0])) + 2));
        temp = my_strcpy(temp, path_entry[i]);
        temp = my_strcat(temp, "/");
        temp = my_strcat(temp, args[0]);
        temp[my_strlen(temp)] = '\0';
        if (access(temp, X_OK) == 0)
            return temp;
    }
    return NULL;
}
