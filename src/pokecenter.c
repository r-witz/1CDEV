#include <stdio.h>
#include <unistd.h>

#include "../include/player.h"

void ask_where_to_go();

void pokecenter(Player *ptrPlayer) {
    int choice;
    write(1, "+----------------------------+\n" , 32);
    write(1, "|   What do you want to do?  |\n", 32);
    write(1, "|    1. Heal Supemons        |\n", 32);
    write(1, "|    2. Leave the pokecenter |\n", 32);
    write(1, "+----------------------------+\n" , 32);
    write(1, "1 or 2 : ", 10);
    scanf("%d", &choice);
    printf("You chose %d\n", choice);
    if (choice == 1) {
        for (int i=0; i<6; i++) {
            if (ptrPlayer->supemons[i] != 0) {
                ptrPlayer->supemons[i]->hp = ptrPlayer->supemons[i]->max_hp;
            }
        }
        printf("You healed your supemons\n");
        for (int i=0; i<6; i++) {
            if (ptrPlayer->supemons[i] != 0) {
                printf("%d HP\n", ptrPlayer->supemons[i]->hp);
            }
        }
        ask_where_to_go();
    }
    else if (choice == 2) {
        ask_where_to_go();
    }
    else {
        printf("Invalid choice\n");
    }
}