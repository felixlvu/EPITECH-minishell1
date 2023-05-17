/*
** EPITECH PROJECT, 2022
** poollib
** File description:
** poollib
*/

int my_getnbr(const char *str)
{
    int n = 0;
    int sign = 1;
    const char *p = str;

    if (*p == '-') {
        sign = -1;
        p++;
    }
    while (*p) {
        if (*p < '0' || *p > '9') {
            break;
        }
        n = n * 10 + (*p - '0');
        p++;
    }
    return sign * n;
}
