/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** first_fond.c
*/

#include "utilities.h"

void create_background_3(obj_t *object)
{
    object->clock = sfClock_create();
    object->seconds = 0;
    object->texture = sfTexture_createFromFile("assets/map3.png", NULL);
    object->sprite = sfSprite_create();
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    sfSprite_setScale(object->sprite, (sfVector2f) {4, 3.5});
    map3_s(object);
}

void create_background_3_2(obj_t *object)
{
    object->clock = sfClock_create();
    object->seconds = 0;
    object->texture = sfTexture_createFromFile("assets/map3.png", NULL);
    object->sprite = sfSprite_create();
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    sfSprite_setScale(object->sprite, (sfVector2f) {4, 3.5});
    map3_2s(object);
}

void map3_s(obj_t *object)
{
    object->pos.x = 0;
    object->pos.y = 0;
    sfSprite_setPosition(object->sprite, object->pos);
}

void map3_2s(obj_t *object)
{
    object->pos.x = 1080;
    object->pos.y = 0;
    sfSprite_setPosition(object->sprite, object->pos);
}