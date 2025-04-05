/*
** EPITECH PROJECT, 2024
** B-MUL-100-MPL-1-1-myradar-teddy.bertrand
** File description:
** click2.c
*/

#include "./my.h"

static void options_click2(sfRenderWindow *window,
    menu_t *menu, sfEvent *event)
{
    sfSprite_setScale(menu->Spoptions, (sfVector2f){3.8, 3.8});
    sfSprite_setPosition(menu->Spoptions, (sfVector2f) {770, 505});
    if (event->type == sfEvtMouseButtonReleased && menu->gamestate == 0) {
        menu->gamestate = 2;
    }
}

static void options_click(sfRenderWindow *window, menu_t *menu, sfEvent *event)
{
    sfVector2i mouse = sfMouse_getPosition((const sfWindow*) window);

    sfSprite_setPosition(menu->Spoptions, (sfVector2f) {760, 500});
    sfSprite_setScale(menu->Spoptions, (sfVector2f){4, 4});
    if (mouse.x >= sfSprite_getPosition(menu->Spoptions).x &&
        mouse.x <= sfSprite_getPosition(menu->Spoptions).x + 400) {
            if (mouse.y >= sfSprite_getPosition(menu->Spoptions).y &&
            mouse.y <= sfSprite_getPosition(menu->Spoptions).y + 130) {
                options_click2(window, menu, event);
            }
        }
}

static void return_click2(sfRenderWindow *window, menu_t *menu, sfEvent *event)
{
    sfSprite_setScale(menu->Spret, (sfVector2f){3.8, 3.8});
    if (event->type == sfEvtMouseButtonReleased) {
        menu->gamestate = 0;
    }
}

void return_click(sfRenderWindow *window, menu_t *menu, sfEvent *event)
{
    sfVector2i mouse = sfMouse_getPosition((const sfWindow*) window);

    sfSprite_setScale(menu->Spret, (sfVector2f){4, 4});
    if (mouse.x >= sfSprite_getPosition(menu->Spret).x &&
        mouse.x <= sfSprite_getPosition(menu->Spret).x + 130) {
            if (mouse.y >= sfSprite_getPosition(menu->Spret).y &&
            mouse.y <= sfSprite_getPosition(menu->Spret).y + 130) {
                return_click2(window, menu, event);
            }
        }
}

void exit_click2(sfRenderWindow *window, menu_t *menu, sfEvent *event)
{
    sfSprite_setScale(menu->Spexit, (sfVector2f){3.8, 3.8});
    sfSprite_setPosition(menu->Spexit, (sfVector2f) {825, 655});
    if (event->type == sfEvtMouseButtonReleased && menu->gamestate == 0) {
        sfRenderWindow_close(window);
    }
}

void exit_click(sfRenderWindow *window, menu_t *menu, sfEvent *event)
{
    sfVector2i mouse = sfMouse_getPosition((const sfWindow*) window);

    sfSprite_setScale(menu->Spexit, (sfVector2f){4, 4});
    sfSprite_setPosition(menu->Spexit, (sfVector2f) {815, 650});
    if (mouse.x >= sfSprite_getPosition(menu->Spexit).x &&
        mouse.x <= sfSprite_getPosition(menu->Spexit).x + 250) {
            if (mouse.y >= sfSprite_getPosition(menu->Spexit).y &&
            mouse.y <= sfSprite_getPosition(menu->Spexit).y + 130) {
                exit_click2(window, menu, event);
            }
    }
}

void clicks2(sfRenderWindow *window, menu_t *menu, sfEvent *event)
{
    options_click(window, menu, event);
    return_click(window, menu, event);
    exit_click(window, menu, event);
}
