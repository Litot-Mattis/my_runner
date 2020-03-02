/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** map.c
*/

#include "utilities.h"

char *open_file(char const *map)
{
    char *str;
    int file_d;

    file_d = open(map, O_RDONLY);
    if (file_d == -1) {
        write (2, "map not found!\n", 16);
        return (NULL);
    }
    str = malloc(sizeof(char) * 71 + 1);
    read(file_d, str, 71);
    str[71] = '\0';
    return (str);
}

int my_count_obstacl(char **av, obj_t *game_obj)
{
    int count = 0;
    int j = 0;
    char *str = open_file(av[1]);

    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == 'x')
            count += 1;
    }
    game_obj->map.size = 0;
    game_obj->map.size = count;
    game_obj->map.map_sprite = malloc(sizeof(map_sprite_t) * (count + 1));
    game_obj->map.map = malloc(sizeof(int) * (count + 1));
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == 'x') {
            game_obj->map.map[j] = i * 306 * 0.2;
            j += 1;
        }
    }
    return (count);
}