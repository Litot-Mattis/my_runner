/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** parralax.c
*/

#include "utilities.h"

void move_map_3_s(obj_t *object)
{
    object->time = sfClock_getElapsedTime(object->clock);
    object->seconds = object->time.microseconds / 1000000.0;
    if (object->seconds >= 0.01f) {
        object->pos.x -= 3;
        sfSprite_setPosition(object->sprite, object->pos);
    }
    if (object->pos.x <= -2176) {
        object->pos.x = 1080;
        sfSprite_setPosition(object->sprite, object->pos);
    }
}

void move_map_3_2s(obj_t *object)
{
    object->time = sfClock_getElapsedTime(object->clock);
    object->seconds = object->time.microseconds / 1000000.0;
    if (object->seconds >= 0.01f) {
        object->pos.x -= 3;
        sfSprite_setPosition(object->sprite, object->pos);
    }
    if (object->pos.x <= -2176) {
        object->pos.x = 1080;
        sfSprite_setPosition(object->sprite, object->pos);
    }
}

void move_map_1_s(obj_t *object)
{
    object->time = sfClock_getElapsedTime(object->clock);
    object->seconds = object->time.microseconds / 1000000.0;
    if (object->seconds >= 0.01f) {
        object->pos.x -= 0.3f;
        sfSprite_setPosition(object->sprite, object->pos);
    }
    if (object->pos.x <= -1080) {
        object->pos.x = 1080;
        sfSprite_setPosition(object->sprite, object->pos);
    }
}

void move_map_1_2s(obj_t *object)
{
    object->time = sfClock_getElapsedTime(object->clock);
    object->seconds = object->time.microseconds / 1000000.0;
    if (object->seconds >= 0.01f) {
        object->pos.x -= 0.3f;
        sfSprite_setPosition(object->sprite, object->pos);
    }
    if (object->pos.x <= -1080) {
        object->pos.x = 1080;
        sfSprite_setPosition(object->sprite, object->pos);
    }
}