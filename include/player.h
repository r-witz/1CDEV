#pragma once 

#include "supemon.h"

typedef struct {
    Supemon *supemon;
    int money;
    int max_money;
    int pokeballs;
    int max_pokeballs;
    int potions;
    int max_potions;
    int super_potions;
    int max_super_potions;
    int rare_candy;
    int max_rare_candy;
    int supemon_count;
    Supemon *supemons[6];
} Player;


Player player = {
    .money = 500,
    .max_money = 999999,
    .pokeballs = 5,
    .max_pokeballs = 999,
    .potions = 3,
    .max_potions = 999,
    .super_potions = 0,
    .max_super_potions = 999,
    .rare_candy = 0,
    .max_rare_candy = 999,
    .supemon_count = 0,
    .supemons = {NULL, NULL , NULL, NULL, NULL, NULL},
};