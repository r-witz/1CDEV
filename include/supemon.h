#pragma once

typedef struct {
    char *name;
    short damage;
    short attack_bonus;
    short defense_bonus;
    short evasion_bonus;
} Move;

typedef struct {
    char *name;
    short level;
    int experience;
    int experience_max;
    short hp;
    short max_hp;
    short attack;
    short base_attack;
    short defense;
    short base_defense;
    short evasion;
    short base_evasion;
    short accuracy;
    short base_accuracy;
    short speed;
    Move *moves[2];
} Supemon;

Supemon *getSupemonByID(int id);
void freeSupemon(Supemon *ptrSupemon);
