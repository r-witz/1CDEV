#include <stdio.h>
#include <unistd.h>

#include "../include/supemon.h"

void ask_where_to_go();

void fight() {
    write(1, "You are fighting with a wild Supemon\n\n", 38);
    write(1, "SUPMANDER (enemy) \n", 20);
    write(1, "-----------------------\n", 25);
    write(1, "HP: 10/10       ", 17);
    write(1, "Lvl: 1\n", 7);
    write(1, "Atk: 1          ", 17);
    write(1, "Def: 1\n", 8);
    write(1, "Acc: 2          ", 17);
    write(1, "Eva: 1\n", 8);
    write(1, "-----------------------\n", 25);
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