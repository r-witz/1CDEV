#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../include/player.h"

void ask_where_to_go(Player *ptrPlayer);
Supemon *getSupemonByID(int id);
void empty_buffer();

void displaySupemonStats(Player *ptrPlayer, Supemon *enemy);

void fight(Player *ptrPlayer) {
    int choiceAttack, choice4; 
    Supemon *enemy = NULL;
    char buffer[100];

    do {
        if (enemy == NULL) {
            srand(time(NULL));
            int randomEnemy = rand() % 3 + 1;
            enemy = getSupemonByID(randomEnemy);
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
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &choice4);
        write(1, "\n", 1);

        if (choice4 == 1) {
            write(1, "\n1 - Scratch\n", 14);
            write(1, "2 - Grawl\n", 11);
            write(1, "3 - Cancel\n", 12);  
            write(1, "1, 2 or 3 : ", 13);

            scanf("%d", &choiceAttack);

            if (choiceAttack == 1) {
                double dodge = ptrPlayer->supemons[0]->accuracy + enemy->evasion + 0.1;
                srand(time(NULL));
                int random = rand() % 100 / 100.0;
                if (random > dodge) {
                    write(1, "You missed\n", 11);
                }
                else {
                enemy->hp -= 3 * ptrPlayer->supemons[0]->attack - enemy->defense;
                ptrPlayer->supemons[0]->hp -= enemy->attack - ptrPlayer->supemons[0]->defense;
                write(1, "You used Scratch\n", 18);
                displaySupemonStats(ptrPlayer, enemy);
                }
            } else if (choiceAttack == 2) {
                ptrPlayer->supemons[0]->attack += 1;
                write(1, "You used Grawl\n", 16);
                displaySupemonStats(ptrPlayer, enemy);
            } else if (choiceAttack == 3) {
                write(1, "You canceled\n", 14);
            } else {
                write(1, "Invalid choice\n", 16);
            }
        } else if (choice4 == 2) {
            write(1, "Which supemon do you want to summon ?\n", 38);
            for (int i = 0; i < 6; i++) {
                if (ptrPlayer->supemons[i] != NULL) {
                    write(1, "Supemon \n", 9);
                    char* supemonName = ptrPlayer->supemons[i]->name;
                    write(1, supemonName, strlen(supemonName));
                    write(1, " (", 2);
                    int supemonHp = ptrPlayer->supemons[i]->hp;
                    printf("%d", supemonHp);
                    write(1, "/", 1);
                    int supemonMaxHp = ptrPlayer->supemons[i]->max_hp;
                    printf("%d", supemonMaxHp);
                    write(1, ")\n", 2);
                }
            }
            char choice4[100];
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = '\0';
            strncpy(choice4, buffer, sizeof(choice4) - 1);

            if (1 <= choiceAttack && choiceAttack <= 6) {
                if (ptrPlayer->supemons[choiceAttack - 1] != NULL) {
                    ptrPlayer->supemons[0] = ptrPlayer->supemons[choiceAttack - 1];
                    char* supemonName = ptrPlayer->supemons[0]->name;
                    write(1, supemonName, strlen(supemonName));
                    write(1, " is summoned\n", 13);
                }
                else if (ptrPlayer->supemons[choiceAttack - 1] == NULL) {
                    write(1, "No supemon here\n", 16);
                }
                else {
                    write(1, "invalid choice\n", 15);
            }
        }
        } else if (choice4 == 3) {
            int maximumItems;
            while (maximumItems != 4) {
                write(1, "You have:\n", 10);
                printf("%d", ptrPlayer->potions);
                write(1, " potions\n", 9);
                printf("%d", ptrPlayer->super_potions);
                write(1, " super potions\n", 15);
                printf("%d", ptrPlayer->rare_candy);
                write(1, " rare candies\n", 14);
                write(1, "What item do you want to use ?\n", 31);
                write(1, "1. Potion\n", 10);
                write(1, "2. Super potion\n", 16);
                write(1, "3. Rare candy\n", 14);
                write(1, "4. Cancel\n", 10);
                write(1, "1, 2, 3 or 4: ", 14);
                int choiceItem;
                fgets(buffer, sizeof(buffer), stdin);
                sscanf(buffer, "%d", &choiceItem);
                write(1, "\n", 1);
                if (choiceItem == 1) {
                    if (ptrPlayer->potions > 0) {
                        ptrPlayer->potions -= 1;
                        ptrPlayer->supemons[0]->hp += 5;
                        if (ptrPlayer->supemons[0]->hp > ptrPlayer->supemons[0]->max_hp) {
                            ptrPlayer->supemons[0]->hp = ptrPlayer->supemons[0]->max_hp;
                        }
                        write(1, "You used a potion\n", 18);
                        maximumItems += 1;
                    } else {
                        write(1, "You don't have any potion\n", 26);
                    }
                } else if (choiceItem == 2) {
                    if (ptrPlayer->super_potions > 0) {
                        ptrPlayer->super_potions -= 1;
                        ptrPlayer->supemons[0]->hp += 10;
                        if (ptrPlayer->supemons[0]->hp > ptrPlayer->supemons[0]->max_hp) {
                            ptrPlayer->supemons[0]->hp = ptrPlayer->supemons[0]->max_hp;
                        }
                        write(1, "You used a super potion\n", 24);
                        maximumItems += 1;
                    } else {
                        write(1, "You don't have any super potion\n", 32);
                    }
                } else if (choiceItem == 3) {
                    if (ptrPlayer->rare_candy > 0) {
                        ptrPlayer->rare_candy -= 1;
                        ptrPlayer->supemons[0]->level += 1;
                        write(1, "You used a rare candy\n", 22);
                        maximumItems += 1;
                    } else {
                        write(1, "You don't have any rare candy\n", 30);
                    }
                } else if (choiceItem == 4) {
                    write(1, "You canceled\n", 14);
                } else {
                    write(1, "Invalid choice\n", 16);
                }
            }

        } else if (choice4 == 4) {
            printf("Enemy HP = %d\n", enemy->hp);
            printf("Enemy Max HP = %d\n", enemy->max_hp);
            double random = (float)(enemy->max_hp - enemy->hp) / enemy->max_hp - 0.5;
            srand(time(NULL));
            float randomValue = rand() % 100 / 100.0;
            printf("Random = %f\n", random);
            printf("RandomValue = %f\n", randomValue);
            if (random > randomValue) {
                write(1, "You captured the enemy\n", 23);
                if (ptrPlayer->supemons[1] == NULL) {
                    ptrPlayer->supemons[1] = enemy;
                } else if (ptrPlayer->supemons[2] == NULL) {
                    ptrPlayer->supemons[2] = enemy;
                } else if (ptrPlayer->supemons[3] == NULL) {
                    ptrPlayer->supemons[3] = enemy;
                } else if (ptrPlayer->supemons[4] == NULL) {
                    ptrPlayer->supemons[4] = enemy;
                } else if (ptrPlayer->supemons[5] == NULL) {
                    ptrPlayer->supemons[5] = enemy;
                } else {
                    write(1, "Your team is full. Do you want to replace a supemon? (Y/N): ", 59);
                    char choice;
                    fgets(buffer, sizeof(buffer), stdin);
                    sscanf(buffer, "%c", &choice);
                    write(1, "\n", 1);
                    if (choice == 'Y' || choice == 'y') {
                        write(1, "Which supemon do you want to replace? (1-5): ", 45);
                        int replaceChoice;
                        fgets(buffer, sizeof(buffer), stdin);
                        sscanf(buffer, "%d", &replaceChoice);
                        write(1, "\n", 1);
                        if (1 <= replaceChoice && replaceChoice <= 5) {
                            ptrPlayer->supemons[replaceChoice] = enemy;
                        } else {
                            write(1, "Invalid choice\n", 15);
                        }
                    }
                    else if (choice == 'N' || choice == 'n') {
                        write(1, "You chose not to replace\n", 26);
                    }
                }
                ask_where_to_go(ptrPlayer);
            } else {
                write(1, "You failed to capture the enemy\n", 32);
            }
        } else if (choice4 == 5) {
            int random = rand() % (ptrPlayer->supemons[0]->evasion + enemy->evasion);
            if (random < ptrPlayer->supemons[0]->evasion) {
                write(1, "You ran away\n", 14);
                ask_where_to_go(ptrPlayer);
            } else {
                write(1, "You failed to run away\n", 23);
            }
        } else {
            write(1, "Invalid choice\n", 16);
        }
    } while (choice4 != 5 || enemy->hp <= 0 || ptrPlayer->supemons[0]->hp <= 0);
}

void displaySupemonStats(Player *ptrPlayer, Supemon *enemy) {
    char hp[100], max_hp[100], level[100], atk[100], def[100], acc[100], eva[100];
    int supemonLevel = ptrPlayer->supemons[0]->level;
    enemy->hp *= supemonLevel * 0.3;
    enemy->max_hp *= supemonLevel * 0.3;
    enemy->attack *= supemonLevel * 0.3;
    enemy->defense *= supemonLevel * 0.3;
    enemy->accuracy *= supemonLevel * 0.3;
    enemy->evasion *= supemonLevel * 0.3;

    char enemyEva[100], enemyAcc[100], enemyDef[100], enemyHP[100], enemyMaxHP[100], enemyAtk[100];
    

    write(1, "\nWILD SUPEMON (", 15);
    write(1, enemy->name, strlen(enemy->name));
    write(1, ")\n-----------------------\n", 26);
    write(1, "HP: ", 4);
    sprintf(enemyHP, "%d", enemy->hp);
    write(1, enemyHP, strlen(enemyHP));
    write(1, "/", 1);
    sprintf(enemyMaxHP, "%d", enemy->max_hp);
    write(1, enemyMaxHP, strlen(enemyMaxHP));
    sprintf(level, "%d", ptrPlayer->supemons[0]->level);
    write(1, "       Lvl: ", 12);
    write(1, level, strlen(level));
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
        ask_where_to_go(ptrPlayer);
    }
    else if (enemy->hp <= 0) {
        write(1, "\nYou defeated the enemy\n", 24);
        int moneyEarned = rand() % 401 + 100;
        ptrPlayer->money += moneyEarned;
        int xpEarned = rand() % ptrPlayer->supemons[0]->level * 401 + 100;
        ptrPlayer->supemons[0]->experience += xpEarned;
        write(1, "Your Supemon earned ", 20);
        sprintf(hp, "%d", xpEarned);
        write(1, hp, strlen(hp));
        write(1, " XP!\n", 5);
        write(1, "Your Supemon now has ", 21);
        sprintf(hp, "%d", ptrPlayer->supemons[0]->experience);
        write(1, hp, strlen(hp));
        write(1, " / ", 3);
        sprintf(max_hp, "%d", ptrPlayer->supemons[0]->experience_max);
        write(1, max_hp, strlen(max_hp));
        write(1, " XP!\n", 5);
        write(1, "You earned ", 11);
        sprintf(hp, "%d", moneyEarned);
        write(1, hp, strlen(hp));
        write(1, " Supecoins!\n", 12);
        write(1, "You now have ", 13);
        sprintf(hp, "%d", ptrPlayer->money);
        write(1, hp, strlen(hp));
        write(1, " Supecoins!\n", 12);
        ask_where_to_go(ptrPlayer);
    }
}
