/*
** EPITECH PROJECT, 2024
** B-MUL-100-MPL-1-1-myradar-teddy.bertrand
** File description:
** events.c
*/
#include "./my.h"

int keyboard(menu_t *menu, sfEvent *event)
{
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyL) {
        menu->hitboxes *= -1;
        return (0);
    }
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyS) {
        menu->sprites *= -1;
        return (0);
    }
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyR) {
        menu->ralenti *= -1;
        return (0);
    }
}

void events(sfRenderWindow *window, sfEvent event, menu_t *menu)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
            keyboard(menu, &event);
            clicks(window, menu, &event);
    }
}
