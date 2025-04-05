/*
** EPITECH PROJECT, 2024
** B-MUL-100-MPL-1-1-myradar-teddy.bertrand
** File description:
** shortest_path.c
*/
#include "./my.h"

void resetvector_plus(planes_t *plane)
{
    if (plane->path == 3) {
    plane->vectorx = plane->x2 - plane->x1;
    plane->vectory = plane->y2 + 1200 - plane->y1;
    plane->norme = sqrt(pow(plane->vectorx, 2) + pow(plane->vectory, 2));
    }
    if (plane->path == 4) {
    plane->vectorx = plane->x2 - plane->x1;
    plane->vectory = plane->y2 - 1200 - plane->y1;
    plane->norme = sqrt(pow(plane->vectorx, 2) + pow(plane->vectory, 2));
    }
}

static void resetvector(planes_t *plane)
{
    if (plane->path == 0) {
    plane->vectorx = plane->x2 - plane->x1;
    plane->vectory = plane->y2 - plane->y1;
    plane->norme = sqrt(pow(plane->vectorx, 2) + pow(plane->vectory, 2));
    }
    if (plane->path == 1) {
    plane->vectorx = plane->x2 + 1920 - plane->x1;
    plane->vectory = plane->y2 - plane->y1;
    plane->norme = sqrt(pow(plane->vectorx, 2) + pow(plane->vectory, 2));
    }
    if (plane->path == 2) {
    plane->vectorx = plane->x2 - 1920 - plane->x1;
    plane->vectory = plane->y2 - plane->y1;
    plane->norme = sqrt(pow(plane->vectorx, 2) + pow(plane->vectory, 2));
    }
    resetvector_plus(plane);
}

void shortest_path_plus(planes_t *plane)
{
    if (sqrt(pow(plane->vectorx, 2) + pow(plane->vectory, 2)) < plane->norme) {
    plane->norme = sqrt(pow(plane->vectorx, 2) + pow(plane->vectory, 2));
    plane->path = 2;
    }
    plane->vectorx = plane->x2 - plane->x1;
    plane->vectory = plane->y2 + 1200 - plane->y1;
    if (sqrt(pow(plane->vectorx, 2) + pow(plane->vectory, 2)) < plane->norme) {
    plane->norme = sqrt(pow(plane->vectorx, 2) + pow(plane->vectory, 2));
    plane->path = 3;
    }
    plane->vectorx = plane->x2 - plane->x1;
    plane->vectory = plane->y2 - 1200 - plane->y1;
    if (sqrt(pow(plane->vectorx, 2) + pow(plane->vectory, 2)) < plane->norme) {
    plane->norme = sqrt(pow(plane->vectorx, 2) + pow(plane->vectory, 2));
    plane->path = 4;
    }
}

void shortest_path(planes_t *plane)
{
    plane->path = 0;
    plane->vectorx = plane->x2 - plane->x1;
    plane->vectory = plane->y2 - plane->y1;
    plane->norme = sqrt(pow(plane->vectorx, 2) + pow(plane->vectory, 2));
    plane->vectorx = plane->x2 + 1920 - plane->x1;
    plane->vectory = plane->y2 - plane->y1;
    if (sqrt(pow(plane->vectorx, 2) + pow(plane->vectory, 2)) < plane->norme) {
    plane->norme = sqrt(pow(plane->vectorx, 2) + pow(plane->vectory, 2));
    plane->path = 1;
    }
    plane->vectorx = plane->x2 - 1920 - plane->x1;
    plane->vectory = plane->y2 - plane->y1;
    shortest_path_plus(plane);
    resetvector(plane);
}
