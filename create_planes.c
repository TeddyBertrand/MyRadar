/*
** EPITECH PROJECT, 2024
** B-MUL-100-MPL-1-1-myradar-teddy.bertrand
** File description:
** create_planes.c
*/
#include "./my.h"

void how_many_plane_tower(menu_t *menu, char **argv)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    char **str;

    menu->planes = 0;
    menu->towers = 0;
    fp = fopen(argv[1], "r");
    if (fp == NULL)
        exit(84);
    while ((getline(&line, &len, fp) != -1)) {
        str = str_to_word_array(line);
        if (str[0][0] == 'A')
            menu->planes += 1;
        if (str[0][0] == 'T')
            menu->towers += 1;
    }
}

void add_plane(planes_t *plane, char **str)
{
    plane->x1 = my_getnbr(str[1]);
    plane->y1 = my_getnbr(str[2]);
    plane->x2 = my_getnbr(str[3]);
    plane->y2 = my_getnbr(str[4]);
    plane->speed = my_getnbr(str[5]);
    plane->delay = my_getnbr(str[6]);
    shortest_path(plane);
    plane->rotation = atan2(plane->vectory, plane->vectorx);
    plane->vectorx /= plane->norme;
    plane->vectory /= plane->norme;
    plane->arrived = 0;
    plane->rotation = plane->rotation * (180 / PI);
}

void add_tower(tower_t *tower, char **str)
{
    tower->x = my_getnbr(str[1]);
    tower->y = my_getnbr(str[2]);
    tower->radius = my_getnbr(str[3]);
}

void add_to_list(char **str, planes_t *plane, tower_t *tower, menu_t *menu)
{
    if (str[0][0] == 'A') {
        add_plane(&plane[menu->compteur.a], str);
        menu->compteur.a += 1;
    }
    if (str[0][0] == 'T') {
        add_tower(&tower[menu->compteur.t], str);
        menu->compteur.t += 1;
    }
}

void create_planes(planes_t *plane, tower_t *tower, char **argv, menu_t *menu)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    char **str;

    menu->compteur.a = 0;
    menu->compteur.t = 0;
    fp = fopen(argv[1], "r");
    while ((getline(&line, &len, fp) != -1)) {
        str = str_to_word_array(line);
        add_to_list(str, plane, tower, menu);
    }
}
