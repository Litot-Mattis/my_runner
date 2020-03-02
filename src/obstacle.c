/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** obstacle.c
*/

#include "utilities.h"

int create_obstacle(my_hunter_t *ht)
{
    int count = 0;
    ht->game_obj.map.map_sprite->clock = sfClock_create();
    ht->game_obj.map.map_sprite->seconds = 0;
    ht->game_obj.map.map_sprite->pos.y = 499;

    for (int i = 0; i < ht->game_obj.map.size ; i += 1) {
        ht->game_obj.map.map_sprite[i].pos.y = 499;
        ht->game_obj.map.map_sprite[i].pos.x = ht->game_obj.map.map[i];
        ht->game_obj.map.map_sprite[i].texture =
        sfTexture_createFromFile("assets/box.png", NULL);
        ht->game_obj.map.map_sprite[i].sprite = sfSprite_create();
        sfSprite_setTexture(ht->game_obj.map.map_sprite[i].sprite,
        ht->game_obj.map.map_sprite->texture, sfTrue);
        sfSprite_setScale(ht->game_obj.map.map_sprite[i].sprite,
        (sfVector2f){0.2, 0.2});
        sfSprite_setPosition(ht->game_obj.map.map_sprite[i].sprite, (sfVector2f)
        {ht->game_obj.map.map[i], ht->game_obj.map.map_sprite->pos.y});
    }
    return (0);
}

void move_box(my_hunter_t *ht)
{
    ht->game_obj.map.map_sprite->time =
    sfClock_getElapsedTime(ht->game_obj.map.map_sprite->clock);
    ht->game_obj.map.map_sprite->seconds =
    ht->game_obj.map.map_sprite->time.microseconds / 1000000.0;
    if (ht->game_obj.map.map_sprite->seconds >= 0.01f) {
        for ( int i = 0; i < ht->game_obj.map.size ; i += 1) {
            ht->game_obj.map.map_sprite[i].pos.x -= 4;
            sfSprite_setPosition(ht->game_obj.map.map_sprite[i].sprite,
            ht->game_obj.map.map_sprite[i].pos);
        }
    }
}

void collide(my_hunter_t *ht)
{
    ht->game_obj.map.boole = 0;
    for (int i = 0; i < ht->game_obj.map.size ; i += 1) {
        if (ht->chara.pos.x >= ht->game_obj.map.map_sprite[i].pos.x - 125 &&
        ht->chara.pos.x <= ht->game_obj.map.map_sprite[i].pos.x - 115) {
            if (ht->chara.pos.y >= ht->game_obj.map.map_sprite[i].pos.y - 100
            && ht->chara.pos.y <= ht->game_obj.map.map_sprite[i].pos.y) {
                ht->game_obj.map.boole = 1;
            }
        }
    }
}

void inside_loop(my_hunter_t *ht, obj_t object[6], sfEvent event)
{
    paralax(object, ht);
    display(ht);
    collide(ht);
    loop_event(ht, event);
}