#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "../include/player.h"

void ask_where_to_go(Player *ptrPlayer);
void pokecenter(Player *ptrPlayer) {
    int choice;
    char buffer[100];
    do {
        write(1, "+----------------------------+\n" , 32);
        write(1, "|   What do you want to do?  |\n", 32);
        write(1, "|    1. Heal Supemons        |\n", 32);
        write(1, "|    2. Leave the pokecenter |\n", 32);
        write(1, "+----------------------------+\n" , 32);
        write(1, "1 or 2 : ", 10);
        
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &choice);
        write(1, "\n", 1);
        if (choice == 1) {
            for (int i=0; i<6; i++) {
                if (ptrPlayer->supemons[i] != 0) {
                    ptrPlayer->supemons[i]->hp = ptrPlayer->supemons[i]->max_hp;
                }
            }
            write(1, "Your Supemons have been healed!\n", 32);
            for (int i=0; i<6; i++) {
                if (ptrPlayer->supemons[i] != 0) {
                    char hp[100];
                    write(1, ptrPlayer->supemons[i]->name, strlen(ptrPlayer->supemons[i]->name));
                    write(1, " has ", 5);
                    sprintf(hp, "%d", ptrPlayer->supemons[i]->hp);
                    write(1, hp, strlen(hp));
                    write(1, " / ", 3);
                    sprintf(hp, "%d", ptrPlayer->supemons[i]->max_hp);
                    write(1, hp, strlen(hp));
                    write(1, " HP\n", 4);
                }
            }
            ask_where_to_go(ptrPlayer);
        }
        else if (choice == 2) {
            ask_where_to_go(ptrPlayer);
        }
        else {
            write(1, "Please enter a valid number.\n", 29);
        }
    } while (choice != 1 && choice != 2);
}