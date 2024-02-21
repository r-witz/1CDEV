#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/cJSON.h"
#include "../include/supemon.h"

#define MAX_MOVES 2

Supemon *parseJSON(const char *supemonFilename, const char *moveFilename,
                   int id) {

  FILE *supemonFile = fopen(supemonFilename, "r");
  if (!supemonFile) {
    perror("Error opening Supemon file");
    return NULL;
  }

  fseek(supemonFile, 0, SEEK_END);
  long supemonFileSize = ftell(supemonFile);
  fseek(supemonFile, 0, SEEK_SET);
  char *supemonJsonBuffer = malloc(supemonFileSize + 1);
  if (!supemonJsonBuffer) {
    perror("Memory allocation failed");
    fclose(supemonFile);
    return NULL;
  }
  fread(supemonJsonBuffer, 1, supemonFileSize, supemonFile);
  fclose(supemonFile);
  supemonJsonBuffer[supemonFileSize] = '\0';

  cJSON *supemonRoot = cJSON_Parse(supemonJsonBuffer);
  if (!supemonRoot) {
    const char *error_ptr = cJSON_GetErrorPtr();
    if (error_ptr != NULL) {
      fprintf(stderr, "Error parsing Supemon JSON: %s\n", error_ptr);
    }
    free(supemonJsonBuffer);
    return NULL;
  }

  cJSON *supemonArray = supemonRoot;
  cJSON *supemonObj = NULL;
  cJSON_ArrayForEach(supemonObj, supemonArray) {
    cJSON *idObj = cJSON_GetObjectItemCaseSensitive(supemonObj, "id");
    if (!cJSON_IsNumber(idObj)) {
      fprintf(stderr, "Error getting Supemon ID\n");
      cJSON_Delete(supemonRoot);
      free(supemonJsonBuffer);
      return NULL;
    }
    int supemonId = idObj->valueint;

    if (supemonId == id) {
      Supemon *supemon = malloc(sizeof(Supemon));
      if (!supemon) {
        perror("Memory allocation failed");
        cJSON_Delete(supemonRoot);
        free(supemonJsonBuffer);
        return NULL;
      }

      supemon->name = strdup(
          cJSON_GetObjectItemCaseSensitive(supemonObj, "name")->valuestring);
      supemon->level = 1;
      supemon->experience = 0;
      supemon->hp =
          cJSON_GetObjectItemCaseSensitive(supemonObj, "hp")->valueint;
      supemon->max_hp = supemon->hp;
      supemon->attack =
          cJSON_GetObjectItemCaseSensitive(supemonObj, "attack")->valueint;
      supemon->base_attack = supemon->attack;
      supemon->defense =
          cJSON_GetObjectItemCaseSensitive(supemonObj, "defense")->valueint;
      supemon->base_defense = supemon->defense;
      supemon->evasion =
          cJSON_GetObjectItemCaseSensitive(supemonObj, "evasion")->valueint;
      supemon->base_evasion = supemon->evasion;
      supemon->accuracy =
          cJSON_GetObjectItemCaseSensitive(supemonObj, "accuracy")->valueint;
      supemon->base_accuracy = supemon->accuracy;
      supemon->speed =
          cJSON_GetObjectItemCaseSensitive(supemonObj, "speed")->valueint;

      cJSON *movesArray = cJSON_GetObjectItemCaseSensitive(supemonObj, "moves");
      cJSON *movesObj = NULL;
      short i = 0;
      short moves[2];
      cJSON_ArrayForEach(movesObj, movesArray) {
        moves[i] = movesObj->valueint;
        i++;
      }

      FILE *moveFile = fopen(moveFilename, "r");
      if (!moveFile) {
        perror("Error opening Move file");
        cJSON_Delete(supemonRoot);
        free(supemonJsonBuffer);
        free(supemon);
        return NULL;
      }

      fseek(moveFile, 0, SEEK_END);
      long moveFileSize = ftell(moveFile);
      fseek(moveFile, 0, SEEK_SET);
      char *moveJsonBuffer = malloc(moveFileSize + 1);
      if (!moveJsonBuffer) {
        perror("Memory allocation failed");
        fclose(moveFile);
        cJSON_Delete(supemonRoot);
        free(supemonJsonBuffer);
        free(supemon);
        return NULL;
      }
      fread(moveJsonBuffer, 1, moveFileSize, moveFile);
      fclose(moveFile);
      moveJsonBuffer[moveFileSize] = '\0';

      cJSON *moveRoot = cJSON_Parse(moveJsonBuffer);
      if (!moveRoot) {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
          fprintf(stderr, "Error parsing Move JSON: %s\n", error_ptr);
        }
        free(moveJsonBuffer);
        cJSON_Delete(supemonRoot);
        free(supemonJsonBuffer);
        free(supemon);
        return NULL;
      }

      cJSON *moveArray = moveRoot;
      cJSON *moveObj = NULL;
      cJSON_ArrayForEach(moveObj, moveArray) {
        cJSON *moveIdObj = cJSON_GetObjectItemCaseSensitive(moveObj, "id");
        if (!cJSON_IsNumber(moveIdObj)) {
          fprintf(stderr, "Error getting Move ID\n");
          cJSON_Delete(moveRoot);
          free(moveJsonBuffer);
          cJSON_Delete(supemonRoot);
          free(supemonJsonBuffer);
          free(supemon);
          return NULL;
        }
        int moveId = moveIdObj->valueint;

        for (int i = 0; i < 2; i++) {
          if (moves[i] == moveId) {
            cJSON *nameObj = cJSON_GetObjectItemCaseSensitive(moveObj, "name");
            cJSON *damageObj =
                cJSON_GetObjectItemCaseSensitive(moveObj, "damage");
            cJSON *attackBonusObj =
                cJSON_GetObjectItemCaseSensitive(moveObj, "attack_bonus");
            cJSON *defenseBonusObj =
                cJSON_GetObjectItemCaseSensitive(moveObj, "defense_bonus");
            cJSON *evasionBonusObj =
                cJSON_GetObjectItemCaseSensitive(moveObj, "evasion_bonus");

            Move *move = malloc(sizeof(Move));
            if (!move) {
              perror("Memory allocation failed");
              cJSON_Delete(moveRoot);
              free(moveJsonBuffer);
              cJSON_Delete(supemonRoot);
              free(supemonJsonBuffer);
              free(supemon);
              return NULL;
            }

            move->name = strdup(nameObj->valuestring);
            move->damage = cJSON_IsNumber(damageObj) ? damageObj->valueint : 0;
            move->attack_bonus =
                cJSON_IsNumber(attackBonusObj) ? attackBonusObj->valueint : 0;
            move->defense_bonus =
                cJSON_IsNumber(defenseBonusObj) ? defenseBonusObj->valueint : 0;
            move->evasion_bonus =
                cJSON_IsNumber(evasionBonusObj) ? evasionBonusObj->valueint : 0;

            supemon->moves[i] = move;
          }
        }
      }

      cJSON_Delete(moveRoot);
      free(moveJsonBuffer);
      cJSON_Delete(supemonRoot);
      free(supemonJsonBuffer);
      return supemon;
    }
  }

  fprintf(stderr, "Supemon with ID %d not found in JSON\n", id);
  cJSON_Delete(supemonRoot);
  free(supemonJsonBuffer);
  return NULL;
}

void freeSupemon(Supemon *ptrSupemon) {
    free(ptrSupemon->name);
    for (int i = 0; i < MAX_MOVES; ++i) {
      if (ptrSupemon->moves[i]) {
        free(ptrSupemon->moves[i]->name);
        free(ptrSupemon->moves[i]);
      }
    }
    free(ptrSupemon);
}

int main() {
  const char *supemonFilename = "backup/supemon.json";
  const char *moveFilename = "backup/move.json";
  int id = 1;
  Supemon *supemon = parseJSON(supemonFilename, moveFilename, id);
  if (supemon) {
    printf("Name: %s\n", supemon->name);
    printf("HP: %d\n", supemon->hp);
    printf("Attack: %d\n", supemon->attack);
    printf("Defense: %d\n", supemon->defense);
    printf("Evasion: %d\n", supemon->evasion);
    printf("Accuracy: %d\n", supemon->accuracy);
    printf("Speed: %d\n", supemon->speed);
    printf("Moves:\n");
    for (int i = 0; i < MAX_MOVES; ++i) {
      if (supemon->moves[i]) {
        Move *move = supemon->moves[i];
        printf("  Move %d:\n", i + 1);
        printf("    Name: %s\n", move->name);
        printf("    Damage: %d\n", move->damage);
        printf("    Attack Bonus: %d\n", move->attack_bonus);
        printf("    Defense Bonus: %d\n", move->defense_bonus);
        printf("    Evasion Bonus: %d\n", move->evasion_bonus);
      }
    }

    freeSupemon(supemon);
  }
  return 0;
}
