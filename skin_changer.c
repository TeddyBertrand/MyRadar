/*
** EPITECH PROJECT, 2024
** B-MUL-100-MPL-1-1-myradar-teddy.bertrand
** File description:
** skin_changer.c
*/
#include "./my.h"

void skin_changer3(menu_t *menu)
{
    if (menu->skinstate == 5) {
        menu->skin = sfTexture_createFromFile
        ("./texture/button_plane1.png", NULL);
        sfSprite_setTexture(menu->Spskin, menu->skin, sfTrue);
        menu->plane = sfTexture_createFromFile("./texture/plane1.png", NULL);
    sfSprite_setTexture(menu->Spplane, menu->plane, sfTrue);
    }
    if (menu->skinstate == 6) {
        menu->skin = sfTexture_createFromFile
        ("./texture/button_skin_tower.png", NULL);
        sfSprite_setTexture(menu->Spskin, menu->skin, sfTrue);
        menu->plane = sfTexture_createFromFile
        ("./texture/Control-Tower20x20.png", NULL);
    sfSprite_setTexture(menu->Spplane, menu->plane, sfTrue);
    }
}

void skin_changer2(menu_t *menu)
{
    if (menu->skinstate == 3) {
        menu->skin = sfTexture_createFromFile
        ("./texture/button_skin3.png", NULL);
        sfSprite_setTexture(menu->Spskin, menu->skin, sfTrue);
        menu->plane = sfTexture_createFromFile("./texture/skin3.png", NULL);
        sfSprite_setTexture(menu->Spplane, menu->plane, sfTrue);
    }
    if (menu->skinstate == 4) {
        menu->skin = sfTexture_createFromFile
        ("./texture/button_skin4.png", NULL);
        sfSprite_setTexture(menu->Spskin, menu->skin, sfTrue);
        menu->plane = sfTexture_createFromFile("./texture/skin4.png", NULL);
        sfSprite_setTexture(menu->Spplane, menu->plane, sfTrue);
    }
    skin_changer3(menu);
}

void skin_changer(menu_t *menu)
{
    if (menu->skinstate == 6)
    menu->skinstate = 0;
    menu->skinstate += 1;
    if (menu->skinstate == 1) {
    menu->skin = sfTexture_createFromFile("./texture/button_skin1.png", NULL);
    sfSprite_setTexture(menu->Spskin, menu->skin, sfTrue);
    menu->plane = sfTexture_createFromFile("./texture/skin1.png", NULL);
    sfSprite_setTexture(menu->Spplane, menu->plane, sfTrue);
    }
    if (menu->skinstate == 2) {
        menu->skin = sfTexture_createFromFile
        ("./texture/button_skin2.png", NULL);
        sfSprite_setTexture(menu->Spskin, menu->skin, sfTrue);
        menu->plane = sfTexture_createFromFile("./texture/skin2.png", NULL);
    sfSprite_setTexture(menu->Spplane, menu->plane, sfTrue);
    }
    skin_changer2(menu);
}
