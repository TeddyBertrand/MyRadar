/*
** EPITECH PROJECT, 2024
** B-MUL-100-MPL-1-1-myradar-teddy.bertrand
** File description:
** clock.c
*/
#include "./my.h"

void othergamestates(sfRenderWindow *window, menu_t *menu)
{
    if (menu->gamestate == 2) {
    sfRenderWindow_drawSprite(window, menu->Spoptback, NULL);
    sfRenderWindow_drawSprite(window, menu->Splucas, NULL);
    sfRenderWindow_drawSprite(window, menu->Spskin, NULL);
    if (menu->istxt == 1) {
    sfText_setString(menu->text, "Je t'aime");
    sfRenderWindow_drawText(window, menu->text, NULL);
    }
    }
    if (menu->gamestate != 0)
    sfRenderWindow_drawSprite(window, menu->Spret, NULL);
}

void each_frame(menu_t *menu, sfRenderWindow *window,
    planes_t *planes, tower_t *tower)
{
    sfTime time = sfClock_getElapsedTime(planes->clock);

    if (sfTime_asSeconds(time) > 1 / 60) {
    if (menu->gamestate == 1) {
    sfRenderWindow_drawSprite(window, menu->Spbackradar, NULL);
    sfRenderWindow_drawText(window, menu->timer, NULL);
    menu->len_text = getlen(sfTime_asSeconds(menu->delay_time));
    menu->str = malloc(sizeof(char) * (menu->len_text + 1));
    sfText_setString(menu->secondes, my_put_string(
    (int)sfTime_asSeconds(menu->delay_time), menu->len_text, menu->str, 1));
    sfRenderWindow_drawText(window, menu->secondes, NULL);
    draw_towers(window, menu, tower);
        planes->nb_arrived = 0;
    check_planes_arrived(window, menu, planes);
    check_isinplane(planes, menu, tower);
    draw_planes(window, planes, menu, tower);
        sfClock_restart(planes->clock);
        }
    }
    othergamestates(window, menu);
}
