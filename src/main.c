/*
** EPITECH PROJECT, 2019
** my_hunter-master
** File description:
** main.c
*/

#include "utilities.h"

int documentation(void)
{
    my_putstr("~~HOW TO PLAY~~\n");
    my_putstr("Enter the command ./my_runner, \n");
    my_putstr("Enter in 2nd argument a map(.txt), \n");
    my_putstr("Example: ./my_runner src/map.txt\n");
}

int end_this_motherfucker(my_hunter_t *ht)
{
    sfRenderWindow_destroy(ht->window);
    sfMusic_destroy(ht->music);
    return (0);
}

int destroyed(my_hunter_t *ht, obj_t object[6])
{
    for (int i = 0; i < 6; i += 1) {
        sfTexture_destroy(object[i].texture);
        sfSprite_destroy(object[i].sprite);
    }
    sfRenderWindow_destroy(ht->window);
    sfMusic_destroy(ht->music);
    return (0);
}

int runner(my_hunter_t *ht)
{
    create(ht);
    create_obstacle(ht);
    sfEvent event;
    obj_t object[6];
    ht->chara.boolean = 0;
    menu(ht);
    game_objj(ht, object);
    sfMusic_play(ht->music);
    loop_open(ht, object, event);
    destroyed(ht, object);
}

int main(int ac, char **av)
{
    my_hunter_t ht;

    if (ac == 2 && (av[1][0] == 'h' || av[1][1] == 'h')) {
        documentation();
        return (0);
    } else {
        my_count_obstacl(av, &ht.game_obj);
        runner(&ht);
    }
}