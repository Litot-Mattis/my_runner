/*
** EPITECH PROJECT, 2019
** my_hunter-master
** File description:
** my_hunter.c
*/

#include "utilities.h"

void clock(my_hunter_t *ht)
{
    ht->time = sfClock_getElapsedTime(ht->clock);
    ht->seconde = ht->time.microseconds / 1000000.0;
    if (ht->seconde > 0.08) {
        move_rect(ht, 64, 192);
        sfClock_restart(ht->clock);
    }
}

void paralax(obj_t *object, my_hunter_t *ht)
{
    move_map_1_s(&object[0]);
    move_map_1_2s(&object[1]);
    move_map_2_s(&object[2]);
    move_map_2_2s(&object[3]);
    move_map_3_s(&object[4]);
    move_map_3_2s(&object[5]);
    move_ground_s(ht);
    move_box(ht);
}

void display(my_hunter_t *ht)
{
    sfRenderWindow_drawSprite(ht->window, ht->ground_s, NULL);
    sfRenderWindow_drawSprite(ht->window, ht->ground_2s, NULL);
    sfRenderWindow_drawSprite(ht->window, ht->chara.hero_s, NULL);
    sfSprite_setTextureRect(ht->chara.hero_s, ht->move.rect);
    for (int i = 0; i < ht->game_obj.map.size; i += 1)
        sfRenderWindow_drawSprite(ht->window,
        ht->game_obj.map.map_sprite[i].sprite, NULL);
    if (ht->chara.boolean == 1)
        jump_hero(ht);
    clock(ht);
}