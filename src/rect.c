/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** rect.c
*/

#include "utilities.h"

void create_character(my_hunter_t *ht)
{
    ht->chara.pos.x = 50;
    ht->chara.pos.y = 400;
    my_create_rect(ht);
    ht->chara.clock = sfClock_create();
    ht->chara.seconds = 0;
    ht->chara.hero_t = sfTexture_createFromFile("assets/hero_walk.png", NULL);
    ht->chara.hero_s = sfSprite_create();
    sfSprite_setTexture(ht->chara.hero_s, ht->chara.hero_t, sfTrue);
    sfSprite_setScale(ht->chara.hero_s, (sfVector2f) {2.5, 2.5});
    sfSprite_setPosition(ht->chara.hero_s, ht->chara.pos);
}

void my_create_rect(my_hunter_t *ht)
{
    ht->clock = sfClock_create();
    ht->move.x_speed = 0.2;
    ht->move.rect.top = 0;
    ht->move.rect.left = 0;
    ht->move.rect.width = 64;
    ht->move.rect.height = 64;
}

void move_rect(my_hunter_t *ht, int offset, int max_value)
{
    if (ht->move.rect.left == 128)
        ht->move.rect.left = 0;
    else
        ht->move.rect.left += offset;
}

void jump_hero(my_hunter_t *ht)
{
    if (ht->chara.boolean == 1) {
        ht->chara.pos.y += ht->chara.velocity;
        ht->chara.velocity += GRAVITY;
        if (ht->chara.pos.y >= 400) {
            ht->chara.pos.y = 400;
            ht->chara.velocity = 0;
            ht->chara.boolean = 0;
        }
    }
    sfSprite_setPosition(ht->chara.hero_s, ht->chara.pos);
}