/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** mysh
*/

#include "my.h"
#include "mym.h"

int main(int arc, char *arv[], char **env)
{
    if (arc != 1)
        return (84);
    int ret = main_loop(env);
    return (ret);
}
