/*
** EPITECH PROJECT, 2024
** B-MUL-100-MPL-1-1-myradar-teddy.bertrand
** File description:
** check collision.c
*/
#include "./my.h"

int isintower(planes_t *planes, tower_t *tower, int i, int current)
{
    if (tower[i].x - tower[i].radius <= planes[current].x1 &&
        tower[i].x + tower[i].radius >= planes[current].x1) {
            if (tower[i].y - tower[i].radius <= planes[current].y1 &&
            tower[i].y + tower[i].radius >= planes[current].y1) {
                return (1);
            }
    }
    return (0);
}

static void eachtower(planes_t *planes, tower_t *tower, int current,
    menu_t *menu)
{
    for (int i = 0; i != menu->towers; i++)
        if (isintower(planes, tower, i, current) == 1) {
            planes[current].protected = 0;
            return;
            }
    planes[current].protected = 1;
}

void check_isintower(planes_t *planes, menu_t *menu, tower_t *tower, int i)
{
    for (int current = 0; current != menu->planes; current++) {
        eachtower(planes, tower, current, menu);
    }
}

void isin_plane(planes_t *planes, int i, int current)
{
    if (planes[i].x1 - 20 <= planes[current].x1 &&
    planes[i].x1 + 20 >= planes[current].x1) {
                if (planes[i].y1 - 20 <= planes[current].y1 &&
                planes[i].y1 + 20 >= planes[current].y1) {
                    planes[i].arrived = 1;
                    planes[i].x1 = 0;
                    planes[i].y1 = 0;
                    planes[current].arrived = 1;
                    planes[current].x1 = 0;
                    planes[current].y1 = 0;
                }
            }
}

void goodplane(int i, int current, planes_t *planes)
{
    if (i != current && planes[current].protected == 1 &&
    planes[i].protected == 1)
        isin_plane(planes, i, current);
}

void check_isinplane(planes_t *planes, menu_t *menu,
    tower_t *tower)
{
    for (int current = 0; current != menu->planes; current++)
        for (int i = 0; i != menu->planes; i++) {
            goodplane(i, current, planes);
    }
}
