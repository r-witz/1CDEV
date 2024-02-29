#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../include/player.h"

void ask_where_to_go();
Supemon *getSupemonByID(int id);

void displaySupemonStats(Player *ptrPlayer, Supemon *enemy);

void fight(Player *ptrPlayer) {
    int choiceAttack, choice4; 
    Supemon *enemy = NULL;

    do {
        if (enemy == NULL) {
            srand(time(NULL));
            int random = rand() % 3 + 1;
            enemy = getSupemonByID(random);
            displaySupemonStats(ptrPlayer, enemy);
        }

        write(1, "+----------------------------+\n" , 32);
        write(1, "|What will you do?           |\n", 32);
        write(1, "|    1. Move                 |\n", 32);
        write(1, "|    2. Change Supemon       |\n", 32);
        write(1, "|    3. Use item             |\n", 32);
        write(1, "|    4. Capture              |\n", 32);
        write(1, "|    5. Run away             |\n", 32);
        write(1, "+----------------------------+\n" , 32);
        write(1, "1, 2, 3, 4 or 5: ", 18);
        scanf("%d", &choice4);

        if (choice4 == 1) {
            write(1, "\n1 - Scratch\n", 14);
            write(1, "2 - Grawl\n", 11);
            write(1, "3 - Cancel\n", 12);  
            write(1, "1, 2 or 3 : ", 13);

            scanf("%d", &choiceAttack);

            if (choiceAttack == 1) {
                write(1, "You used Scratch\n", 18);
                enemy->hp -= 3;
                ptrPlayer->supemons[0]->hp -= enemy->attack;
                displaySupemonStats(ptrPlayer, enemy);
            } else if (choiceAttack == 2) {
                write(1, "You used Grawl\n", 16);
                ptrPlayer->supemons[0]->attack += 1;
                displaySupemonStats(ptrPlayer, enemy);
            } else if (choiceAttack == 3) {
                write(1, "You canceled\n", 14);
            } else {
                write(1, "Invalid choice\n", 16);
            }
        } else if (choice4 == 2) {
            write(1, "You changed Supemon\n", 21);
        } else if (choice4 == 3) {
            write(1, "You used item\n", 14);
        } else if (choice4 == 4) {
            write(1, "You captured\n", 14);
        } else if (choice4 == 5) {
            write(1, "You ran away\n", 14);
        } else {
            write(1, "Invalid choice\n", 16);
        }
    } while (choice4 != 5 || enemy->hp <= 0 || ptrPlayer->supemons[0]->hp <= 0);
}

void displaySupemonStats(Player *ptrPlayer, Supemon *enemy) {
    char enemyEva[100], enemyAcc[100], enemyDef[100], enemyHP[100], enemyMaxHP[100], enemyLevel[100], enemyAtk[100];
    char hp[100], max_hp[100], level[100], atk[100], def[100], acc[100], eva[100];

    write(1, "\nWILD SUPEMON (", 15);
    write(1, enemy->name, strlen(enemy->name));
    write(1, ")\n-----------------------\n", 26);
    write(1, "HP: ", 4);
    sprintf(enemyHP, "%d", enemy->hp);
    write(1, enemyHP, strlen(enemyHP));
    write(1, "/", 1);
    sprintf(enemyMaxHP, "%d", enemy->max_hp);
    write(1, enemyMaxHP, strlen(enemyMaxHP));
    sprintf(enemyLevel, "%d", enemy->level);
    write(1, "       Lvl: ", 12);
    write(1, enemyLevel, strlen(enemyLevel));
    write(1, "\nAtk: ", 6);
    sprintf(enemyAtk, "%d", enemy->attack);
    write(1, enemyAtk, strlen(enemyAtk));
    write(1, "          Def: ", 15);
    sprintf(enemyDef, "%d", enemy->defense);
    write(1, enemyDef, strlen(enemyDef));
    write(1, "\nAcc: ", 6);
    sprintf(enemyAcc, "%d", enemy->accuracy);
    write(1, enemyAcc, strlen(enemyAcc));
    write(1, "          Eva: ", 15);
    sprintf(enemyEva, "%d", enemy->evasion);
    write(1, enemyEva, strlen(enemyEva));
    write(1, "\n-----------------------\n", 25);

    write(1, ptrPlayer->supemons[0]->name, strlen(ptrPlayer->supemons[0]->name));
    write(1, " (", 2);
    write(1, ptrPlayer->name, strlen(ptrPlayer->name));
    write(1, ")\n", 2);
    write(1, "HP: ", 4);
    sprintf(hp, "%d", ptrPlayer->supemons[0]->hp);
    write(1, hp, strlen(hp));
    write(1, "/", 1);
    sprintf(max_hp, "%d", ptrPlayer->supemons[0]->max_hp);
    write(1, max_hp, strlen(max_hp));
    sprintf(level, "%d", ptrPlayer->supemons[0]->level);
    write(1, "       Lvl: ", 12);
    write(1, level, strlen(level));
    write(1, "\nAtk: ", 6);
    sprintf(atk, "%d", ptrPlayer->supemons[0]->attack);
    write(1, atk, strlen(atk));
    write(1, "          Def: ", 15);
    sprintf(def, "%d", ptrPlayer->supemons[0]->defense);
    write(1, def, strlen(def));
    write(1, "\nAcc: ", 6);
    sprintf(acc, "%d", ptrPlayer->supemons[0]->accuracy);
    write(1, acc, strlen(acc));
    write(1, "          Eva: ", 15);
    sprintf(eva, "%d", ptrPlayer->supemons[0]->evasion);
    write(1, eva, strlen(eva));
    write(1, "\n-----------------------\n\n", 26);


    if (ptrPlayer->supemons[0]->hp <= 0) {
        write(1, "\nYour Supemon fainted\n", 22);
        ask_where_to_go();
    }
    else if (enemy->hp <= 0) {
        write(1, "\nYou defeated the enemy\n", 24);
        ask_where_to_go();

    }
}
