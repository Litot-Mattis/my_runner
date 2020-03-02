/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** my_create.c
*/

#include "utilities.h"

void my_create_music(my_hunter_t *ht)
{
    ht->victory = 0;
    ht->music = sfMusic_createFromFile("assets/bgm_menu.ogg");
}

void my_create_window(my_hunter_t *ht)
{
    ht->video_mode.width = 1080;
    ht->video_mode.height = 600;
    ht->video_mode.bitsPerPixel = 32;
}

void create(my_hunter_t *ht)
{
    my_create_window(ht);
    my_create_music(ht);
    create_ground(ht);
    create_ground2(ht);
    create_character(ht);
    ht->window = sfRenderWindow_create(ht->video_mode,
        "RUNNER T'SES MORT", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(ht->window, 120);
}