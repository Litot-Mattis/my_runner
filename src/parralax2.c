/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** parralax2.c
*/

#include "utilities.h"

void move_map_2_s(obj_t *object)
{
    object->time = sfClock_getElapsedTime(object->clock);
    object->seconds = object->time.microseconds / 1000000.0;
    if (object->seconds >= 0.01f) {
        object->pos.x -= 1;
        sfSprite_setPosition(object->sprite, object->pos);
    }
    if (object->pos.x <= -2176) {
        object->pos.x = 1080;
        sfSprite_setPosition(object->sprite, object->pos);
    }
}

void move_map_2_2s(obj_t *object)
{
    object->time = sfClock_getElapsedTime(object->clock);
    object->seconds = object->time.microseconds / 1000000.0;
    if (object->seconds >= 0.01f) {
        object->pos.x -= 1;
        sfSprite_setPosition(object->sprite, object->pos);
    }
    if (object->pos.x <= -2176) {
        object->pos.x = 1080;
        sfSprite_setPosition(object->sprite, object->pos);
    }
}

void move_ground_s(my_hunter_t *ht)
{
        ht->timeg = sfClock_getElapsedTime(ht->clock);
    ht->seconde_g = ht->timeg.microseconds / 1000000.0;
    if (ht->seconde_g >= 0.01f) {
        ht->ground_pos.x -= 4;
        ht->ground_2pos.x -= 4;
        ht->victory += 1;
        sfSprite_setPosition(ht->ground_s, ht->ground_pos);
        sfSprite_setPosition(ht->ground_2s, ht->ground_2pos);
    }
    if (ht->ground_pos.x <= -2176) {
        ht->ground_pos.x = 1080;
        sfSprite_setPosition(ht->ground_s, ht->ground_pos);
    }
    if (ht->ground_2pos.x <= -2176) {
        ht->ground_2pos.x = 1080;
        sfSprite_setPosition(ht->ground_2s, ht->ground_2pos);
    }
}