/*
** EPITECH PROJECT, 2024
** B-MUL-100-MPL-1-1-myradar-teddy.bertrand
** File description:
** init_all.c
*/
#include "./my.h"

void set_position_and_scale(menu_t *menu)
{
    sfSprite_setScale(menu->Sptower, (sfVector2f){0.2, 0.2});
    sfSprite_setPosition(menu->Splucas, (sfVector2f) {-50, 200});
    sfSprite_setPosition(menu->Sptitre, (sfVector2f) {560, 200});
    sfSprite_setPosition(menu->Spstart, (sfVector2f) {500, 150});
    sfSprite_setPosition(menu->Spoptions, (sfVector2f) {480, 300});
    sfSprite_setPosition(menu->Spexit, (sfVector2f) {535, 450});
    sfSprite_setScale(menu->Splucas, (sfVector2f){1.2, 1.2});
    sfSprite_setScale(menu->Sptitre, (sfVector2f){0.5, 0.5});
    sfSprite_setScale(menu->Spret, (sfVector2f){4, 4});
    sfSprite_setScale(menu->Spstart, (sfVector2f){4, 4});
    sfSprite_setScale(menu->Spoptions, (sfVector2f){4, 4});
    sfSprite_setScale(menu->Spexit, (sfVector2f){4, 4});
}

void create_sprite(sfTexture **a, sfSprite **b, char *c)
{
    *a = sfTexture_createFromFile(c, NULL);
    *b = sfSprite_create();
    sfSprite_setTexture(*b, *a, sfTrue);
}

static void init_texts(menu_t *menu)
{
    menu->font = sfFont_createFromFile("./texture/doom.ttf");
    menu->text = sfText_create();
    menu->font_timer = sfFont_createFromFile("./texture/doom.ttf");
    menu->timer = sfText_create();
    menu->secondes = sfText_create();
    sfText_setString(menu->text, "Je t'aime");
    sfText_setFont(menu->text, menu->font);
    sfText_setCharacterSize(menu->text, 100);
    sfText_setColor(menu->text, sfRed);
    sfText_setPosition(menu->text, (sfVector2f) {180, 260});
    sfText_setString(menu->timer, "Timer : ");
    sfText_setFont(menu->timer, menu->font_timer);
    sfText_setCharacterSize(menu->timer, 100);
    sfText_setColor(menu->timer, sfYellow);
    sfText_setPosition(menu->timer, (sfVector2f) {1400, 70});
    sfText_setFont(menu->secondes, menu->font_timer);
    sfText_setCharacterSize(menu->secondes, 100);
    sfText_setColor(menu->secondes, sfYellow);
    sfText_setPosition(menu->secondes, (sfVector2f) {1700, 70});
}

void init_hitboxes(menu_t *menu)
{
    menu->planes_rect = sfRectangleShape_create();
    menu->towers_hitbox = sfCircleShape_create();
    sfRectangleShape_setFillColor(menu->planes_rect, sfTransparent);
    sfRectangleShape_setOutlineColor(menu->planes_rect, sfGreen);
    sfRectangleShape_setSize(menu->planes_rect, (sfVector2f) {20, 20});
    sfRectangleShape_setOutlineThickness(menu->planes_rect, 2);
    sfCircleShape_setFillColor(menu->towers_hitbox, sfTransparent);
    sfCircleShape_setOutlineColor(menu->towers_hitbox, sfBlue);
    sfCircleShape_setOutlineThickness(menu->towers_hitbox, 2);
}

void init_sprites(menu_t *menu)
{
    create_sprite(&menu->lucas, &menu->Splucas, "./texture/lucas.png");
    create_sprite(&menu->tower, &menu->Sptower,
    "./texture/Control-Tower.png");
    create_sprite(&menu->plane, &menu->Spplane, "./texture/skin1.png");
    create_sprite(&menu->backradar, &menu->Spbackradar,
    "./texture/backradar.png");
    create_sprite(&menu->titre, &menu->Sptitre, "./texture/titre.png");
    create_sprite(&menu->optback, &menu->Spoptback,
    "./texture/optionsback.png");
    create_sprite(&menu->ret, &menu->Spret, "./texture/return.png");
    create_sprite(&menu->texture, &menu->sprite, "./texture/background.png");
    create_sprite(&menu->options, &menu->Spoptions, "./texture/options.png");
    create_sprite(&menu->start, &menu->Spstart, "./texture/start.png");
    create_sprite(&menu->exit, &menu->Spexit, "./texture/exit.png");
    create_sprite(&menu->skin, &menu->Spskin, "./texture/button_skin1.png");
}

static void init_int(menu_t *menu)
{
    menu->gamestate = 0;
    menu->rect.left = 0;
    menu->rect2.left = 0;
    menu->hitboxes = -1;
    menu->sprites = 1;
    menu->ralenti = -1;
    menu->compteur.a = 0;
    menu->compteur.t = 0;
    menu->skinstate = 1;
}

void init_all(menu_t *menu, clockbackground_t *clock,
    planes_t *plane, sfRenderWindow *window)
{
    init_sprites(menu);
    init_hitboxes(menu);
    init_texts(menu);
    set_position_and_scale(menu);
    init_int(menu);
    menu->cri = sfMusic_createFromFile("./texture/shout.mp3");
    clock->clock = sfClock_create();
    plane->clock = sfClock_create();
    menu->delay_clock = sfClock_create();
    sfRenderWindow_setFramerateLimit(window, 60);
}
