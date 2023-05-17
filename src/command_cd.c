/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** mysh
*/

#include "my.h"
#include "mym.h"

char *my_strcpycwd(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

void change_pwd(Mysh *mysh)
{
    char *cwd = NULL;
    char *temp = NULL;

    cwd = getcwd(cwd, 0);

    temp = malloc(sizeof(char) * (my_strlen(cwd) + 5));
    temp = my_strcpycwd(temp, "PWD=");
    temp = my_strcat(temp, cwd);

    for (int i = 4; mysh->new_env[mysh->find_pwd][i] != '\0'; i++)
        mysh->new_env[mysh->find_pwd][i] = '\0';

    free(mysh->new_env[mysh->find_pwd]);
    mysh->new_env[mysh->find_pwd] = malloc(sizeof(char) * (my_strlen(cwd) + 5));

    mysh->new_env[mysh->find_pwd] = my_strcpycwd(mysh->new_env[mysh->find_pwd],
    temp);

    free(temp);
}

void change_oldpwd(Mysh *mysh, char *cwd)
{
    char *temp = NULL;
    int i = 0;

    temp = malloc(sizeof(char) * (my_strlen(cwd) + 8));
    temp = my_strcpycwd(temp, "OLDPWD=");
    temp = my_strcat(temp, cwd);

    for (i = 4; mysh->new_env[mysh->find_oldpwd][i] != '\0'; i++)
        mysh->new_env[mysh->find_oldpwd][i] = '\0';

    free(mysh->new_env[mysh->find_oldpwd]);
    mysh->new_env[mysh->find_oldpwd] = malloc(
    sizeof(char) * (my_strlen(cwd) + 8));

    mysh->new_env[mysh->find_oldpwd] = my_strcpycwd(
    mysh->new_env[mysh->find_oldpwd], temp);

    free(temp);
}

void execute_cd(Mysh *mysh, char **args)
{
    char *pwd = NULL;

    if (args[1] == NULL) {
        args[1] = mysh->home;
    } else if (my_strcmp(args[1], "-") == 0 && mysh->oldpwd != NULL) {
        args[1] = mysh->oldpwd;
    }
    pwd = getcwd(pwd, 0);
    mysh->oldpwd = malloc(sizeof(char *) * my_strlen(pwd));
    mysh->oldpwd = my_strcpy(mysh->oldpwd, pwd);
    if (chdir(args[1]) == -1 && args[1] != mysh->home) {
        my_putstr(args[1]);
        my_putstr(": No such file or directory.\n");
    } else {
        change_oldpwd(mysh, pwd);
        change_pwd(mysh);
    }
}
