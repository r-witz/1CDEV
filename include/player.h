#pragma once 

#include "supemon.h"

typedef struct {
    char *name;
    int money;
    short potions;
    short super_potions;
    short rare_candy;
    short items_used;
    Supemon *supemons[6];
} Player;

void freePlayer(Player *player);
Player *createPlayer();
void savePlayer(const char *filename, Player *player);
Player *loadPlayer(const char *filename);
