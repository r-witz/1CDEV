#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../include/supemon.h"

void ask_where_to_go();
Supemon *getSupemonByID(int id);

void fight() {
    getSupemonByID(1), getSupemonByID(2), getSupemonByID(3);
    char enemyEva[1], enemyAcc[1], enemyDef[1], enemyHP[1], enemyMaxHP[1], enemyLevel[1], enemyAtk[1];

    srand(time(NULL));
    int random = rand() % 3 + 1;
    Supemon *enemy = getSupemonByID(random);
    write(1, "WILD SUPEMON (", 14);
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
    // can't work on that right now because the supémon stats are not initialized
    write(1, "SUPMANDER (Benjamin) \n", 22);
    write(1, "HP: 10/10       ", 17);
    write(1, "Lvl: 1\n", 7);
    write(1, "Atk: 1          ", 17);
    write(1, "Def: 1\n", 8);
    write(1, "Acc: 2          ", 17);
    write(1, "Eva: 1\n", 8);
    write(1, "-----------------------\n\n", 25);
    write(1, "+----------------------------+\n" , 32);
    write(1, "|What will you do?           |\n", 32);
    write(1, "|    1. Move                 |\n", 32);
    write(1, "|    2. Change Supemon       |\n", 32);
    write(1, "|    3. Use item             |\n", 32);
    write(1, "|    4. Capture              |\n", 32);
    write(1, "|    5. Run away             |\n", 32);
    write(1, "+----------------------------+\n" , 32);
    write(1, "1, 2, 3, 4 or 5: ", 18);
    int choice3;
    scanf("%d", &choice3);
    if (choice3 == 1) {
        write(1, "\n1 - Scratch\n", 14);
        write(1, "2 - Grawl\n", 11);
        write(1, "3 - Cancel\n", 12);  
        write(1, "1, 2 or 3 : ", 13);
        int choiceAttack;
        scanf("%d", &choiceAttack);        
        printf("You used %d\n", choiceAttack);
    } else if (choice3 == 2) {
        write(1, "You changed Supemon\n", 21);
    } else if (choice3 == 3) {
        write(1, "You used an item\n", 17);
    } else if (choice3 == 4) {
        write(1, "You tried to capture the Supemon\n", 33);
    } else if (choice3 == 5) {
        write(1, "You ran away\n", 14);
        ask_where_to_go();
    } else {
        write(1, "Invalid choice\n", 16);
    }
}