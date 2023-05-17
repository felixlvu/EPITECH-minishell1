/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** mysh
*/

#include "my.h"
#include "mym.h"

void init_path(Mysh *mysh)
{
    int i = 0;
    mysh->path = NULL;

    for (i = 0; mysh->new_env[i] != NULL; i++) {
        if (my_strncmp(mysh->new_env[i], "PATH=", 5) == 0) {
            mysh->path = malloc(sizeof(char) * (my_strlen(mysh->new_env[i])));
            mysh->path = my_strnncat(mysh->path, mysh->new_env[i], 5, 0);
        }
    }
    if (mysh->path != NULL) {
        mysh->path[my_strlen(mysh->path)] = '\0';
    } else {
        mysh->path = malloc(sizeof(char) * 6);
        mysh->path = my_strcpy(mysh->path, "/bin/");
    }
}

void find_elements(char **env, Mysh *mysh)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], "HOME", 4) == 0)
            mysh->find_env = i;
    }
    mysh->home = malloc(sizeof(char *) * (my_strlen(env[mysh->find_env]) - 5));
    my_strnncat(mysh->home, env[mysh->find_env], 5, 0);
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], "PWD", 3) == 0) {
            mysh->find_pwd = i;
        }
    }
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], "OLDPWD", 6) == 0) {
            mysh->find_oldpwd = i;
        }
    }
}

void create_new_env(char **env, Mysh *mysh)
{
    int len_env = 0;
    int i = 0;

    for (len_env = 0 ; env[len_env] != NULL; len_env++);

    mysh->new_env = malloc(sizeof(char *) * (len_env + 1));
    for (i = 0; env[i] != NULL; i++) {
        mysh->new_env[i] = malloc(sizeof(char) * my_strlen(env[i]) + 1);
        mysh->new_env[i] = my_strcpy(mysh->new_env[i], env[i]);
    }
    mysh->new_env[i] = NULL;
}

int main_loop(char **env)
{
    Mysh *mysh;
    char *command = NULL;
    size_t size = 0;
    mysh = malloc(sizeof(Mysh));
    int ret = 0;

    create_new_env(env, mysh);
    find_elements(env, mysh);
    init_path(mysh);

    while (1) {
        if (isatty(0) == 1)
            my_putstr("$> ");
        if (getline(&command, &size, stdin) == -1)
            return (0);
        if (find_command(command, mysh) == 1)
            return 1;
    }
    free(mysh);
    return ret;
}
