/*
** EPITECH PROJECT, 2024
** myradar.c
** File description:
** my radar
*/
#include "./my.h"

void theclock(clockbackground_t *clock, sfRenderWindow *window, menu_t *menu)
{
    clock->time = sfClock_getElapsedTime(clock->clock);
    if (sfTime_asSeconds(clock->time) > 0.2f) {
        move_rectangle_back(menu, 1920, 15360);
        sfSprite_setTextureRect(menu->sprite, menu->rect);
        move_rectangle_back2(menu, 1920, 13440);
        sfSprite_setTextureRect(menu->Spoptback, menu->rect2);
        sfClock_restart(clock->clock);
    }
}

void clockposition(planes_t *planes, int i, menu_t *menu)
{
    sfTime time = sfClock_getElapsedTime(planes->clock);

    if (sfTime_asSeconds(time) > 0.2f) {
        planes[i].x1 += planes[i].vectorx * planes[i].speed / 60;
        planes[i].y1 += planes[i].vectory * planes[i].speed / 60;
        sfSprite_setPosition(menu->Spplane,
        (sfVector2f){planes[i].x1, planes[i].y1});
        sfClock_restart(planes->clock);
    }
}

void my_radar(int argc, char **argv)
{
    menu_t menu;
    planes_t *plane;
    tower_t *tower;
    clockbackground_t clock;
    sfRenderWindow *window = sfRenderWindow_create(
    (sfVideoMode) {1920, 1080, 32}, "My radar", sfClose, NULL);
    sfEvent event;

    how_many_plane_tower(&menu, argv);
    plane = malloc(sizeof(planes_t) * menu.planes);
    tower = malloc(sizeof(tower_t) * menu.towers);
    create_planes(plane, tower, argv, &menu);
    init_all(&menu, &clock, plane, window);
    while (sfRenderWindow_isOpen(window)) {
        theclock(&clock, window, &menu);
        events(window, event, &menu);
        window_draw(window, &menu, plane, tower);
    }
    destroy(window, &clock, &menu);
}

int main(int argc, char **argv)
{
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h')
    printhelp();
    my_radar(argc, argv);
    return (0);
}
