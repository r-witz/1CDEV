#pragma once 

#include "supemon.h"

typedef struct {
    char *name;
    int money;
    short potions;
    short super_potions;
    short rare_candy;
    Supemon *supemons[6];
} Player;

void freeSupemon(Supemon *ptrSupemon);
Player *createPlayer();
Player *loadPlayer(const char *filename);
void savePlayer(const char *filename, Player *player);
