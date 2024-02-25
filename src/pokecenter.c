#include <stdio.h>
#include <unistd.h>

#include "../include/player.h"

void ask_where_to_go();

void pokecenter() {
    Player player;
    int choice;
    write(1, "+----------------------------+\n" , 32);
    write(1, "|What do you want to do?     |\n", 32);
    write(1, "|    1. Heal Supemons        |\n", 32);
    write(1, "|    2. Leave the pokecenter |\n", 32);
    write(1, "+----------------------------+\n" , 32);
    write(1, "1 or 2 : ", 10);
    scanf("%d", &choice);
    printf("You chose %d\n", choice);
    if (choice == 1) {
        (&player)->supemons[0]->hp = (&player)->supemons[0]->max_hp;
        (&player)->supemons[1]->hp = (&player)->supemons[1]->max_hp;
        (&player)->supemons[2]->hp = (&player)->supemons[2]->max_hp;
        (&player)->supemons[3]->hp = (&player)->supemons[3]->max_hp;
        (&player)->supemons[4]->hp = (&player)->supemons[4]->max_hp;
        (&player)->supemons[5]->hp = (&player)->supemons[5]->max_hp;
        printf("You healed your supemons\n");
        printf("Supémons team hp : %d %d %d %d %d %d\n", (&player)->supemons[0]->hp, (&player)->supemons[1]->hp, (&player)->supemons[2]->hp, (&player)->supemons[3]->hp, (&player)->supemons[4]->hp, (&player)->supemons[5]->hp);
        ask_where_to_go();
    }
    else if (choice == 2) {
        ask_where_to_go();
    }
    else {
        printf("Invalid choice\n");
    }
}