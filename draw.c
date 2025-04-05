/*
** EPITECH PROJECT, 2024
** B-MUL-100-MPL-1-1-myradar-teddy.bertrand
** File description:
** draw.c
*/
#include "./my.h"

void draw(menu_t *menu, planes_t *planes, int i, sfRenderWindow *window)
{
    set_position_plane(menu, planes, i);
    set_rotation_plane(menu, planes, i);
    if (menu->sprites == 1)
        sfRenderWindow_drawSprite(window, menu->Spplane, NULL);
    if (menu->hitboxes == 1) {
        sfRenderWindow_drawRectangleShape(window,
        menu->planes_rect, NULL);
    }
}
