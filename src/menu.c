/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** menu.c
*/

#include "utilities.h"

void set(my_hunter_t *ht)
{
    ht->s_menu = sfSprite_create();
    ht->texture_menu = sfTexture_createFromFile("assets/menu.png", NULL);
    ht->s_play = sfSprite_create();
    ht->play_t = sfTexture_createFromFile("assets/play.png", NULL);
    ht->p_s = sfSprite_create();
    sfSprite_setTexture(ht->s_menu, ht->texture_menu, sfTrue);
    sfSprite_setTexture(ht->s_play, ht->play_t, sfTrue);
    sfSprite_setScale(ht->s_play, (sfVector2f) {0.6, 0.6});
    sfSprite_setScale(ht->s_menu, (sfVector2f) {0.57, 0.56});
    sfSprite_setPosition(ht->s_play, (sfVector2f) {420, 100});
}

int click(my_hunter_t *ht, int x, int y)
{
    if (x >= 435 && x <= 640 && y >= 190 && y <= 250){
        ht->quit = 0;
        return (0);
    }
    if (x >= 0 && x <= 0 && y >= 0 && y <= 0){
        ht->quit = 1;
        return (0);
    }
    return (1);
}

int event(my_hunter_t *ht)
{
    int returnn = 1;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(ht->window);

    while (sfRenderWindow_pollEvent(ht->window, &ht->event))
        if (ht->event.type == sfEvtClosed){
            ht->quit = 1;
            return (1);
        }
    if (sfMouse_isButtonPressed(sfMouseLeft))
        returnn = click(ht, mouse.x, mouse.y);
    return (returnn);
}

void destroy(my_hunter_t *ht)
{
    sfSprite_destroy(ht->s_menu);
    sfTexture_destroy(ht->texture_menu);
}

void menu(my_hunter_t *ht)
{
    int boucle = 1;
    set(ht);
    while (boucle) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            break;
        boucle = event(ht);
        sfRenderWindow_drawSprite(ht->window, ht->s_menu, NULL);
        sfRenderWindow_drawSprite(ht->window, ht->s_play, NULL);
        sfRenderWindow_drawSprite(ht->window, ht->p_s, NULL);
        sfRenderWindow_display(ht->window);
    }
    destroy(ht);
}