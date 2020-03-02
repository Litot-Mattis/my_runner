/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** second_main.c
*/

#include "utilities.h"

void game_objj(my_hunter_t *ht, obj_t object[6])
{
    object[0].type = BACK;
    object[1].type = BACK_2;
    object[2].type = MIDDLE;
    object[3].type = MIDDLE_2;
    object[4].type = FRONT;
    object[5].type = FRONT_2;
    for (int i = 0; i < 6; i += 1) {
        if (object[i].type == BACK)
            create_background_1(&object[0]);
        if (object[i].type == BACK_2)
            create_background_1_2(&object[1]);
        if (object[i].type == MIDDLE)
            create_background_2(&object[2]);
        if (object[i].type == MIDDLE_2)
            create_background_2_2(&object[3]);
        if (object[i].type == FRONT)
            create_background_3(&object[4]);
        if (object[i].type == FRONT_2)
            create_background_3_2(&object[5]);
    }
}

int loop_event(my_hunter_t *ht, sfEvent event)
{
    while (sfRenderWindow_pollEvent(ht->window, &ht->event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close;
        if (sfKeyboard_isKeyPressed(sfKeySpace)) {
            if (!ht->chara.boolean) {
                ht->chara.boolean = 1;
                ht->chara.velocity = -20;
            }
        }
        sfSprite_setPosition(ht->chara.hero_s, ht->chara.pos);
    }
}

int loop_open(my_hunter_t *ht, obj_t object[6], sfEvent event)
{
    if (ht->quit == 1)
        return (end_this_motherfucker(ht));
    while (sfRenderWindow_isOpen(ht->window)) {
        if (ht->game_obj.map.boole == 1) {
            my_putstr("DEFEAT\n");
            break;
        }
        if (ht->victory == 856) {
            my_putstr("VICTORY\n");
            break;
        }
        for (int i = 0; i < 6; i += 1)
            sfRenderWindow_drawSprite(ht->window, object[i].sprite, NULL);
        inside_loop(ht, object, event);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            break;
        clock(ht);
        sfRenderWindow_display(ht->window);
        sfRenderWindow_clear(ht->window, sfBlack);
    }
}