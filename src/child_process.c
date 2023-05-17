/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** mysh
*/

#include "my.h"
#include "mym.h"

int check_type_child_next(Mysh *mysh, char *command, char **args, char *path)
{
    int ret = 0;

    if (args[0][0] == '.' && args[0][1] == '/') {
        ret = execute_command(command);
    } else {
        if (execve(path, args, NULL) == -1) {
            my_printf("%s", args[0]);
            my_printf(": Command not found.\n");
            return 0;
        }
    }
    return ret;
}

int check_type_child(Mysh *mysh, char *command, char **args, char *path)
{
    int pid = 0;
    int status = 0;
    int ret = 0;

    pid = fork();
    if (pid == 0) {
        ret = check_type_child_next(mysh, command, args, path);
    } else {
        waitpid(pid, &status, WUNTRACED);
    }
    if (WIFSIGNALED(status)) {
        if (WTERMSIG(status) == SIGSEGV) {
            write(2, "Segmentation fault\n", 19);
            return 139;
        }
    }
    return ret;
}

int check_child_command(Mysh *mysh, char *command, char **args, char *path)
{
    int ret = 0;

    if (access(path, X_OK) == 0) {
        ret = check_type_child(mysh, command, args, path);
        if (ret != 0)
            return ret;
    } else {
        my_printf("%s", args[0]);
        my_printf(": Command not found.\n");
        return 1;
    }
    return ret;
}
