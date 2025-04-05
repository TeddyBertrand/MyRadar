/*
** EPITECH PROJECT, 2024
** B-MUL-100-MPL-1-1-myradar-teddy.bertrand
** File description:
** rectangles.c
*/
#include "./my.h"

void move_rectangle_back(menu_t *menu, int offset, int max_value)
{
    menu->rect.top = 0;
    menu->rect.left += offset;
    menu->rect.width = 1920;
    menu->rect.height = 1080;
    if (menu->rect.left >= max_value)
        menu->rect.left = 0;
}

void move_rectangle_back2(menu_t *menu, int offset, int max_value)
{
    menu->rect2.top = 0;
    menu->rect2.left += offset;
    menu->rect2.width = 1920;
    menu->rect2.height = 1080;
    if (menu->rect2.left >= max_value)
        menu->rect2.left = 0;
}
