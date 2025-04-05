/*
** EPITECH PROJECT, 2024
** B-MUL-100-MPL-1-1-myradar-teddy.bertrand
** File description:
** drawsprites_radar.c
*/

#include "./my.h"

void set_hitbox(menu_t *menu, tower_t *tower, int i)
{
    sfCircleShape_setRadius(menu->towers_hitbox, tower[i].radius);
    sfCircleShape_setOrigin(menu->towers_hitbox, (sfVector2f) {
        sfCircleShape_getRadius(menu->towers_hitbox),
        sfCircleShape_getRadius(menu->towers_hitbox)
    });
    sfCircleShape_setPosition(menu->towers_hitbox, (sfVector2f) {
        sfSprite_getPosition(menu->Sptower).x,
        sfSprite_getPosition(menu->Sptower).y
    });
}

void draw_towers(sfRenderWindow *window, menu_t *menu, tower_t *tower)
{
    for (int i = 0; i != menu->towers; i++) {
        sfSprite_setOrigin(menu->Sptower, (sfVector2f){
                sfTexture_getSize(menu->tower).x / 2,
            sfTexture_getSize(menu->tower).y / 2
        });
        sfSprite_setPosition(menu->Sptower,
        (sfVector2f){tower[i].x, tower[i].y});
        set_hitbox(menu, tower, i);
        if (menu->sprites == 1)
            sfRenderWindow_drawSprite(window, menu->Sptower, NULL);
        if (menu->hitboxes == 1)
            sfRenderWindow_drawCircleShape(window, menu->towers_hitbox, NULL);
    }
}

void check_planes_arrived(sfRenderWindow *window, menu_t *menu,
    planes_t *planes)
{
    for (int i = 0; i != menu->planes; i++) {
        if (planes[i].arrived == 1)
            planes->nb_arrived += 1;
        if (planes->nb_arrived == menu->planes)
            sfRenderWindow_close(window);
    }
}

static int clock_delay(planes_t *planes, menu_t *menu, int i)
{
    menu->delay_time = sfClock_getElapsedTime(menu->delay_clock);
    if (sfTime_asSeconds(menu->delay_time) < planes[i].delay) {
        return (1);
    } else {
        return (0);
    }
}

void draw_planes(sfRenderWindow *window, planes_t *planes,
    menu_t *menu, tower_t *tower)
{
    for (int i = 0; i != menu->planes; i++) {
            check_isintower(planes, menu, tower, i);
            if (planes[i].arrived == 0 && clock_delay(planes, menu, i) == 0) {
            draw(menu, planes, i, window);
        }
        }
}

static void menu_draw(sfRenderWindow *window, menu_t *menu,
    planes_t *planes, tower_t *tower)
{
    if (menu->gamestate == 0) {
    sfRenderWindow_drawSprite(window, menu->sprite, NULL);
    sfRenderWindow_drawSprite(window, menu->Sptitre, NULL);
    sfRenderWindow_drawSprite(window, menu->Spoptions, NULL);
    sfRenderWindow_drawSprite(window, menu->Spexit, NULL);
    sfRenderWindow_drawSprite(window, menu->Spstart, NULL);
    }
    each_frame(menu, window, planes, tower);
}

void window_draw(sfRenderWindow *window, menu_t *menu,
    planes_t *plane, tower_t *tower)
{
    sfRenderWindow_clear(window, sfBlack);
    menu_draw(window, menu, plane, tower);
    sfRenderWindow_display(window);
}
