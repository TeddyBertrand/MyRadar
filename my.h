/*
** EPITECH PROJECT, 2024
** B-MUL-100-MPL-1-1-myradar-teddy.bertrand
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdarg.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <math.h>
    #define PI 3.141592653589

typedef struct compteur {
    int a;
    int t;
} compteur_t;

typedef struct menu {
    sfRectangleShape *planes_rect;
    sfCircleShape *towers_hitbox;
    int istxt;
    int hitboxes;
    int sprites;
    int skinstate;
    int len_text;
    char *str;
    sfFont *font_timer;
    sfText *timer;
    sfFont *font;
    sfText *text;
    sfText *secondes;
    sfMusic *cri;
    sfSprite *Splucas;
    sfTexture *lucas;
    sfSprite *Spskin;
    sfTexture *skin;
    sfSprite *Spplane;
    sfTexture *plane;
    sfSprite *Sptower;
    sfTexture *tower;
    sfTexture *titre;
    sfSprite *Sptitre;
    sfTexture *start;
    sfSprite *Spstart;
    sfTexture *options;
    sfSprite *Spoptions;
    sfTexture *exit;
    sfSprite *Spexit;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfIntRect rect2;
    sfMusic *music;
    sfSound *button;
    sfTexture *ret;
    sfSprite *Spret;
    sfTexture *optback;
    sfSprite *Spoptback;
    sfTexture *backradar;
    sfSprite *Spbackradar;
    int gamestate;
    int planes;
    int towers;
    int ralenti;
    sfClock *delay_clock;
    sfTime delay_time;
    compteur_t compteur;
} menu_t;

typedef struct planes {
    sfTexture *plane;
    sfSprite *Spplane;
    float x1;
    float y1;
    int x2;
    int y2;
    int speed;
    int delay;
    int path;
    float vectorx;
    float vectory;
    float norme;
    sfClock *clock;
    int arrived;
    float rotation;
    int nb_arrived;
    int protected;
} planes_t;

typedef struct tower {
    sfTexture *tower;
    sfSprite *sptower;
    int x;
    int y;
    int radius;
} tower_t;

typedef struct clock {
    sfClock *clock;
    sfTime time;
} clockbackground_t;
int my_compute_square_root(int nb);
int getlen(int nb);
char *my_put_string(int nb, int len, char *str, int i);
int my_getnbr(char const *str);
char **str_to_word_array(char *str);
int printhelp(void);
void clicks(sfRenderWindow *window, menu_t *menu, sfEvent *event);
void move_rectangle_back(menu_t *menu, int offset, int max_value);
void move_rectangle_back2(menu_t *menu, int offset, int max_value);
int mini_printf(const char *format, ...);
int my_put_nbr(int nb);
int my_putstr(char const *str);
void my_putchar(char c);
void draw_towers(sfRenderWindow *window, menu_t *menu, tower_t *tower);
void check_planes_arrived(sfRenderWindow *window,
    menu_t *menu, planes_t *planes);
void draw_planes(sfRenderWindow *window, planes_t *planes,
    menu_t *menu, tower_t *tower);
void each_frame(menu_t *menu, sfRenderWindow *window,
    planes_t *planes, tower_t *tower);
void window_draw(sfRenderWindow *window, menu_t *menu,
    planes_t *plane, tower_t *tower);
void init_all(menu_t *menu, clockbackground_t *clock,
    planes_t *plane, sfRenderWindow *window);
void create_planes(planes_t *plane, tower_t *tower,
    char **argv, menu_t *menu);
void how_many_plane_tower(menu_t *menu, char **argv);
void events(sfRenderWindow *window, sfEvent event, menu_t *menu);
void destroy(sfRenderWindow *window, clockbackground_t *clock, menu_t *menu);
void clicks2(sfRenderWindow *window, menu_t *menu, sfEvent *event);
void skin_changer(menu_t *menu);
void check_isintower(planes_t *planes, menu_t *menu,
    tower_t *tower, int current);
void shortest_path(planes_t *plane);
void set_position_plane(menu_t *menu, planes_t *planes, int i);
void set_rotation_plane(menu_t *menu, planes_t *planes, int i);
void draw(menu_t *menu, planes_t *planes, int i, sfRenderWindow *window);
void check_isinplane(planes_t *planes, menu_t *menu,
    tower_t *tower);
#endif
