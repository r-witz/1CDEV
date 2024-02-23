#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "../include/player.h"
void empty_buffer();
void ask_where_to_go();
void shop();

void buy() {
    char choice4[2];
    char buffer[100];

    write(1,"+---------------------------------------+\n", 42);
    write(1,"|What would you want to buy ?           |\n", 42);
    write(1,"|    1. Potion (+5 HP) -> 100 SC        |\n", 42);
    write(1,"|    2. Super potion (+10 HP) -> 300 SC |\n", 42);
    write(1,"|    3. Rare candy (+1 LVL) -> 700 SC   |\n", 42);
    write(1,"|    4. Leave the shop                  |\n", 42);
    write(1,"+---------------------------------------+\n", 42);
    write(1,"1, 2 or 3 : ", 12);
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    strncpy(choice4, buffer, sizeof(choice4));

    if (strcmp(choice4, "1") == 0) {
        printf("TEST");
    } else if (strcmp(choice4, "2") == 0) {
        printf("TEST");
    } else if (strcmp(choice4, "3") == 0) {
        printf("TEST");
    } else if (strcmp(choice4, "4") == 0) {
        write(1, "GOODBYE\n", 8);
        ask_where_to_go();
    } else {
        write(1, "INCORRECT\n", 10);
        shop();
    }
    empty_buffer();
}