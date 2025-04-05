/*
** EPITECH PROJECT, 2024
** B-MUL-100-MPL-1-1-myradar-teddy.bertrand
** File description:
** clicks.c
*/
#include "./my.h"

static void skin_click2(sfRenderWindow *window, menu_t *menu, sfEvent *event)
{
    sfSprite_setScale(menu->Spskin, (sfVector2f){2.9, 2.9});
    sfSprite_setPosition(menu->Spskin, (sfVector2f) {510, 250});
    if (event->type == sfEvtMouseButtonReleased && menu->gamestate == 2) {
        skin_changer(menu);
    }
}

static void skin_click(sfRenderWindow *window, menu_t *menu, sfEvent *event)
{
    sfVector2i mouse = sfMouse_getPosition((const sfWindow*) window);

    sfSprite_setPosition(menu->Spskin, (sfVector2f) {500, 250});
    sfSprite_setScale(menu->Spskin, (sfVector2f){3, 3});
    if (mouse.x >= sfSprite_getPosition(menu->Spskin).x + 40 &&
        mouse.x <= sfSprite_getPosition(menu->Spskin).x + 320) {
            if (mouse.y >= sfSprite_getPosition(menu->Spskin).y + 40 &&
            mouse.y <= sfSprite_getPosition(menu->Spskin).y + 320) {
                skin_click2(window, menu, event);
            }
        }
}

void lucas_click2(menu_t *menu, sfEvent *event)
{
    sfSprite_setScale(menu->Splucas, (sfVector2f){1.3, 1.3});
    sfSprite_setPosition(menu->Splucas, (sfVector2f) {-60, 170});
    if (event->type == sfEvtMouseButtonReleased && menu->gamestate == 2) {
        sfMusic_play(menu->cri);
        menu->istxt = 1;
    }
}

void lucas_click(sfRenderWindow *window, menu_t *menu, sfEvent *event)
{
    sfVector2i mouse = sfMouse_getPosition((const sfWindow*) window);

    sfSprite_setPosition(menu->Splucas, (sfVector2f) {-50, 200});
    sfSprite_setScale(menu->Splucas, (sfVector2f){1.2, 1.2});
    menu->istxt = 0;
    if (mouse.x >= sfSprite_getPosition(menu->Splucas).x &&
        mouse.x <= sfSprite_getPosition(menu->Splucas).x + 500) {
            if (mouse.y >= sfSprite_getPosition(menu->Splucas).y &&
            mouse.y <= sfSprite_getPosition(menu->Splucas).y + 1000) {
                lucas_click2(menu, event);
            }
        }
}

void start_click2(sfRenderWindow *window, menu_t *menu, sfEvent *event)
{
    sfSprite_setScale(menu->Spstart, (sfVector2f){3.8, 3.8});
    sfSprite_setPosition(menu->Spstart, (sfVector2f) {790, 355});
    if (event->type == sfEvtMouseButtonReleased && menu->gamestate == 0) {
        menu->gamestate = 1;
    }
}

void start_click(sfRenderWindow *window, menu_t *menu, sfEvent *event)
{
    sfVector2i mouse = sfMouse_getPosition((const sfWindow*) window);

    sfSprite_setPosition(menu->Spstart, (sfVector2f) {780, 350});
    sfSprite_setScale(menu->Spstart, (sfVector2f){4, 4});
    if (mouse.x >= sfSprite_getPosition(menu->Spstart).x &&
        mouse.x <= sfSprite_getPosition(menu->Spstart).x + 350) {
            if (mouse.y >= sfSprite_getPosition(menu->Spstart).y &&
            mouse.y <= sfSprite_getPosition(menu->Spstart).y + 130) {
                start_click2(window, menu, event);
            }
        }
}

void clicks(sfRenderWindow *window, menu_t *menu, sfEvent *event)
{
    start_click(window, menu, event);
    lucas_click(window, menu, event);
    skin_click(window, menu, event);
    clicks2(window, menu, event);
}
