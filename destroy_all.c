/*
** EPITECH PROJECT, 2024
** B-MUL-100-MPL-1-1-myradar-teddy.bertrand
** File description:
** destroy_all.c
*/
#include "./my.h"

void destroy(sfRenderWindow *window, clockbackground_t *clock, menu_t *menu)
{
    sfTexture_destroy(menu->texture);
    sfSprite_destroy(menu->sprite);
    sfTexture_destroy(menu->exit);
    sfSprite_destroy(menu->Spexit);
    sfTexture_destroy(menu->options);
    sfSprite_destroy(menu->Spoptions);
    sfTexture_destroy(menu->start);
    sfSprite_destroy(menu->Spstart);
    sfTexture_destroy(menu->ret);
    sfSprite_destroy(menu->Spret);
    sfTexture_destroy(menu->titre);
    sfSprite_destroy(menu->Sptitre);
    sfRenderWindow_destroy(window);
    sfClock_destroy(clock->clock);
}
