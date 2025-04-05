/*
** EPITECH PROJECT, 2024
** B-MUL-100-MPL-1-1-myradar-teddy.bertrand
** File description:
** str_to_word_array.c
*/
#include "./my.h"

int howmany_words(char *str)
{
    int space = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ')
            space++;
    }
    return (space);
}

int how_manyletters(char *str, int j)
{
    int space = j;
    int current_space = 0;
    int i = 0;
    int taille = 0;

    for (; str[i] != '\0' && current_space != space; i++) {
        if (str[i] == ' ') {
            current_space++;
        }
    }
    for (; str[i] != '\0' && str[i] != ' '; i++) {
        taille++;
    }
    return (taille);
}

char **str_to_word_array(char *str)
{
    int space = howmany_words(str);
    int j = 0;
    int k = 0;
    char **buffer = malloc(sizeof(char *) * (space + 2));

    for (int i = 0; i <= space; i++) {
        buffer[i] = malloc(sizeof(char) * (how_manyletters(str, i) + 3));
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            buffer[k][j] = '\0';
            j = 0;
            k += 1;
            i++;
        }
        buffer[k][j] = str[i];
        j++;
    }
    return (buffer);
}
