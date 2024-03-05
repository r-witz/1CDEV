#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/cJSON.h"
#include "../include/player.h"

void freePlayer(Player *player) {
    if (!player) {
        return;
    }

    free(player->name);

    for (int i = 0; i < 6; i++) {
        if (player->supemons[i]) {
            freeSupemon(player->supemons[i]);
        }
    }

    free(player);
}

Player *createPlayer() {
    Player *player = malloc(sizeof(Player));
    if (!player) {
        return NULL;
    }

    player->money = 0;
    player->potions = 0;
    player->super_potions = 0;
    player->rare_candy = 0;
    player->selected_supemon = 0;
    for (int i=0; i<6; i++) {
        player->supemons[i] = NULL;
    }

    return player;
}

void savePlayer(const char *filename, Player *player) {
    cJSON *root = cJSON_CreateObject();
    if (!root) {
        fprintf(stderr, "Error creating JSON object\n");
        return;
    }

    cJSON_AddStringToObject(root, "name", player->name);
    cJSON_AddNumberToObject(root, "money", player->money);
    cJSON_AddNumberToObject(root, "potions", player->potions);
    cJSON_AddNumberToObject(root, "super_potions", player->super_potions);
    cJSON_AddNumberToObject(root, "rare_candy", player->rare_candy);

    cJSON *supemonsArray = cJSON_CreateArray();
    if (!supemonsArray) {
        fprintf(stderr, "Error creating Supemons array\n");
        cJSON_Delete(root);
        return;
    }

    for (int i = 0; i < 6; i++) {
        Supemon *supemon = player->supemons[i];
        if (supemon) {
            cJSON *supemonObj = cJSON_CreateObject();
            if (!supemonObj) {
                fprintf(stderr, "Error creating Supemon object\n");
                cJSON_Delete(root);
                cJSON_Delete(supemonsArray);
                return;
            }
            cJSON_AddStringToObject(supemonObj, "name", supemon->name);
            cJSON_AddNumberToObject(supemonObj, "level", supemon->level);
            cJSON_AddNumberToObject(supemonObj, "experience", supemon->experience);
	    cJSON_AddNumberToObject(supemonObj, "experience_max", supemon->experience_max);
            cJSON_AddNumberToObject(supemonObj, "hp", supemon->hp);
            cJSON_AddNumberToObject(supemonObj, "max_hp", supemon->max_hp);
            cJSON_AddNumberToObject(supemonObj, "attack", supemon->attack);
            cJSON_AddNumberToObject(supemonObj, "base_attack", supemon->base_attack);
            cJSON_AddNumberToObject(supemonObj, "defense", supemon->defense);
            cJSON_AddNumberToObject(supemonObj, "base_defense", supemon->base_defense);
            cJSON_AddNumberToObject(supemonObj, "evasion", supemon->evasion);
            cJSON_AddNumberToObject(supemonObj, "base_evasion", supemon->base_evasion);
            cJSON_AddNumberToObject(supemonObj, "accuracy", supemon->accuracy);
            cJSON_AddNumberToObject(supemonObj, "base_accuracy", supemon->base_accuracy);
            cJSON_AddNumberToObject(supemonObj, "speed", supemon->speed);

            cJSON_AddItemToArray(supemonsArray, supemonObj);
        }
    }

    cJSON_AddItemToObject(root, "supemons", supemonsArray);

    char *jsonStr = cJSON_Print(root);
    if (!jsonStr) {
        fprintf(stderr, "Error generating JSON string\n");
        cJSON_Delete(root);
        return;
    }

    FILE *file = fopen(filename, "w");
    if (!file) {
        fprintf(stderr, "Error opening file for writing\n");
        cJSON_Delete(root);
        free(jsonStr);
        return;
    }

    fprintf(file, "%s", jsonStr);

    fclose(file);
    cJSON_Delete(root);
    free(jsonStr);
}

Player *loadPlayer(const char *filename) {
    
    FILE *file = fopen(filename, "r");
    if (!file) {
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *jsonBuffer = malloc(fileSize + 1);
    if (!jsonBuffer) {
        perror("Memory allocation failed");
        fclose(file);
        return NULL;
    }
    fread(jsonBuffer, 1, fileSize, file);
    fclose(file);
    jsonBuffer[fileSize] = '\0';

    cJSON *root = cJSON_Parse(jsonBuffer);
    free(jsonBuffer);

    if (!root) {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            fprintf(stderr, "Error parsing JSON: %s\n", error_ptr);
        }
        return NULL;
    }

    Player *player = malloc(sizeof(Player));
    if (!player) {
        perror("Memory allocation failed");
        cJSON_Delete(root);
        return NULL;
    }

    cJSON *nameObj = cJSON_GetObjectItemCaseSensitive(root, "name");
    cJSON *moneyObj = cJSON_GetObjectItemCaseSensitive(root, "money");
    cJSON *potionsObj = cJSON_GetObjectItemCaseSensitive(root, "potions");
    cJSON *superPotionsObj = cJSON_GetObjectItemCaseSensitive(root, "super_potions");
    cJSON *rareCandyObj = cJSON_GetObjectItemCaseSensitive(root, "rare_candy");
    cJSON *supemonsArray = cJSON_GetObjectItemCaseSensitive(root, "supemons");

    player->name = strdup(nameObj->valuestring);
    player->money = moneyObj->valueint;
    player->potions = potionsObj->valueint;
    player->super_potions = superPotionsObj->valueint;
    player->rare_candy = rareCandyObj->valueint;

    cJSON *supemonObj = NULL;
    cJSON_ArrayForEach(supemonObj, supemonsArray) {
        Supemon *supemon = malloc(sizeof(Supemon));
        if (!supemon) {
            perror("Memory allocation failed");
            cJSON_Delete(root);
            freePlayer(player);
            return NULL;
        }

        supemon->name = strdup(cJSON_GetObjectItemCaseSensitive(supemonObj, "name")->valuestring);
        supemon->level = cJSON_GetObjectItemCaseSensitive(supemonObj, "level")->valueint;
        supemon->experience = cJSON_GetObjectItemCaseSensitive(supemonObj, "experience")->valueint;
	supemon->experience_max = cJSON_GetObjectItemCaseSensitive(supemonObj, "experience_max")->valueint;
        supemon->hp = cJSON_GetObjectItemCaseSensitive(supemonObj, "hp")->valueint;
        supemon->max_hp = supemon->hp;
        supemon->attack = cJSON_GetObjectItemCaseSensitive(supemonObj, "attack")->valueint;
        supemon->base_attack = supemon->attack;
        supemon->defense = cJSON_GetObjectItemCaseSensitive(supemonObj, "defense")->valueint;
        supemon->base_defense = supemon->defense;
        supemon->evasion = cJSON_GetObjectItemCaseSensitive(supemonObj, "evasion")->valueint;
        supemon->base_evasion = supemon->evasion;
        supemon->accuracy = cJSON_GetObjectItemCaseSensitive(supemonObj, "accuracy")->valueint;
        supemon->base_accuracy = supemon->accuracy;
        supemon->speed = cJSON_GetObjectItemCaseSensitive(supemonObj, "speed")->valueint;


        for (int i = 0; i < 6; i++) {
            if (player->supemons[i] == NULL) {
                player->supemons[i] = supemon;
                break;
            }
        }
    }

    cJSON_Delete(root);
    return player;
}
