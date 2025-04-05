/*
** EPITECH PROJECT, 2024
** B-MUL-100-MPL-1-1-myradar-teddy.bertrand
** File description:
** set_pos.c
*/
#include "./my.h"

void gotthroughwalls(menu_t *menu, planes_t *planes, int i)
{
    if (planes[i].x1 >= 1920)
    planes[i].x1 -= 1920;
    if (planes[i].x1 <= 0)
    planes[i].x1 += 1920;
    if (planes[i].y1 >= 1200)
    planes[i].y1 -= 1200;
    if (planes[i].y1 <= 0)
    planes[i].y1 += 1200;
}

void set_position_plane(menu_t *menu, planes_t *planes, int i)
{
    gotthroughwalls(menu, planes, i);
    sfSprite_setOrigin(menu->Spplane, (sfVector2f){
        sfTexture_getSize(menu->plane).x / 2,
        sfTexture_getSize(menu->plane).y / 2
    });
    planes[i].x1 += planes[i].vectorx * planes[i].speed / 60;
    planes[i].y1 += planes[i].vectory * planes[i].speed / 60;
    sfSprite_setPosition(menu->Spplane,
    (sfVector2f){planes[i].x1, planes[i].y1});
    sfRectangleShape_setOrigin(menu->planes_rect, (sfVector2f){
        sfRectangleShape_getSize(menu->planes_rect).x / 2,
        sfRectangleShape_getSize(menu->planes_rect).y / 2
    });
    sfRectangleShape_setPosition(menu->planes_rect, (sfVector2f) {
        sfSprite_getPosition(menu->Spplane).x,
        sfSprite_getPosition(menu->Spplane).y
    });
}

void set_rotation_plane(menu_t *menu, planes_t *planes, int i)
{
    if (planes[i].rotation < 0)
        planes[i].rotation += 360;
    sfSprite_setRotation(menu->Spplane, planes[i].rotation + 90);
    if (planes[i].x1 >= planes[i].x2 - 10 &&
    planes[i].x1 <= planes[i].x2 + 10)
        if (planes[i].y1 >= planes[i].y2 - 10 &&
        planes[i].y1 <= planes[i].y2 + 10)
            planes[i].arrived = 1;
}
