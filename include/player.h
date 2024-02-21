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