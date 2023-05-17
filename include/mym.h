/*
** EPITECH PROJECT, 2022
** my.r
** File description:
** my.r
*/

#ifndef MYM_H
    #define MYM_H

typedef struct {
    char **new_env;
    char *home;
    char *pwd;
    char *hold;
    char *oldpwd;
    char *path;
    int index;
    int find_env;
    int len_env;
    int find_pwd;
    int find_oldpwd;
} Mysh;

    #include <stddef.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/wait.h>
    #include <signal.h>

    int main(int arc, char *arv[], char **env);
    int main_loop(char **env);
    int find_command(char *command, Mysh *mysh);
    int execute_command(char *command);
    void print_env(Mysh *mysh);
    char* my_strnncat(char* dest, const char* src, size_t n, size_t m);
    int all_builtins(char **args, Mysh *mysh);
    void execute_cd(Mysh *mysh, char **args);
    void change_pwd(Mysh *mysh);
    char* find_command_path(const char* command, Mysh *mysh, char **args);
    int check_child_command(Mysh *mysh, char *command, char **args, char *path);
    void change_oldpwd(Mysh *mysh, char *cwd);
    void event_setenv(Mysh *mysh, char **args);
    char **event_unsetenv(Mysh *mysh, char **args);
    char **copy_array(char **array);
    char **copy_array_remove(char **array, int remove_line);
    char **copy_array_add(char **array, int add_line);
    char* my_strnncat(char* dest, const char* src, size_t n, size_t m);
    char **str_to_word_array(char *str, char separator);
#endif
