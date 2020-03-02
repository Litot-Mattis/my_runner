/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** fond.c
*/

#include "utilities.h"

void create_background_1(obj_t *object)
{
    object->clock = sfClock_create();
    object->seconds = 0;
    object->texture = sfTexture_createFromFile("assets/map1.png", NULL);
    object->sprite = sfSprite_create();
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    sfSprite_setScale(object->sprite, (sfVector2f) {4, 4});
    map1_s(object);
}

void create_background_1_2(obj_t *object)
{
    object->clock = sfClock_create();
    object->seconds = 0;
    object->texture = sfTexture_createFromFile("assets/map1bis.png", NULL);
    object->sprite = sfSprite_create();
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    sfSprite_setScale(object->sprite, (sfVector2f) {4, 4});
    map1_2s(object);
}

void map1_s(obj_t *object)
{
    object->pos.x = 0;
    object->pos.y = 0;
    sfSprite_setPosition(object->sprite, object->pos);
}

void map1_2s(obj_t *object)
{
    object->pos.x = 1080;
    object->pos.y = 0;
    sfSprite_setPosition(object->sprite, object->pos);
}