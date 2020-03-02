/*
** EPITECH PROJECT, 2019
** my_hunter-master
** File description:
** utilities.h
*/

#ifndef UTILITIES_H
#define UTILITIES_H

#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <fcntl.h>

#define GRAVITY 0.84;

typedef struct map_sprite_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfClock *clock;
    sfVector2f pos;
    sfVector2f size;
    sfTime time;
    float seconds;
} map_sprite_t;

typedef struct map_s
{
    int *map;
    int size;
    int boole;
    map_sprite_t *map_sprite;
} map_t;

typedef struct my_hero_s {
    sfTexture *hero_t;
    sfSprite *hero_s;
    sfVector2f size;
    sfVector2f pos;
    sfIntRect rect;
    sfClock *clock;
    sfTime time;
    float seconds;
    int boolean;
    float velocity;
    int x;
    int y;
} my_hero_t;

typedef struct rect_s {
    sfClock *clock;
    sfIntRect rect;
    float x_speed;
} my_rect_t;

typedef enum PARA_s {
    BACK,
    BACK_2,
    MIDDLE,
    MIDDLE_2,
    FRONT,
    FRONT_2
} PARA_t;

typedef struct game_obj_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfClock *clock;
    sfVector2f pos;
    sfTime time;
    float seconds;
    PARA_t type;
    map_t map;
} obj_t;

typedef struct my_runner_s {
    my_hero_t chara;
    my_rect_t move;
    obj_t game_obj;
    sfRenderWindow *window;
    sfTexture *loose_t;
    sfTexture *map1_t;
    sfTexture *map2_t;
    sfTexture *map3_t;
    sfTexture *map4_t;
    sfTexture *map1_2t;
    sfTexture *map2_2t;
    sfTexture *map3_2t;
    sfTexture *map4_2t;
    sfTexture *ground_t;
    sfTexture *ground_2t;
    sfTexture *texture_menu;
    sfTexture *play_t;
    sfTexture *stop_t;
    sfTexture *p_t;
    sfSprite *p_s;
    sfSprite *loose_s;
    sfSprite *map1_s;
    sfSprite *map2_s;
    sfSprite *map3_s;
    sfSprite *map4_s;
    sfSprite *map1_2s;
    sfSprite *map2_2s;
    sfSprite *map3_2s;
    sfSprite *map4_2s;
    sfSprite *ground_s;
    sfSprite *ground_2s;
    sfSprite *s_menu;
    sfSprite *s_play;
    sfSprite *s_stop;
    sfMusic *music;
    sfClock *clock;
    sfVideoMode video_mode;
    sfTime time;
    sfTime time2;
    sfTime time3;
    sfTime timeg;
    sfTime time_bis;
    sfTime time2_bis;
    sfTime time3_bis;
    sfTime timeg_bis;
    sfVector2f map1_pos;
    sfVector2f map2_pos;
    sfVector2f map3_pos;
    sfVector2f map4_pos;
    sfVector2f ground_pos;
    sfVector2f map1_2pos;
    sfVector2f map2_2pos;
    sfVector2f map3_2pos;
    sfVector2f map4_2pos;
    sfVector2f ground_2pos;
    sfVector2f mouse;
    sfEvent event;
    float frame;
    int quit;
    int offset;
    int max_value;
    int victory;
    float seconde;
    float seconde2;
    float seconde3;
    float seconde_g;
    float seconde_bis;
    float seconde2_bis;
    float seconde3_bis;
    float seconde_gbis;
} my_hunter_t;

//second_main:
void game_objj(my_hunter_t *ht, obj_t object[6]);
int loop_event(my_hunter_t *ht, sfEvent event);
int loop_open(my_hunter_t *ht, obj_t object[6], sfEvent event);

// Functions of lib:
void my_putchar(char c);
int my_putstr(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_len(char const *str);

//main:
int documentation(void);
int end_this_motherfucker(my_hunter_t *ht);
int runner(my_hunter_t *ht);
int main(int ac, char **av);

//my_hunter: check
void clock(my_hunter_t *ht);
void paralax(obj_t *object, my_hunter_t *ht);
void display(my_hunter_t *ht);

//my_create: check
void my_create_music(my_hunter_t *ht);
void my_create_window(my_hunter_t *ht);
void create(my_hunter_t *ht);

//rect: check
void create_character(my_hunter_t *ht);
void my_create_rect(my_hunter_t *ht);
void move_rect(my_hunter_t *ht, int offset, int max_value);
void jump_hero(my_hunter_t *ht);

//first_fond: check
void create_background_3(obj_t *object);
void create_background_3_2(obj_t *object);
void map3_s(obj_t *object);
void map3_2s(obj_t *object);

//menu: check
void set(my_hunter_t *ht);
int click(my_hunter_t *ht, int x, int y);
int event(my_hunter_t *ht);
void destroy(my_hunter_t *ht);
void menu(my_hunter_t *ht);


//last_fond: check
void create_background_1(obj_t *object);
void create_background_1_2(obj_t *object);
void map1_s(obj_t *object);
void map1_2s(obj_t *object);

//second_fond: check
void create_background_2(obj_t *object);
void create_background_2_2(obj_t *object);
void map2_s(obj_t *object);
void map2_2s(obj_t *object);

//parralax:
void move_map_3_s(obj_t *object);
void move_map_3_2s(obj_t *object);
void move_map_1_s(obj_t *object);
void move_map_1_2s(obj_t *object);

//parralax2:
void move_map_2_s(obj_t *object);
void move_map_2_2s(obj_t *object);
void move_ground_s(my_hunter_t *ht);

//ground: check
void create_ground(my_hunter_t *ht);
void create_ground2(my_hunter_t *ht);
void my_ground_s(my_hunter_t *ht);
void my_ground_2s(my_hunter_t *ht);

//map: check
char *open_file(char const *map);
int my_count_obstacl(char **av, obj_t *game_obj);

//obstacle: check
int create_obstacle(my_hunter_t *ht);
void move_box(my_hunter_t *ht);
void collide(my_hunter_t *ht);
void inside_loop(my_hunter_t *ht, obj_t object[6], sfEvent event);

#endif
