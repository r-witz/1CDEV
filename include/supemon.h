#include <stdio.h>

typedef struct {
    char *name;
    int level;
    int experience;
    int hp;
    int max_hp;
    int attack;
    int base_attack;
    int defense;
    int base_defense;
    int evasion;
    int base_evasion;
    int accuracy;
    int base_accuracy;
    int speed;
    char *moves[4];
} Supemon;