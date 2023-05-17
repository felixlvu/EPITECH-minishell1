/*
** EPITECH PROJECT, 2022
** poollib
** File description:
** poollib
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; i < n; i++) {
        if (*s1 != *s2) {
            return (*s1 < *s2) ? -1 : 1;
        }
        if (*s1 == '\0') {
            return 0;
        }
        s1++;
        s2++;
    }
    return 0;
}
