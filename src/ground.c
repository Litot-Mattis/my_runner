/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** ground.c
*/

#include "utilities.h"

void create_ground(my_hunter_t *ht)
{
    ht->clock = sfClock_create();
    ht->seconde = 0;
    ht->ground_t = sfTexture_createFromFile("assets/ground.png", NULL);
    ht->ground_s = sfSprite_create();
    sfSprite_setTexture(ht->ground_s, ht->ground_t, sfTrue);
    sfSprite_setScale(ht->ground_s, (sfVector2f) {4, 4.2});
    my_ground_s(ht);
}

void create_ground2(my_hunter_t *ht)
{
    ht->clock = sfClock_create();
    ht->seconde = 0;
    ht->ground_2t = sfTexture_createFromFile("assets/ground.png", NULL);
    ht->ground_2s = sfSprite_create();
    sfSprite_setTexture(ht->ground_2s, ht->ground_2t, sfTrue);
    sfSprite_setScale(ht->ground_2s, (sfVector2f) {4, 4.2});
    my_ground_2s(ht);
}

void my_ground_s(my_hunter_t *ht)
{
    ht->ground_pos.x = 0;
    ht->ground_pos.y = 0;
    sfSprite_setPosition(ht->ground_s, ht->ground_pos);
}

void my_ground_2s(my_hunter_t *ht)
{
    ht->ground_2pos.x = 1080;
    ht->ground_2pos.y = 0;
    sfSprite_setPosition(ht->ground_2s, ht->ground_2pos);
}