#pragma once 

#include "supemon.h"

void freeSupemon(Supemon *ptrSupemon);

typedef struct {
    char *name;
    int money;
    int potions;
    int super_potions;
    int rare_candy;
    Supemon *supemons[6];
} Player;

// Player player;
// player.money = 500;
// player.potions = 0;
// player.super_potions = 0;
// player.rare_candy = 0;
// player.supemons = {NULL, NULL, NULL, NULL, NULL, NULL};