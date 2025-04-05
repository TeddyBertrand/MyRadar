/*
** EPITECH PROJECT, 2024
** B-MUL-100-MPL-1-1-myradar-teddy.bertrand
** File description:
** help.c
*/
#include "./my.h"

int printhelp(void)
{
    int fd = open("./h.txt", O_RDONLY);
    char buffer[BUFSIZ + 1];
    int reader = read(fd, buffer, BUFSIZ + 1);

    if (fd == -1)
    return (84);
    for (int i = 0; buffer[i] != '\0'; i++)
    write(1, &buffer[i], 1);
    return (0);
}
