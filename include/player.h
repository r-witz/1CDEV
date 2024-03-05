#pragma once 

#include "supemon.h"

typedef struct {
    char *name;
    int money;
    int potions;
    int super_potions;
    int rare_candy;
    int selected_supemon;
    Supemon *supemons[6];
} Player;

void freeSupemon(Supemon *ptrSupemon);
Player *createPlayer();
Player *loadPlayer(const char *filename);
void savePlayer(const char *filename, Player *player);
